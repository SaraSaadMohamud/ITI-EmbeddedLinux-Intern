#ifndef RADIOPLAYER_H
#define RADIOPLAYER_H

#include <QObject>
#include <QtQml/qqml.h>
#include <QMediaPlayer>
#include<QAudioOutput>

class RadioPlayer : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    // Coring Proberties
    Q_PROPERTY(bool playing_state   READ getRadioPlayingState      NOTIFY radioPlayingStateChanged FINAL)

    // Audio Control Properties
    Q_PROPERTY(bool muted   READ getRadioMuteState         WRITE setRadioMuteState NOTIFY radioMuteStateChanged FINAL)
    Q_PROPERTY(float volume READ getRadioVolume            WRITE setRadioVolume    NOTIFY radioVolumeChanged    FINAL)

    // Radio Property
    Q_PROPERTY(QVariantList radio_station           READ getRadioStation             NOTIFY radioStationsChanged              FINAL)
    Q_PROPERTY(QString current_radio_station        READ getCurrentRadioStation      NOTIFY currentRadioStationChanged        FINAL)
    Q_PROPERTY(qint64 current_radio_station_index   READ getCurrentRadioStationIndex NOTIFY currentRadioStationIndexChanged   FINAL)
    Q_PROPERTY(QString error_string                 READ getRadioErrorString         NOTIFY radioErrorOccured                 FINAL)

public:
    explicit RadioPlayer(QObject *parent = nullptr);

    //Radio Getters
    bool getRadioPlayingState() const;
    bool  getRadioMuteState() const;
    float getRadioVolume() const;

    QVariantList getRadioStation() const;
    QString getCurrentRadioStation() const;
    qint64 getCurrentRadioStationIndex() const;
    QString getRadioErrorString() const;


    // Setters
    void setRadioMuteState(bool position);
    void setRadioVolume(float position);

    // Control Methods
    Q_INVOKABLE void playRadioStation(qint64 radio_station_index);
    Q_INVOKABLE void toggleRadioPlayback();
    Q_INVOKABLE void stopRadioStation();
    Q_INVOKABLE void nextRadioStation();
    Q_INVOKABLE void previousRadioStation();

    /*************************************************************************/

signals:

    void radioPlayingStateChanged();
    void radioMuteStateChanged();
    void radioVolumeChanged();

    // Radio Signals
    void radioStationsChanged();
    void currentRadioStationChanged();
    void currentRadioStationIndexChanged();
    void radioErrorOccured();

private:

    QMediaPlayer* m_media_player;
    QAudioOutput* m_audio_output;

    QVariantList m_radio_station;
    QString m_current_station_name;
    qint64 m_current_station_index = -1;

    QString m_error_string;

    void setSource(const QString &radio_source);
};

#endif // RADIOPLAYER_H