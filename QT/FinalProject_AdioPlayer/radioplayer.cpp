#include "radioplayer.h"
#include "loggin.h"
#include <QDebug>
#include <QLoggingCategory>

RadioPlayer::RadioPlayer(QObject *parent) : QObject{parent}
{
    m_media_player = new QMediaPlayer(this);
    m_audio_output = new QAudioOutput(this);

    m_media_player->setAudioOutput(m_audio_output);
    m_audio_output->setVolume(0.5);

    // Connect QMediaPlayer & QAudioOutpue signals  with my media/audio signals
    connect(m_media_player,&QMediaPlayer::playingChanged ,this,&RadioPlayer::radioPlayingStateChanged);
    connect(m_audio_output,&QAudioOutput::mutedChanged   ,this,&RadioPlayer::radioMuteStateChanged);
    connect(m_audio_output,&QAudioOutput::volumeChanged  ,this,&RadioPlayer::radioVolumeChanged);

    // Error Handling
    connect(m_media_player, &QMediaPlayer::errorOccurred, this, [this](QMediaPlayer::Error err){
        if(err !=QMediaPlayer::NoError){
            m_error_string = m_media_player->errorString();
            qCWarning(mediaPlayer) <<"Playback Error: "<<m_error_string;
            emit radioErrorOccured();
        }
    });

    // Radio

    m_radio_station = {
                        QVariantMap{
                            {"name", "Cairo Radio Station"},
                            {"country","🇪🇬 EGYPT"},
                            {"url","http://n12.radiojar.com/8s5u5tpdtwzuv"}
                        },

                        QVariantMap{
                            {"name", "Maka Radio Station"},
                            {"country","🇸🇦 Saudi Arabia"},
                            {"url","https://edge.mixlr.com/channel/rwumx"}
                        },

                        QVariantMap{
                            {"name", "Kuwait Radio Station"},
                            {"country", "🇰🇼 Kuwait1"},
                            {"url", "https://radio.mp3islam.com/listen/quran_radio/radio.mp3"}
                        },

                        QVariantMap{
                            {"name", "Morocco Radio Station"},
                            {"country", "🇲🇦 Morocco"},
                            {"url", "http://stream.radiojar.com/0tpy1h0kxtzuv"}
                        },
                        
                        QVariantMap{
                            {"name", "Jordan Quran Radio"},
                            {"country", "🇯🇴 Jordan"},
                            {"url", "https://jrtv-live.ercdn.net/jrradio/quranradio.m3u8"}
                        },

                       /* QVariantMap{
                            {"name", "Kuwait Radio Station"},
                            {"country", "🇰🇼 Kuwait2"},
                            {"url", "https://radio.mp3islam.com/listen/abdulbasit/radio.mp3"}
                        },*/

                        QVariantMap{
                            {"name", "Zitouna Quran Radio"},
                            {"country", "🇹🇳 Tunisia"},
                            {"url", "https://radio.radiotunisienne.tn/radiozaitouna"}
                        },
                };

    emit radioStationsChanged();
}

/*********************************************************************************************************************/

void RadioPlayer::playRadioStation(qint64 radio_station_index)
{
    if( ( radio_station_index < 0 ) || ( radio_station_index >= m_radio_station.size() ))
    {
        qCWarning(mediaPlayer)<<"Invalid radio station Index!";
        return;
    }

    m_current_station_index = radio_station_index;
    QVariantMap radion_station = m_radio_station[m_current_station_index].toMap();
    m_current_station_name = radion_station.value("name").toString();

    QString radio_src = radion_station.value("url").toString();
    setSource(radio_src);

    emit currentRadioStationChanged();
    emit currentRadioStationIndexChanged();

    m_media_player->play();
    qCInfo(mediaPlayer) <<"Tunning to Station: "<<m_current_station_name;
}

void RadioPlayer::toggleRadioPlayback()
{
    if (m_media_player->isPlaying())
    {
        m_media_player->pause();
    }
    else
    {
        m_media_player->play();
    }
}

void RadioPlayer::stopRadioStation()
{
    m_media_player->stop();
    emit radioPlayingStateChanged();
}

void RadioPlayer::previousRadioStation()
{
    if(m_radio_station.isEmpty())
    {
        qCWarning(mediaPlayer)<<"No Station Avalible, Station List is Empty!";
        return;
    }
    m_current_station_index =( ( (m_current_station_index - 1) + m_radio_station.size() ) % m_radio_station.size() );
    playRadioStation(m_current_station_index);
}

void RadioPlayer::nextRadioStation()
{
    if(m_radio_station.isEmpty())
    {
        qCWarning(mediaPlayer)<<"No Station Avalible, Station List is Empty!";
        return;
    }

    m_current_station_index =( (m_current_station_index + 1) % m_radio_station.size() );
    playRadioStation(m_current_station_index);
}

void RadioPlayer::addRadioStation(const QString &name, const QString &country, const QString &url)
{
    if (name.trimmed().isEmpty() || country.trimmed().isEmpty() || url.trimmed().isEmpty())
    {
        qCWarning(mediaPlayer) << "Cannot add radio station: empty data.";
        return;
    }

    QVariantMap station;

    station["name"] = name.trimmed();
    station["country"] = country.trimmed();
    station["url"] = url.trimmed();
    m_radio_station.append(station);

    emit radioStationsChanged();
    qCInfo(mediaPlayer)<< "Radio station added:" << name << country << url;
}

/*void RadioPlayer::removeRadioStation(const QString &radio_url)
{
    for (int i = 0; i < m_radio_station.size(); ++i)
    {
        QVariantMap station = m_radio_station[i].toMap();

        if (station.value("url").toString() == radio_url)
        {
            QString stationName = station.value("name").toString();

            // remove station is the current station
            if (i == m_current_station_index)
            {
                stopRadioStation();

                m_current_station_index = -1;
                m_current_station_name.clear();

                emit currentRadioStationChanged();
                emit currentRadioStationIndexChanged();
            }
            // remove not the current station
            else if (i < m_current_station_index)
            {
                --m_current_station_index;
                emit currentRadioStationIndexChanged();
            }

            m_radio_station.removeAt(i);
            emit radioStationsChanged();

            qCInfo(mediaPlayer) << "Radio station removed:" << stationName;

            return;
        }
    }

    qCWarning(mediaPlayer)<< "Radio station not found:" << radio_url;
}*/

QVariantList RadioPlayer::getRadioStation() const
{
    return m_radio_station;
}

QString RadioPlayer::getCurrentRadioStation() const
{
    return m_current_station_name;
}

qint64 RadioPlayer::getCurrentRadioStationIndex() const
{
    return m_current_station_index;
}

bool RadioPlayer::getRadioPlayingState() const
{
    return m_media_player->isPlaying();
}

bool RadioPlayer::getRadioMuteState() const
{
    return m_audio_output->isMuted();
}

float RadioPlayer::getRadioVolume() const
{
    return m_audio_output->volume();
}

QString RadioPlayer::getRadioErrorString() const
{
    return m_error_string;
}

void RadioPlayer::setRadioMuteState(bool position)
{
    m_audio_output->setMuted(position);
}

void RadioPlayer::setRadioVolume(float position)
{
    m_audio_output->setVolume( qBound(0.0f,position,1.0f) );
}

void RadioPlayer::setSource(const QString &radio_source)
{
    m_media_player->stop();
    m_media_player->setSource(QUrl(radio_source));
}
