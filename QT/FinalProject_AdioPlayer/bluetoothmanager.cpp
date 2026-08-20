#include "bluetoothmanager.h"

#include <QDebug>
#include <QFileInfo>
#include <QFileInfoList>
#include <QTimer>
#include <QRegularExpression>
#include <QDateTime>

BluetoothManager::BluetoothManager(QObject *parent) : QObject(parent), m_discoveryAgent(nullptr),
      m_localDevice(nullptr), m_devices(), m_scanning(false), m_bluetoothPoweredOn(false),
      m_scanTimer(nullptr), m_scanProgress(0), m_scanElapsedSeconds(0), m_scanStartTime(),
      m_scanCompleted(false),m_connected(false),m_connectedDeviceName(), m_connectedAddress(),
      m_connectionStatus("Disconnected"),m_fileReceiver(nullptr), m_fileWatcher(nullptr),
      m_bluetoothReceiveDirectory(), m_receivingFile(false), m_receivedFilePath(),
      m_currentTransferFile(),m_currentTransferSize(0)
{
    m_localDevice =  new QBluetoothLocalDevice(this);
    m_discoveryAgent =  new QBluetoothDeviceDiscoveryAgent(this);
    m_scanTimer =  new QTimer(this);
    m_scanTimer->setInterval(1000);

    connect(m_scanTimer, &QTimer::timeout,this,&BluetoothManager::updateScanProgress);

    m_bluetoothPoweredOn = m_localDevice->hostMode() != QBluetoothLocalDevice::HostPoweredOff;

    connect( m_localDevice,&QBluetoothLocalDevice::hostModeStateChanged,this,
        &BluetoothManager::hostModeStateChanged );
 
    connect(m_discoveryAgent,&QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
        this, &BluetoothManager::deviceDiscovered);

    connect( m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
        this, &BluetoothManager::discoveryFinished
    );

    connect( m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled,
        this, &BluetoothManager::discoveryFinished
    );

    connect(m_discoveryAgent,&QBluetoothDeviceDiscoveryAgent::errorOccurred,
        this,&BluetoothManager::discoveryError
    );

    m_fileWatcher = new QFileSystemWatcher(this);

    connect(m_fileWatcher, &QFileSystemWatcher::directoryChanged,
        this,[this](const QString &directory){

            qDebug()<< "Bluetooth directory changed:"<< directory;
            QTimer::singleShot(700, this,[this, directory]()
                {
                    checkForReceivedAudioFile(directory);
                }
            );
        }
    );

    qDebug()<< "====================================";
    qDebug()<< "BluetoothManager initialized";
    qDebug()<< "Bluetooth powered on:" << m_bluetoothPoweredOn;
    qDebug()<< "====================================";
}

bool BluetoothManager::getscanning() const
{
    return m_scanning;
}

bool BluetoothManager::getbluetoothPoweredOn() const
{
    return m_bluetoothPoweredOn;
}

QVariantList BluetoothManager::getdevices() const
{
    return m_devices;
}

int BluetoothManager::getScanProgress() const
{
    return m_scanProgress;
}

int BluetoothManager::getScanElapsedSeconds() const
{
    return m_scanElapsedSeconds;
}

QString BluetoothManager::getScanStartTime() const
{
    return m_scanStartTime;
}

bool BluetoothManager::getScanCompleted() const
{
    return m_scanCompleted;
}

bool BluetoothManager::getConnected() const
{
    return m_connected;
}

QString BluetoothManager::getConnectedDeviceName() const
{
    return m_connectedDeviceName;
}

QString BluetoothManager::getConnectionStatus() const
{
    return m_connectionStatus;
}

bool BluetoothManager::getReceivingFile() const
{
    return m_receivingFile;
}
 
QString BluetoothManager::getReceivedFilePath() const
{
    return m_receivedFilePath;
}

void BluetoothManager::setConnectionStatus(const QString &status)
{
    if (m_connectionStatus == status)
        return;

    m_connectionStatus = status;
    emit connectionStatusChanged();

    qDebug()<< "Bluetooth status:"<< m_connectionStatus;
}

void BluetoothManager::setReceivingFile(bool receiving)
{
    if (m_receivingFile == receiving)
        return;

    m_receivingFile = receiving;
    emit receivingFileChanged();

    qDebug()<< "Receiving file:" << m_receivingFile;
}

void BluetoothManager::startScan()
{
    qDebug()<< "====================================";
    qDebug()<< "Starting Bluetooth scan...";
    qDebug()<< "====================================";

    if (!m_bluetoothPoweredOn)
    {
        qWarning()<< "Bluetooth is powered off.";
        setConnectionStatus("Bluetooth is powered off");

        return;
    }

    if (m_scanning)
    {
        qDebug()<< "Bluetooth scan already running.";

        return;
    }

    m_devices.clear();
    emit devicesChanged();

    m_scanProgress = 0;
    emit scanProgressChanged();

    m_scanElapsedSeconds = 0;
    emit scanElapsedSecondsChanged();

    m_scanStartTime =QDateTime::currentDateTime().toString("hh:mm:ss");
    emit scanStartTimeChanged();

    m_scanCompleted = false;
    emit scanCompletedChanged();

    m_scanning = true;
    emit scanningChanged();

    m_scanTimer->start();
    m_discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::ClassicMethod
        |QBluetoothDeviceDiscoveryAgent::LowEnergyMethod );

    setConnectionStatus("Scanning for Bluetooth devices...");

    qDebug()<< "Bluetooth scan started.";
    qDebug()<< "Scan duration:"<< SCAN_DURATION_SECONDS<< "seconds";
}

void BluetoothManager::updateScanProgress()
{
    if (!m_scanning)
    {
        m_scanTimer->stop();
        return;
    }

    m_scanElapsedSeconds++;
    emit scanElapsedSecondsChanged();

    m_scanProgress =(m_scanElapsedSeconds * 100 ) / SCAN_DURATION_SECONDS;

    if (m_scanProgress > 100)
    {
        m_scanProgress = 100;
    }

    emit scanProgressChanged();
    qDebug()<< "Scan progress:" << m_scanProgress << "%";

    if (m_scanElapsedSeconds >= SCAN_DURATION_SECONDS )
    {
        m_scanProgress = 100;
        emit scanProgressChanged();

        m_scanCompleted = true;
        emit scanCompletedChanged();

        m_scanTimer->stop();
        qDebug()<< "Scan timer completed.";

        // Stop Bluetooth discovery
        if (m_discoveryAgent->isActive())
        {
            m_discoveryAgent->stop();
        }
        else
        {
            discoveryFinished();
        }
    }
}

void BluetoothManager::stopScan()
{
    if (!m_scanning)
        return;

    qDebug()<< "Stopping Bluetooth scan...";

    if (m_scanTimer)
    {
        m_scanTimer->stop();
    }

    if (m_discoveryAgent->isActive())
    {
        m_discoveryAgent->stop();
    }
    else
    {
        discoveryFinished();
    }
}

void BluetoothManager::deviceDiscovered( const QBluetoothDeviceInfo &device)
{
    qDebug() << "------------------------------------";
    qDebug() << "Bluetooth device discovered";
    qDebug() << "Name:" << device.name();
    qDebug() << "Address:" << device.address().toString();
    qDebug() << "RSSI:" << device.rssi();
    qDebug() << "------------------------------------";

    QString address = device.address().toString();

    for (const QVariant &item : m_devices)
    {
        QVariantMap existingDevice = item.toMap();

        if ( existingDevice["address"] .toString() == address )
        {
            return;
        }
    }

    QString deviceName = device.name();

    if (deviceName.isEmpty())
    {
        deviceName = "Unknown Device";
    }

    QString deviceType = "Unknown";

    switch (device.majorDeviceClass())
    {
        case QBluetoothDeviceInfo::MiscellaneousDevice:
            deviceType = "Miscellaneous";
            break;

        case QBluetoothDeviceInfo::ComputerDevice:
            deviceType = "Computer";
            break;

        case QBluetoothDeviceInfo::PhoneDevice:
            deviceType = "Phone";
            break;

        case QBluetoothDeviceInfo::NetworkDevice:
            deviceType = "Network";
            break;

        case QBluetoothDeviceInfo::AudioVideoDevice:
            deviceType = "Audio / Video";
            break;

        case QBluetoothDeviceInfo::PeripheralDevice:
            deviceType = "Peripheral";
            break;

        case QBluetoothDeviceInfo::ImagingDevice:
            deviceType = "Imaging";
            break;

        case QBluetoothDeviceInfo::WearableDevice:
            deviceType = "Wearable";
            break;

        case QBluetoothDeviceInfo::ToyDevice:
            deviceType = "Toy";
            break;

        default:
            deviceType = "Unknown";
            break;
    }

    QVariantMap deviceMap;

    deviceMap["name"] = deviceName;
    deviceMap["address"] = address;
    deviceMap["rssi"] =  device.rssi();
    deviceMap["type"] = deviceType;
    deviceMap["isAudioDevice"] = ( device.majorDeviceClass() ==
            QBluetoothDeviceInfo::AudioVideoDevice );

    m_devices.append( deviceMap );
    emit devicesChanged();
}

void BluetoothManager::discoveryFinished()
{
    qDebug() << "====================================";
    qDebug() << "Bluetooth discovery finished";
    qDebug() << "Devices found:" << m_devices.size();
    qDebug() << "====================================";

    if (m_scanTimer)
    {
        m_scanTimer->stop();
    }

    if (m_scanning)
    {
        m_scanning = false;
        emit scanningChanged();
    }

    if (m_scanElapsedSeconds >= SCAN_DURATION_SECONDS)
    {
        if (m_scanProgress != 100)
        {
            m_scanProgress = 100;
            emit scanProgressChanged();
        }

        if (!m_scanCompleted)
        {
            m_scanCompleted = true;
            emit scanCompletedChanged();
        }
    }

    if (m_devices.isEmpty())
    {
        setConnectionStatus( "No Bluetooth devices found");
    }
    else
    {
        setConnectionStatus( QString("%1 device(s) found").arg(m_devices.size()));
    }
}

void BluetoothManager::discoveryError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    qWarning() << "Bluetooth discovery error:" << error;
    qWarning() << m_discoveryAgent->errorString();

    if (m_scanTimer)m_scanTimer->stop();

    if (m_scanning)
    {
        m_scanning = false;
        emit scanningChanged();
    }

    m_scanCompleted = false;
    emit scanCompletedChanged();
    setConnectionStatus("Bluetooth scan error");
}

void BluetoothManager::hostModeStateChanged(QBluetoothLocalDevice::HostMode state)
{
    bool poweredOn =state != QBluetoothLocalDevice::HostPoweredOff;

    qDebug()<< "Bluetooth host mode changed:" << state;

    if (m_bluetoothPoweredOn == poweredOn)
        return;

    m_bluetoothPoweredOn = poweredOn;
    emit bluetoothPoweredOnChanged();

    if (!m_bluetoothPoweredOn)
    {
        if (m_scanTimer)
        {
            m_scanTimer->stop();
        }

        if (m_scanning)
        {
            m_discoveryAgent->stop();
            m_scanning = false;
            emit scanningChanged();
        }

        // Reset scan state
        m_scanCompleted = false;
        emit scanCompletedChanged();

        // Disconnect current device
        if (m_connected)
        {
            stopFileReceiver();

            m_connected = false;
            m_connectedDeviceName.clear();
            m_connectedAddress.clear();

            emit connectedChanged();
            emit connectedDeviceChanged();
        }

        setConnectionStatus( "Bluetooth is powered off");
    }
    else
    {
        setConnectionStatus( "Bluetooth is ready");
    }
}


void BluetoothManager::pairAndConnect(const QString &address, const QString &name)
{
    if (address.isEmpty())
    {
        setConnectionStatus("Invalid Bluetooth address");
        return;
    }

    if (!m_bluetoothPoweredOn)
    {
        setConnectionStatus("Bluetooth is powered off");
        return;
    }

    if (m_connected && m_connectedAddress == address)
    {
        setConnectionStatus( "Already connected");
        return;
    }

    qDebug()<< "====================================";
    qDebug()<< "Pairing / connecting";
    qDebug()<< "Device:" << name;
    qDebug() << "Address:" << address;
    qDebug() << "====================================";

    setConnectionStatus( "Pairing...");

    QProcess *process = new QProcess(this);

    connect( process, QOverload<int, QProcess::ExitStatus>::of( &QProcess::finished ),
        this, [this, process, address, name](int exitCode, QProcess::ExitStatus status)
        {
            Q_UNUSED(status)

            QString output = QString::fromUtf8(process->readAllStandardOutput());
            QString error = QString::fromUtf8(process->readAllStandardError());

            qDebug()<< "bluetoothctl output:" << output;

            qDebug()<< "bluetoothctl exit code:"<< exitCode;

            if (!error.isEmpty())
            {
                qWarning()<< "bluetoothctl error:"<< error;
            }

            QProcess *checkProcess = new QProcess(this);

            connect( checkProcess, QOverload<int, QProcess::ExitStatus>::of( &QProcess::finished),
                this, [this, checkProcess,process,address,name](int checkExitCode,  QProcess::ExitStatus checkStatus)
                {
                    Q_UNUSED(checkStatus)
                    QString checkOutput = QString::fromUtf8( checkProcess
                                ->readAllStandardOutput() );

                    QString checkError = QString::fromUtf8( checkProcess ->readAllStandardError());

                    qDebug()<< "Connection check:" << checkOutput;

                    if (!checkError.isEmpty())
                    {
                        qWarning()<< "Connection check error:"<< checkError;
                    }

                    bool success =(checkExitCode == 0 && checkOutput.contains( "Connected: yes",
                                Qt::CaseInsensitive) );

                    if (success)
                    {
                        m_connected = true;
                        m_connectedDeviceName = name;
                        m_connectedAddress = address;

                        setConnectionStatus( "Connected");

                        emit connectedChanged();
                        emit connectedDeviceChanged();

                        qDebug() << "Connected to:" << name;

                        startFileReceiver();
                    }
                    else
                    {
                        m_connected = false;
                        m_connectedDeviceName.clear();
                        m_connectedAddress.clear();

                        setConnectionStatus( "Connection failed");

                        emit connectedChanged();
                        emit connectedDeviceChanged();

                        qWarning() << "Connection failed:"<< name;
                    }

                    checkProcess->deleteLater();
                    process->deleteLater();
                }
            );

            checkProcess->start( "bluetoothctl", { "info", address } );
        }
    );

    QString script =QString("power on\n" "agent on\n" "default-agent\n" "pairable on\n"
            "pair %1\n" "trust %1\n" "connect %1\n" "quit\n" ).arg(address);

    process->start("bluetoothctl",{ "--timeout", "30" } );

    if (!process->waitForStarted(3000))
    {
        qWarning()<< "Failed to start bluetoothctl";
        process->deleteLater();
        setConnectionStatus( "Failed to start Bluetooth"  );

        return;
    }

    process->write(script.toUtf8());
    process->closeWriteChannel();
}

void BluetoothManager::disconnectDevice()
{
    if (m_connectedAddress.isEmpty())
    {
        setConnectionStatus("No device connected");

        return;
    }

    qDebug()<< "Disconnecting:" << m_connectedAddress;

    stopFileReceiver();

    QProcess::execute( "bluetoothctl", {  "disconnect",  m_connectedAddress});

    m_connected = false;
    m_connectedDeviceName.clear();
    m_connectedAddress.clear();

    setConnectionStatus("Disconnected");

    emit connectedChanged();
    emit connectedDeviceChanged();
}


void BluetoothManager::setDiscoverable(bool enabled)
{
    if (!m_bluetoothPoweredOn)
    {
        qWarning() << "Bluetooth is powered off";
        setConnectionStatus( "Bluetooth is powered off");

        return;
    }

    if (enabled)
    {
        QProcess::execute( "bluetoothctl",{"discoverable","on"});

        QProcess::execute("bluetoothctl",{"pairable","on"} );

        qDebug() << "Bluetooth:" << "Discoverable + Pairable";
    }
    else
    {
        QProcess::execute("bluetoothctl",{"discoverable","off"});

        qDebug()<< "Bluetooth:"<< "Discoverable off";
    }
}

void BluetoothManager::startFileReceiver()
{
    if (m_fileReceiver)
    {
        qDebug() << "OBEX receiver already exists";
        return;
    }

    QString musicLocation =QStandardPaths::writableLocation(QStandardPaths::MusicLocation);

    if (musicLocation.isEmpty())
    {
        musicLocation =QDir::homePath() + "/Music";
    }

    m_bluetoothReceiveDirectory = musicLocation + "/BluetoothReceived";

    QDir directory( m_bluetoothReceiveDirectory);

    if (!directory.exists())
    {
        if (!directory.mkpath("."))
        {
            qWarning()<< "Cannot create:"<< m_bluetoothReceiveDirectory;
            setConnectionStatus("Cannot create receive directory");

            return;
        }
    }

    if (!m_fileWatcher->directories().contains(m_bluetoothReceiveDirectory))
    {
        m_fileWatcher->addPath(m_bluetoothReceiveDirectory);
    }
    m_fileReceiver = new QProcess(this);

    connect(m_fileReceiver,&QProcess::readyReadStandardOutput,this,
        [this](){QString output =  QString::fromUtf8(m_fileReceiver->readAllStandardOutput());

            qDebug()<< "OBEX:"<< output;
            handleObexOutput(output);
        }
    );

    connect(m_fileReceiver,&QProcess::readyReadStandardError,this,[this]()
        {
            QString error = QString::fromUtf8(m_fileReceiver->readAllStandardError());

            qWarning()<< "OBEX:"<< error;
            handleObexOutput(error);
        }
    );

    connect(m_fileReceiver, &QProcess::errorOccurred, this,[this](QProcess::ProcessError error)
        {
            qWarning()<< "OBEX process error:" << error;
            setReceivingFile(false);
            setConnectionStatus("OBEX receiver error");
        }
    );

    connect( m_fileReceiver,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),this,
        [this](int exitCode,QProcess::ExitStatus status)
        {
            Q_UNUSED(status)

            qDebug()<< "OBEX receiver stopped";
            qDebug()<< "Exit code:" << exitCode;

            setReceivingFile(false);

            if (m_fileReceiver)
            {
                m_fileReceiver->deleteLater();
                m_fileReceiver = nullptr;
            }
        }
    );

    QStringList arguments;

    arguments<< "-s"<< m_bluetoothReceiveDirectory;

    qDebug()<< "====================================";
    qDebug()<< "Starting Bluetooth OBEX receiver";
    qDebug()<< "Directory:"<< m_bluetoothReceiveDirectory;
    qDebug()<< "====================================";

    m_fileReceiver->start("bt-obex",arguments );

    if (!m_fileReceiver->waitForStarted(3000))
    {
        qWarning() << "Failed to start bt-obex";

        m_fileReceiver->deleteLater();
        m_fileReceiver = nullptr;
        setConnectionStatus("Failed to start OBEX");

        return;
    }

    setReceivingFile(true);
    setConnectionStatus("Ready to receive files");

    qDebug()<< "Bluetooth OBEX receiver started";
}
void BluetoothManager::handleObexOutput(const QString &output)
{
    if (output.isEmpty())
    {
        return;
    }

    if (output.contains("Transfer Request",Qt::CaseInsensitive))
    {
        qDebug()<< "Bluetooth file transfer request received";
    }

    QRegularExpression nameRegex("Name:\\s*(.+)");

    QRegularExpressionMatch match = nameRegex.match(output);

    if (match.hasMatch())
    {
        m_currentTransferFile = match.captured(1).trimmed();

        qDebug()<< "Incoming file:" << m_currentTransferFile;
    }

    QRegularExpression sizeRegex("Size:\\s*(\\d+)\\s*bytes");

    match =sizeRegex.match(output);

    if (match.hasMatch())
    {
        m_currentTransferSize = match.captured(1).toLongLong();

        qDebug()<< "Incoming file size:"<< m_currentTransferSize;
    }

    if (output.contains("Accept (yes/no)?",Qt::CaseInsensitive))
    {
        qDebug()<< "Automatically accepting Bluetooth file";

        if (m_fileReceiver)
        {
            m_fileReceiver->write("yes\n");
        }

        setReceivingFile(true);
        setConnectionStatus("Receiving file...");
    }

    if (output.contains("Transfer started", Qt::CaseInsensitive))
    {
        setReceivingFile(true);
        setConnectionStatus("Receiving file...");
    }

    if (output.contains("Transfer succeeded",Qt::CaseInsensitive))
    {
        qDebug()<< "Bluetooth transfer succeeded";

        setReceivingFile(false);

        setConnectionStatus("File received");

        QTimer::singleShot(500,this,[this]()
            {
                checkForReceivedAudioFile(m_bluetoothReceiveDirectory);
            }
        );
    }
}

void BluetoothManager::stopFileReceiver()
{
    if (!m_fileReceiver)
    {
        setReceivingFile(false);
        return;
    }

    qDebug()<< "Stopping Bluetooth OBEX receiver";

    m_fileReceiver->terminate();

    if (!m_fileReceiver->waitForFinished(1500))
    {
        m_fileReceiver->kill();
        m_fileReceiver->waitForFinished(500);
    }

    setReceivingFile(false);

    if (m_fileReceiver)
    {
        m_fileReceiver->deleteLater();
        m_fileReceiver = nullptr;
    }
}


void BluetoothManager::checkForReceivedAudioFile(const QString &directory)
{
    QDir dir(directory);

    if (!dir.exists())
    {
        return;
    }

    QFileInfoList files = dir.entryInfoList( QDir::Files,QDir::Time);

    if (files.isEmpty())
    {
        return;
    }

    for (const QFileInfo &fileInfo : files)
    {
        QString filePath = fileInfo.absoluteFilePath();

        if (!isAudioFile(filePath))
        {
            continue;
        }

        qint64 size1 = fileInfo.size();

        QTimer::singleShot( 200, this, [this, filePath, size1]()
            {
                QFileInfo updatedFile( filePath );

                if (!updatedFile.exists())
                    return;

                qint64 size2 = updatedFile.size();

                // File is still being written
                if (size1 != size2)
                {
                    qDebug()<< "File still changing:"<< filePath;

                    return;
                }

                if (m_receivedFilePath == filePath)
                {
                    return;
                }

                m_receivedFilePath = filePath;

                qDebug() << "====================================";
                qDebug() << "Bluetooth audio received:";
                qDebug() << m_receivedFilePath;
                qDebug() << "====================================";

                emit receivedFileChanged();

                emit fileReceived( m_receivedFilePath);

                setConnectionStatus( "Audio file ready" );
            }
        );

        return;
    }
}

bool BluetoothManager::isAudioFile(
    const QString &filePath) const
{
    QFileInfo fileInfo( filePath );
    QString extension = fileInfo.suffix() .toLower();

    return extension == "mp3" || extension == "wav" || extension == "m4a";
}