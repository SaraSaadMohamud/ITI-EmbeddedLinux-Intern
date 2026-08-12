#include "audioplayer.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QMediaMetaData>
#include <QDir>

Q_DECLARE_LOGGING_CATEGORY(mediaPlayer);
Q_LOGGING_CATEGORY(mediaPlayer,"app.mediaPlayer")

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

    // Radio

    m_radio_station = {
        QVariantMap{
            {"name", "Cairo Quran Radio Station"},
            {"country","🇪🇬 EGYPT"},
            {"url","http://n12.radiojar.com/8s5u5tpdtwzuv"}
        },
        QVariantMap{
            {"name", "Maka Quran Radio Station"},
            {"country","🇸🇦 Saudi Arabia"},
            {"url","http://live.mp3quran.net:8008/"}
        },
        QVariantMap{
            {"name", "Nablus Quran Radio Station"},
            {"country","🇵🇸 Palestine"},
            {"url","http://www.quran-radio.org:8002/"}
        },
        QVariantMap{
            {"name", "Jordan Quran Radio Station"},
            {"country", "🇯🇴 Jordan"},
            {"url", "https://jrtv-live.ercdn.net/jordanhd/jordanhd.m3u8"} // Live digital stream URL
        },
        };


    emit radioStationsChanged();

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
        emit positionChanged();
    }
    else {
        qCWarning(mediaPlayer)<<"Invalide Position: "<<position
                              <<" Duration: "<<getDuration();
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
    if(m_is_radio_mode == true)
    {
        nextRadioStation();
        return;
    }

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
    if(m_is_radio_mode == true)
    {
        previousRadioStation();
        return;
    }
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
    m_is_radio_mode = false;
    m_current_station_name.clear();
    emit radioModeChanged();
    emit currentRadioStationChanged();

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

/*********************************************************************************************************************/

void AudioPlayer::playRadionStation(qint64 radio_station_index)
{
    if( ( radio_station_index < 0 ) || ( radio_station_index >= m_radio_station.size() ))
    {
        qCWarning(mediaPlayer)<<"Invalid radio station Index!";
        return;
    }

    m_is_radio_mode = true;
    m_current_station_index = radio_station_index;
    QVariantMap radion_station = m_radio_station[m_current_station_index].toMap();
    m_current_station_name = radion_station.value("name").toString();

    clearMediMetaData();

    QString radio_src = radion_station.value("url").toString();
    setSource(radio_src);

    emit currentRadioStationChanged();
    emit radioModeChanged();

    m_media_player->play();
    qCInfo(mediaPlayer) <<"Tunning to Station: "<<m_current_station_name;

}

void AudioPlayer::previousRadioStation()
{
    if(m_radio_station.isEmpty())
    {
        qCWarning(mediaPlayer)<<"No Station Avalible, Station List is Empty!";
        return;
    }

    if(!m_is_radio_mode)
    {
        qCWarning(mediaPlayer)<<"Radio Mode is Off!";
        return;
    }

    m_current_station_index =( ( (m_current_station_index-1) % m_radio_station.size() ) + m_radio_station.size() );

    emit currentPlayListIndexChanged();
    playRadionStation(m_current_station_index);
}

void AudioPlayer::nextRadioStation()
{
    if(m_radio_station.isEmpty())
    {
        qCWarning(mediaPlayer)<<"No Station Avalible, Station List is Empty!";
        return;
    }

    if(!m_is_radio_mode)
    {
        qCWarning(mediaPlayer)<<"Radio Mode is Off!";
        return;
    }

    m_current_station_index =( (m_current_station_index + 1) % m_radio_station.size() );

    emit currentPlayListIndexChanged();
    playRadionStation(m_current_station_index);
}

bool AudioPlayer::getRadioMode() const
{
    return m_is_radio_mode;
}

QVariantList AudioPlayer::getRadioStation() const
{
    return m_radio_station;
}

QString AudioPlayer::getCurrentRadioStation() const
{
    return m_current_station_name;
}

bool AudioPlayer::getCheckConnectingState() const
{
    return m_redio_recconecting;
}

void AudioPlayer::clearMediMetaData()
{
    m_audio_title.clear();
    m_audio_author.clear();
    m_audio_genre.clear();
    m_audio_album.clear();

    emit metaDataChanged();
}