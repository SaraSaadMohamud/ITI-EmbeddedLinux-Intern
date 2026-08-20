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

    // USB Property
    Q_PROPERTY(bool usb_connect         READ getUSBConnection  NOTIFY usbConnectionChanged FINAL)
    Q_PROPERTY(QString usb_path         READ getUSBPath        NOTIFY usbPathChanged       FINAL)
    Q_PROPERTY(QStringList  usb_devices READ getUSSBDevices    NOTIFY usbDevicesChanged    FINAL)

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

    // Meta Data Getters
    QString getAudioTitle() const;
    QString getAudioAuthor() const;
    QString getAudioGenre() const;
    QString getAudioALbum() const;
    QString geterrorstring() const;

    // USB Getters
    bool getUSBConnection() const;
    QString getUSBPath() const;
    QStringList getUSSBDevices() const;

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

    // USB COntrol Method
    Q_INVOKABLE void scanUSB();
    Q_INVOKABLE void loadUSB(const QString &usbPath);
    Q_INVOKABLE void playSelected(int index);
    Q_INVOKABLE void clearUSB();

    // Bluetooth 
    Q_INVOKABLE void playBluetoothFile(const QString &filePath);

    /*************************************************************************/

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

    // USB Signals
    void usbConnectionChanged();
    void usbPathChanged();
    void usbDevicesChanged();

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

    // USB
    bool m_usb_connected = false;
    QString m_usb_path;
    QStringList m_usb_devices;

    void setSource(const QString audio_source);
};

#endif // AUDIOPLAYER_H