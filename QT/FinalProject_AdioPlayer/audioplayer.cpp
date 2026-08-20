#include "audioplayer.h"
#include "loggin.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QMediaMetaData>
#include <QDir>
#include <QDirIterator>
#include <QStandardPaths>
#include <QFileInfo>

AudioPlayer::AudioPlayer(QObject *parent)
    : QObject{parent}
{
    m_media_player = new QMediaPlayer(this);
    m_audio_output = new QAudioOutput(this);

    m_media_player->setAudioOutput(m_audio_output);
    m_audio_output->setVolume(0.5);

    // Connect QMediaPlayer & QAudioOutpue signals  with my media/audio signals
    connect(m_media_player,&QMediaPlayer::positionChanged,this,&AudioPlayer::positionChanged);
    connect(m_media_player,&QMediaPlayer::durationChanged,this,&AudioPlayer::durationChanged);
    connect(m_media_player,&QMediaPlayer::playingChanged ,this,&AudioPlayer::playingStateChanged);
    connect(m_audio_output,&QAudioOutput::mutedChanged   ,this,&AudioPlayer::muteStateChanged);
    connect(m_audio_output,&QAudioOutput::volumeChanged  ,this,&AudioPlayer::volumeChanged);

    // Error Handling
    connect(m_media_player, &QMediaPlayer::errorOccurred, this, [this](QMediaPlayer::Error err){
        if(err !=QMediaPlayer::NoError){
            m_error_string = m_media_player->errorString();
            qCWarning(mediaPlayer) <<"Playback Error: "<<m_error_string;
            emit errorOccured();
        }
    });

    // Meta Data Handling
    connect(m_media_player, &QMediaPlayer::metaDataChanged, this, [this](){
        QMediaMetaData meta_data = m_media_player->metaData();
        m_audio_title  = meta_data.stringValue(QMediaMetaData::Title);
        m_audio_author = meta_data.stringValue(QMediaMetaData::ContributingArtist);
        m_audio_genre  = meta_data.stringValue(QMediaMetaData::Genre);
        m_audio_album  = meta_data.stringValue(QMediaMetaData::AlbumTitle);

        emit metaDataChanged();

        qCDebug(mediaPlayer)<<"Title        :"<<m_audio_title
                             <<"Author       :"<<m_audio_author
                             <<"Genre        :"<<m_audio_genre
                             <<"Album Title  :"<<m_audio_album;
    });

}


bool AudioPlayer::getPlayingState() const
{
    return m_media_player->isPlaying();
}

qint64 AudioPlayer::getPosition() const
{
    return m_media_player->position();
}

qint64 AudioPlayer::getDuration() const
{
    return m_media_player->duration();
}

bool AudioPlayer::getMuteState() const
{
    return m_audio_output->isMuted();
}

float AudioPlayer::getvolume() const
{
    return m_audio_output->volume();
}

QStringList AudioPlayer::getPlayingList() const
{
    return m_play_list;
}

qint64 AudioPlayer::getCurrentPlayingIndex() const
{
    return m_current_playlist_index;
}

QString AudioPlayer::getAudioTitle() const
{
    return m_audio_title;
}

QString AudioPlayer::getAudioAuthor() const
{
    return m_audio_author;
}

QString AudioPlayer::getAudioGenre() const
{
    return m_audio_genre;
}

QString AudioPlayer::getAudioALbum() const
{
    return m_audio_album;
}

QString AudioPlayer::geterrorstring() const
{
    return m_error_string;
}

void AudioPlayer::setPosition(qint64 position)
{
    if ((position >= 0) && (position <= getDuration() ))
    {
        m_media_player-> setPosition(position);
    }
    else
    {
        qCWarning(mediaPlayer)<<"Invalide Position: "<<position<<" Duration: "<<getDuration();
    }
}

void AudioPlayer::setMuteState(bool position)
{
    m_audio_output->setMuted(position);
}

void AudioPlayer::setVolume(float position)
{
    m_audio_output->setVolume( qBound(0.0f,position,1.0f) );
}


void AudioPlayer::playPause()
{
    if(getPlayingState())
    {
        m_media_player->pause();
    }
    else
    {
        m_media_player->play();
    }
}

void AudioPlayer::stop()
{
    m_media_player->stop();
}

void AudioPlayer::next()
{
    if(m_play_list.isEmpty())
    {
        qCWarning(mediaPlayer)<<"PlayList is Empty";
        m_error_string = QString("PlayList is Empty");
        emit errorOccured();
        return;
    }

    m_current_playlist_index = ( (m_current_playlist_index+1)% m_play_list.size() );
    emit currentPlayListIndexChanged();
    setSource(m_play_list[m_current_playlist_index]);
    m_media_player->play();
    qCInfo(mediaPlayer)<<"Playing Local FIle: "<<m_play_list[m_current_playlist_index];
}

void AudioPlayer::previouse()
{
    if(m_play_list.isEmpty())
    {
        qCWarning(mediaPlayer)<<"PlayList is Empty";
        m_error_string = QString("PlayList is Empty");
        emit errorOccured();
        return;
    }

    m_current_playlist_index = ( ( (m_current_playlist_index-1) + m_play_list.size()) % m_play_list.size() );
    emit currentPlayListIndexChanged();
    setSource(m_play_list[m_current_playlist_index]);
    m_media_player->play();
    qCInfo(mediaPlayer)<<"Playing Local FIle: "<<m_play_list[m_current_playlist_index];
}

void AudioPlayer::loadFolder(const QString &folder_path)
{
    qCDebug(mediaPlayer)<<"Incoming UI Folder Path:"<<folder_path;
    QUrl url(folder_path);
    qCDebug(mediaPlayer)<<"URL Folder Path:"<<url;
    QString local_folder_path = url.toLocalFile();
    qCDebug(mediaPlayer)<<"Local Folder Path:"<<local_folder_path;

    QDir dir(local_folder_path);
    if(! dir.exists())
    {
        m_error_string = QString("FOlder doesn't exists: %1").arg(local_folder_path);
        qCWarning(mediaPlayer)<<m_error_string;
        emit errorOccured();
        return;
    }

    QStringList filters= {"*.mp3","*.m4a","*.wav"};
    QFileInfoList filteredFiles = dir.entryInfoList(filters,QDir::Files);

    if(filteredFiles.isEmpty())
    {
        m_error_string = QString("no Aduio Files found in : %1").arg(local_folder_path);
        qCWarning(mediaPlayer)<<m_error_string;
        emit errorOccured();
        return;
    }

    QStringList audioFilesPath;
    for(auto file: filteredFiles)
    {
        audioFilesPath<<file.absoluteFilePath();
    }

    m_play_list = audioFilesPath;
    m_current_playlist_index = 0;
    m_error_string.clear();

    emit playListChanged();
    emit currentPlayListIndexChanged();
    emit errorOccured();

    setSource(m_play_list[m_current_playlist_index]);
    qCInfo(mediaPlayer)<<"Loaded "<<m_play_list.size()<<" from "<<local_folder_path;

}

QString AudioPlayer::formateTime(qint64 time_ms)
{
    if(time_ms < 0)
    {
        return("00:00");
    }

    qint64 total_seconds = (time_ms) / 1000;
    qint64 hrs = (total_seconds / 3600);
    qint64 mins = (total_seconds % 3600) / 60;
    qint64 seconds = (total_seconds % 60);

    if(hrs)
    {
        return QString("%1:%2:%3")
        .arg(hrs,2,10,QChar('0'))
            .arg(mins,2,10,QChar('0'))
            .arg(seconds,2,10,QChar('0'));
    }
    else
    {
        return QString("%1:%2")
        .arg(mins,2,10,QChar('0'))
            .arg(seconds,2,10,QChar('0'));
    }

}

void AudioPlayer::setSource(const QString audio_source)
{
    m_media_player->stop();
    m_media_player->setSource(QUrl(audio_source));
}


void AudioPlayer::playBluetoothFile(const QString &filePath)
{
    if (filePath.isEmpty())
    {
        m_error_string = "Bluetooth audio file path is empty.";

        qCWarning(mediaPlayer)
            << m_error_string;

        emit errorOccured();

        return;
    }

    QFileInfo fileInfo(filePath);

    if (!fileInfo.exists())
    {
        m_error_string =
            QString("Bluetooth audio file does not exist: %1")
                .arg(filePath);

        qCWarning(mediaPlayer)
            << m_error_string;

        emit errorOccured();

        return;
    }

    if (!fileInfo.isFile())
    {
        m_error_string =
            QString("Bluetooth path is not a file: %1")
                .arg(filePath);

        qCWarning(mediaPlayer)
            << m_error_string;

        emit errorOccured();

        return;
    }

    qCInfo(mediaPlayer)
        << "====================================";

    qCInfo(mediaPlayer)
        << "Playing Bluetooth received audio:";

    qCInfo(mediaPlayer)
        << filePath;

    qCInfo(mediaPlayer)
        << "====================================";


    // Stop current playback
    m_media_player->stop();


    // Clear previous playlist
    m_play_list.clear();

    m_current_playlist_index = 0;

    // Put received Bluetooth file in playlist
    m_play_list.append(filePath);


    // Clear previous metadata
    m_audio_title.clear();
    m_audio_author.clear();
    m_audio_genre.clear();
    m_audio_album.clear();

    m_error_string.clear();


    emit playListChanged();

    emit currentPlayListIndexChanged();

    emit metaDataChanged();

    emit errorOccured();

// =====================================================
// Load Bluetooth audio file
// =====================================================

setSource(filePath);

// =====================================================
// Play automatically
// =====================================================

m_media_player->play();
}
/*********************************************************************************************************************/
bool AudioPlayer::getUSBConnection() const
{
    return m_usb_connected;
}

QString AudioPlayer::getUSBPath() const
{
    return m_usb_path;
}

QStringList AudioPlayer::getUSSBDevices() const
{
    return m_usb_devices;
}

void AudioPlayer::scanUSB()
{
    QString user = qEnvironmentVariable("USER");
    QString mediaPath = "/media/"+ user;
    qCDebug(mediaPlayer)<<"Scanning USB directory:"<<mediaPath;

    QDir mediaDir(mediaPath);

    bool oldConnected = m_usb_connected;
    QString oldPath = m_usb_path;
    QStringList oldDevices = m_usb_devices;
    m_usb_devices.clear();

    if (!mediaDir.exists())
    {
        if (oldConnected)
        {
            qCDebug(mediaPlayer)
            << "USB removed - clearing player";

            clearUSB();
        }

        m_usb_devices.clear();

        if (oldDevices != m_usb_devices)
        {
            emit usbDevicesChanged();
        }

        return;
    }

    // if there are Multi USB
    QStringList usbMountedDevices = mediaDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    if (usbMountedDevices.isEmpty())
    {
        if (oldConnected)
        {
            qCDebug(mediaPlayer)<< "USB removed - clearing player";
            clearUSB();
        }

        if (oldDevices != m_usb_devices)
        {
            emit usbDevicesChanged();
        }

        qCDebug(mediaPlayer)<< "No USB device found.";

        return;
    }

    QStringList audioFilters={
                                "*.mp3",
                                "*.m4a",
                                "*.wav"
    };

    for(const QString &deviceName : usbMountedDevices)
    {
        QString devicePath = mediaDir.absoluteFilePath(deviceName);
        qCDebug(mediaPlayer)<< "Checking device:"<< devicePath;

        QDirIterator iterator(
            devicePath,
            audioFilters,
            QDir::Files,
            QDirIterator::Subdirectories
        );

        if (iterator.hasNext())
        {
            m_usb_devices.append(devicePath);
            qCInfo(mediaPlayer)<< "Audio device found:" << devicePath;
        }
    }

    if (m_usb_devices.isEmpty())
    {
        if (oldConnected)
        {
            qCDebug(mediaPlayer)<< "USB removed or contains no audio - clearing player";
            clearUSB();
        }

        if (oldDevices != m_usb_devices)
        {
            emit usbDevicesChanged();
        }

        qCInfo(mediaPlayer)<< "No audio devices found.";

        return;
    }


    m_usb_connected = true;

    if (oldConnected != m_usb_connected)
    {
        emit usbConnectionChanged();
    }
    if (oldDevices != m_usb_devices)
    {
        emit usbDevicesChanged();
    }

    qDebug(mediaPlayer)<<"USB devices Found: "<<m_usb_devices;
}

void AudioPlayer::loadUSB(const QString &usbPath)
{
    if (usbPath.isEmpty()) {
        m_error_string = "USB path is empty.";
        qCWarning(mediaPlayer) << m_error_string;
        emit errorOccured();
        return;
    }

    QDir usbDir(usbPath);
    if (!usbDir.exists())
    {
        m_error_string =QString("USB path does not exist: %1").arg(usbPath);
        qCWarning(mediaPlayer)<< m_error_string;
        emit errorOccured();
        return;
    }

    m_usb_path = usbPath;
    m_usb_connected = true;

    emit usbConnectionChanged();
    emit usbPathChanged();

    QStringList audioFilters={
        "*.mp3",
        "*.m4a",
        "*.wav"
    };

    QDirIterator iterator(
        usbPath,
        audioFilters,
        QDir::Files,
        QDirIterator::Subdirectories
    );

    QStringList usbAudioFiles;
    while (iterator.hasNext())
    {
        usbAudioFiles.append(iterator.next());
    }

    if (usbAudioFiles.isEmpty())
    {
        m_error_string = QString("No audio files found in USB: %1").arg(usbPath);
        qCWarning(mediaPlayer)<< m_error_string;
        emit errorOccured();
        return;
    }

    m_play_list = usbAudioFiles;
    m_current_playlist_index = -1;
    m_error_string.clear();

    m_media_player->stop();
    m_media_player->setSource(QUrl());

    // Clear metadata
    m_audio_title.clear();
    m_audio_author.clear();
    m_audio_genre.clear();
    m_audio_album.clear();

    emit playListChanged();
    emit currentPlayListIndexChanged();
    emit metaDataChanged();
    emit positionChanged();
    emit durationChanged();
    emit playingStateChanged();

    qCInfo(mediaPlayer) << "Loaded" << m_play_list.size() << "audio files from" << usbPath << "- waiting for user selection.";

}

void AudioPlayer::playSelected(int index)
{
    if (index < 0 || index >= m_play_list.size())
    {
        return;
    }

    m_current_playlist_index = index;
    emit currentPlayListIndexChanged();
    setSource(m_play_list[index]);
   // m_media_player->play();
}

void AudioPlayer::clearUSB()
{
    qCDebug(mediaPlayer) << "USB disconnected - clearing player data";

    m_media_player->stop();
    m_media_player->setSource(QUrl());
    m_play_list.clear();
    m_current_playlist_index = -1;

    // Clear metadata
    m_audio_title.clear();
    m_audio_author.clear();
    m_audio_genre.clear();
    m_audio_album.clear();

    // Clear USB
    m_usb_path.clear();
    m_usb_connected = false;

    // Notify QML
    emit playListChanged();
    emit currentPlayListIndexChanged();
    emit metaDataChanged();
    emit usbPathChanged();
    emit usbConnectionChanged();
    emit usbDevicesChanged();

    qCDebug(mediaPlayer)<< "USB player data cleared successfully";
}