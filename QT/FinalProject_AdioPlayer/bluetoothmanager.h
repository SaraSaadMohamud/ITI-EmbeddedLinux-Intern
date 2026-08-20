#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QObject>

#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceInfo>
#include <QBluetoothAddress>

#include <QVariantList>
#include <QProcess>
#include <QFileSystemWatcher>
#include <QTimer>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>

#include <QtQml/qqmlregistration.h>


class BluetoothManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    // Bluetooth state
    Q_PROPERTY(bool scanning            READ getscanning            NOTIFY scanningChanged)
    Q_PROPERTY(bool bluetoothPoweredOn  READ getbluetoothPoweredOn  NOTIFY bluetoothPoweredOnChanged)
    Q_PROPERTY(QVariantList devices     READ getdevices             NOTIFY devicesChanged)

    // Scan progress
    Q_PROPERTY(int scanProgress        READ getScanProgress        NOTIFY scanProgressChanged)
    Q_PROPERTY(int scanElapsedSeconds  READ getScanElapsedSeconds  NOTIFY scanElapsedSecondsChanged)
    Q_PROPERTY(QString scanStartTime   READ getScanStartTime       NOTIFY scanStartTimeChanged)
    Q_PROPERTY(bool scanCompleted      READ getScanCompleted       NOTIFY scanCompletedChanged)
 
    // Connection state 
    Q_PROPERTY(bool connected               READ getConnected           NOTIFY connectedChanged)
    Q_PROPERTY(QString connectedDeviceName  READ getConnectedDeviceName NOTIFY connectedDeviceChanged)
    Q_PROPERTY(QString connectionStatus     READ getConnectionStatus    NOTIFY connectionStatusChanged)
 
    // File receiving 
    Q_PROPERTY(bool receivingFile       READ getReceivingFile       NOTIFY receivingFileChanged)
    Q_PROPERTY(QString receivedFilePath READ getReceivedFilePath    NOTIFY receivedFileChanged)

public:
    explicit BluetoothManager(QObject *parent = nullptr);

    // Getters

    bool getscanning() const;
    bool getbluetoothPoweredOn() const;
    bool getScanCompleted() const;
    bool getConnected() const;
    bool getReceivingFile() const;

    QVariantList getdevices() const;
    QString getScanStartTime() const;
    QString getConnectedDeviceName() const;
    QString getConnectionStatus() const;
    QString getReceivedFilePath() const;

    int getScanProgress() const;
    int getScanElapsedSeconds() const;

    // Bluetooth discovery
    Q_INVOKABLE void startScan();
    Q_INVOKABLE void stopScan();

    // Pair / Connect
    Q_INVOKABLE void pairAndConnect( const QString &address, const QString &name );
    Q_INVOKABLE void disconnectDevice();

    // Adapter settings
    Q_INVOKABLE void setDiscoverable( bool enabled );

    // OBEX file receiver
    Q_INVOKABLE void startFileReceiver();
    Q_INVOKABLE void stopFileReceiver();

signals:

    // Bluetooth discovery
    void scanningChanged();
    void bluetoothPoweredOnChanged();
    void devicesChanged();

    // Scan progress
    void scanProgressChanged();
    void scanElapsedSecondsChanged();
    void scanStartTimeChanged();
    void scanCompletedChanged();

    // Connection
    void connectedChanged();
    void connectedDeviceChanged();
    void connectionStatusChanged();

    // File receiving
    void receivingFileChanged();
    void receivedFileChanged();
    void fileReceived(const QString &filePath
    );

private slots:

    // Discovery
    void deviceDiscovered( const QBluetoothDeviceInfo &device);
    void discoveryFinished();
    void discoveryError(QBluetoothDeviceDiscoveryAgent::Error error);
 
    // Bluetooth state
    void hostModeStateChanged(QBluetoothLocalDevice::HostMode state);

    // Scan progress
    void updateScanProgress();

private:

    // Bluetooth

    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent;
    QBluetoothLocalDevice *m_localDevice;
    QVariantList m_devices;

    bool m_scanning;
    bool m_bluetoothPoweredOn;

    // Scan progress
    QTimer *m_scanTimer;
    int m_scanProgress;
    int m_scanElapsedSeconds;
    QString m_scanStartTime;
    bool m_scanCompleted;
    static constexpr int SCAN_DURATION_SECONDS = 10;

    // Connection
    bool m_connected;
    QString m_connectedDeviceName;
    QString m_connectedAddress;
    QString m_connectionStatus;

    // OBEX
    QProcess *m_fileReceiver;
    QFileSystemWatcher *m_fileWatcher;
    QString m_bluetoothReceiveDirectory;
    bool m_receivingFile;
    QString m_receivedFilePath;
    QString m_currentTransferFile;
    qint64 m_currentTransferSize;

    // Helpers
    void setConnectionStatus(const QString &status);
    void checkForReceivedAudioFile(const QString &directory);
    bool isAudioFile(const QString &filePath) const;
    void handleObexOutput(const QString &output);
    void setReceivingFile( bool receiving );
};

#endif // BLUETOOTHMANAGER_H