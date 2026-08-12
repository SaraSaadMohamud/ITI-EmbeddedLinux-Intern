#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QtQml/qqml.h>
#include <QMediaPlayer>
#include<QAudioOutput>

class AudioPlayer : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    // Coring Proberties
    Q_PROPERTY(bool playing_state   READ getPlayingState               NOTIFY playingStateChanged FINAL)
    Q_PROPERTY(qint64 position      READ getPosition WRITE setPosition NOTIFY positionChanged     FINAL)
    Q_PROPERTY(qint64 duration      READ getDuration                   NOTIFY durationChanged     FINAL)

    // Audio Control Properties
    Q_PROPERTY(bool muted   READ getMuteState WRITE setMuteState NOTIFY muteStateChanged FINAL)
    Q_PROPERTY(float volume READ getvolume    WRITE setVolume    NOTIFY volumeChanged    FINAL)

    // Local PlayList
    Q_PROPERTY(QStringList playing_list      READ getPlayingList         NOTIFY playListChanged             FINAL)
    Q_PROPERTY(qint64 current_playlist_index READ getCurrentPlayingIndex NOTIFY currentPlayListIndexChanged FINAL)

    // Audio MetaDate
    Q_PROPERTY(QString audio_title        READ getAudioTitle    NOTIFY metaDataChanged FINAL)
    Q_PROPERTY(QString audio_author       READ getAudioAuthor   NOTIFY metaDataChanged FINAL)
    Q_PROPERTY(QString audio_genre        READ getAudioGenre    NOTIFY metaDataChanged  FINAL)
    Q_PROPERTY(QString audio_album        READ getAudioALbum    NOTIFY metaDataChanged  FINAL)
    Q_PROPERTY(QString error_string       READ geterrorstring   NOTIFY errorOccured     FINAL)

    /* *******************************************************************************************************************/
    // Radio Property
    Q_PROPERTY(bool is_radio_mode READ getRadioMode  NOTIFY radioModeChanged FINAL)
    Q_PROPERTY(QVariantList radio_station READ getRadioStation NOTIFY radioStationChanged FINAL)
    Q_PROPERTY(QString current_radio_station READ getCurrentRadioStation NOTIFY currentRadioStationChanged FINAL)
    َQ_PROPERTY(bool radio_check_connecting READ getCheckConnectingState NOTIFY radioConnectingStateChanged FINAL)

public:
    explicit AudioPlayer(QObject *parent = nullptr);

    // Getters
    bool getPlayingState() const;
    qint64 getPosition() const;
    qint64 getDuration() const;

    bool getMuteState() const;
    float  getvolume() const;

    QStringList getPlayingList() const;
    qint64 getCurrentPlayingIndex() const;

    QString getAudioTitle() const;
    QString getAudioAuthor() const;
    QString getAudioGenre() const;
    QString getAudioALbum() const;
    QString geterrorstring() const;

    // Setters
    void setPosition(qint64 position);
    void setMuteState(bool position);
    void setVolume(float position);

    // Control Methods
    Q_INVOKABLE void playPause();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void next();
    Q_INVOKABLE void previouse();
    Q_INVOKABLE void loadFolder(const QString &folder_path);
    Q_INVOKABLE QString formateTime(qint64 time_ms);

    /*************************************************************************/
    //Radio Getters
    bool getRadioMode() const;
    QVariantList getRadioStation() const;
    QString getCurrentRadioStation() const;
    bool getCheckConnectingState() const;

signals:
    void playingStateChanged();
    void positionChanged();
    void durationChanged();
    void muteStateChanged();
    void volumeChanged();
    void playListChanged();
    void currentPlayListIndexChanged();
    void metaDataChanged();
    void errorOccured();

    // Radio Signals
    void radioModeChanged ();
    void radioStationChanged();
    void currentRadioStationChanged();
    void radioConnectingStateChanged();

private:
    QMediaPlayer* m_media_player;
    QAudioOutput* m_audio_output;

    QStringList m_play_list;
    qint64 m_current_playlist_index = -1;

    QString m_audio_title;
    QString m_audio_author;
    QString m_audio_genre;
    QString m_audio_album;
    QString m_error_string;

    void setSource(const QString audio_source);

};

#endif // AUDIOPLAYER_H
