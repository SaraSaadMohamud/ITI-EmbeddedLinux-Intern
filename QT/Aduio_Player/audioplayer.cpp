#include "audioplayer.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QMediaMetaData>

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
    })

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

QString AudioPlayer::getudioALbum() const
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
    m_audio_output->mutedChanged(position);
}

void AudioPlayer::setVolume(float position)
{
    m_audio_output->setVolume( qBound(0.0f,position,1.0f) );
}

void AudioPlayer::playPause()
{
    
}

void AudioPlayer::stop()
{
    
}

void AudioPlayer::next()
{
    
}

void AudioPlayer::previouse()
{
    
}

void AudioPlayer::loadFolder(const QString &folder_path)
{
    
}

void AudioPlayer::formateTime(qint64 time_ms)
{
    
}

void AudioPlayer::setSource(const QString audio_source)
{
    
}
