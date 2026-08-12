import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtQuick.Dialogs
import Aduio_Player

ApplicationWindow {
    id: root
    width: 800
    height: 480
    visible: true
    title: qsTr("Audio Player")

    Material.accent: "#24BFB5"
    Material.theme: Material.Dark

    readonly property real icons_size: root.width * 0.2
    readonly property real button_size: root.width * 0.06
    readonly property real mute_size: root.width * 0.049

    AudioPlayer{
        id: media_player
    }

    Rectangle
    {
        anchors.fill: parent
        color: "#050708"

        Image {
            id: backgroundPattern
            source: "imags/background.png"
            fillMode: Image.Tile
            anchors.fill: parent
            opacity: 0.05
        }

        //Main Window That include Whole Blocks
        ColumnLayout{

                id: bigCountener
                anchors.fill : parent

                // App Title
                Text{
                    id: appTitle
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 100
                    text: qsTr("Audio Player")
                    font.bold: true
                    font.pixelSize: 30
                    color: "#B2EBF2"
                }

                // First Row include AppIcon, MetaData
                RowLayout{

                    id: appIconMataData
                    Layout.alignment: Qt.AlignHCenter
                    spacing: root.width * 0.025

                    // App ICon Image
                    Image{
                        id:adioPlayerImage
                        source: "imags/AduioPlayer.png"
                        fillMode: Image.PreserveAspectFit
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: root.icons_size
                        Layout.preferredHeight: root.icons_size
                        smooth: true
                        mipmap: true
                    }

                    // Meta Data
                    ColumnLayout{

                        id: aduioMetaData
                        Layout.alignment: Qt.AlignVCenter
                        spacing: 10

                        // Audio Title
                        Text{
                            id: aduioTitleID
                            text: media_player.audio_title
                            //font.bold: true
                            font.pixelSize: 25
                            color: "#FFFFFF"
                            wrapMode: Text.Wrap
                        }

                        //Audio Author
                        Text{
                            id: audioAuthorID
                            text: media_player.audio_author
                            font.bold: false
                            font.pixelSize: 22
                            color: "#B2EBF2"
                            wrapMode: Text.Wrap
                        }

                        //Audio Type
                        Text{
                            id: audioGenreID
                            text: media_player.audio_genre
                            font.bold: false
                            font.pixelSize: 18
                           color: "#546E7A"
                        }

                        Text{
                            id: aduioAlbumID
                            text: media_player.audio_album
                            font.bold: true
                            font.pixelSize: 15
                            color: "#B2EBF2"
                            wrapMode: Text.Wrap
                        }

                    }

                }

                // Second Raw Duration, Slider
                RowLayout{
                    id: durationAduioSlider
                    Layout.leftMargin: 25
                    Layout.rightMargin: 25
                    spacing: 8

                    // Elapsed Aduio Time
                    Text{
                        id: elapsedTimeID
                        text: media_player.formateTime((media_player.position))
                        font.pixelSize: 15
                        font.bold: fale
                        color: "white"
                    }

                    //Aduio Progress
                    Slider{
                        id: audioProgress
                        enabled: true
                        Layout.fillWidth: true
                        from:0
                        to:media_player.duration
                        value: media_player.position

                        onMoved: {
                            media_player.position = value
                        }
                    }

                    //Remainng time
                    Text{
                        id: remainingTimeID
                        text: media_player.formateTime( (media_player.duration) - (media_player.position))
                        font.pixelSize: 15
                        font.bold: fale
                        color: "white"
                    }
                }

                RowLayout{
                    id: controlBtnsId
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter
                    Layout.leftMargin: 25
                    Layout.rightMargin: 25
                    spacing:25

                    FolderDialog{
                        id:folderDialogID
                        onAccepted: {
                            media_player.loadFolder(selectedFolder)
                        }
                    }

                    // Audio sources
                    Image{
                        id: audioSOurceID
                        source: "imags/folderUplode.png"
                        Layout.preferredWidth: root.button_size
                        Layout.preferredHeight: root.button_size
                        fillMode: Image.PreserveAspectFit

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                folderDialogID.open()
                            }
                        }
                    }

                    // Radio sources
                    Image{
                        id: radioSOurceID
                        source: "imags/radioUplode.png"
                        Layout.preferredWidth: root.button_size
                        Layout.preferredHeight: root.button_size
                        fillMode: Image.PreserveAspectFit

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }

                    // Spacer
                    Item {
                        id: spacer1
                        implicitWidth: 60
                    }

                    // Previous Audio
                    Image{
                        id: prevousAudioID
                        source: "imags/privous.png"
                        Layout.preferredWidth: root.button_size
                        Layout.preferredHeight: root.button_size
                        fillMode: Image.PreserveAspectFit

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                media_player.previouse()
                            }
                        }
                    }

                    // Play, Pause Audio
                    Image{
                        id: playPauseAudioID
                        source: media_player.playing_state?
                               "imags/pause.png": "imags/play.png"
                        Layout.preferredWidth: root.button_size
                        Layout.preferredHeight: root.button_size
                        fillMode: Image.PreserveAspectFit

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                media_player.playPause()
                            }
                        }
                    }

                    // stop Audio
                    Image{
                        id: stopAudioID
                        source: "imags/stop.png"
                        Layout.preferredWidth: root.button_size
                        Layout.preferredHeight: root.button_size
                        fillMode: Image.PreserveAspectFit

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                media_player.stop()
                            }
                        }
                    }

                    // Next Audio
                    Image{
                        id: nextAudioID
                        source: "imags/Next.png"
                        Layout.preferredWidth: root.button_size
                        Layout.preferredHeight: root.button_size
                        fillMode: Image.PreserveAspectFit

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                media_player.next()
                            }
                        }
                    }

                    // Spacer
                    Item {
                        id: spacer2
                        implicitWidth: 40
                    }

                    RowLayout
                    {
                        Layout.rightMargin: 25
                        // muted/ unmuted Audio
                        Image{
                            id: mutedUnmutedAudioID
                            source:  if(media_player.volume === 0) "imags/muted.png"
                                     else  media_player.muted?"imags/muted.png": "imags/unmuted.png"
                            Layout.preferredWidth: root.mute_size
                            Layout.preferredHeight: root.mute_size
                            fillMode: Image.PreserveAspectFit

                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    media_player.muted=!media_player.muted
                                }
                            }
                        }

                        //Aduio Progress
                        Slider{
                            id: volumeProgress
                            enabled: true
                            Layout.fillWidth: true
                            Layout.minimumWidth: 100
                            Layout.maximumWidth: 400
                            from:0
                            to:1
                            value: media_player.volume

                            onMoved: {
                                media_player.volume = value
                            }
                        }

                        Text{
                            id: volumeLevelID
                            text: Math.round(media_player.volume * 100) + " %"
                            font.pixelSize: 14
                            font.bold: false
                            color: "white"
                        }

                    }

                }

        }
    }

}
