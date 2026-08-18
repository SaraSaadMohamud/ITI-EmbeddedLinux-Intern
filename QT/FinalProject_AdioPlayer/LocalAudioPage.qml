import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtQuick.Dialogs
import FinalProject_AdioPlayer

Page{
    id: root


    readonly property real screenSize: Math.min(root.width, root.height)
    readonly property real icons_size: screenSize * 0.45
    readonly property real button_size: screenSize * 0.09
    readonly property real folder_size: screenSize * 0.10
    readonly property real mute_size: screenSize * 0.075

    AudioPlayer{
        id: media_player
    }

    /*Component.onCompleted: {
        media_player.loadUSB()
    }*/

    Rectangle
    {
        anchors.fill: parent
        color: "black"
        Image {
            id: backgroundPattern
            source: "images/localPage.png"
            anchors.fill: parent
            opacity: 0.7
        }

        Image {
            id: backButton

            source: "images/return.png"

            width: 45
            height: 45

            anchors.left: parent.left
            anchors.top: parent.top

            anchors.leftMargin: 20
            anchors.topMargin: 20

            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent

                onClicked: {
                        root.StackView.view.pop()
                }
            }
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
                    spacing: root.width * 0.010

                    // App ICon Image
                    Image{
                        id:adioPlayerImage
                        source: "images/localAudioPlayer.png"
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
                            text:  media_player.audio_title
                            //font.bold: true
                            font.pixelSize: 25
                            color: "#FFFFFF"
                            wrapMode: Text.Wrap
                        }

                        //Audio Author
                        Text{
                            id: audioAuthorID
                            visible: true
                            text: media_player.audio_author
                            font.bold: false
                            font.pixelSize: 22
                            color: "#B2EBF2"
                            wrapMode: Text.Wrap
                        }

                        //Audio Type
                        Text{
                            id: audioGenreID
                            visible: true
                            text: media_player.audio_genre
                            font.bold: false
                            font.pixelSize: 18
                           color: "#546E7A"
                        }

                        Text{
                            id: aduioAlbumID
                            visible: true
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
                        font.bold: false
                        color: "white"
                    }

                    //Aduio Progress
                    Slider {
                        id: audioProgress

                        Layout.fillWidth: true
                        from: 0
                        to: media_player.duration
                        value: media_player.position
                        onMoved: {
                            media_player.position = value
                        }
                    }

                    //Remainng time
                    Text{
                        id: remainingTimeID
                        visible: true
                        text: media_player.formateTime( (media_player.duration) - (media_player.position))
                        font.pixelSize: 15
                        font.bold: false
                        color: "white"
                    }
                }

                Item {
                    id: controlsContainer

                    Layout.fillWidth: true
                    Layout.preferredHeight: root.button_size + 30

                    Image {
                        id: audioSOurceID

                        source: "images/folderUplode.png"

                        width: root.folder_size
                        height: root.folder_size

                        anchors.right: mainControls.left
                        anchors.rightMargin: 30
                        anchors.verticalCenter: mainControls.verticalCenter

                        fillMode: Image.PreserveAspectFit

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                folderDialogID.open()
                            }
                        }
                    }

                    Row {
                        id: mainControls

                        anchors.centerIn: parent

                        spacing: Math.max(
                            12,
                            root.screenSize * 0.025
                        )


                        // =========================
                        // Previous
                        // =========================

                        Image {
                            id: prevousAudioID

                            source: "images/privous.png"

                            width: root.button_size
                            height: root.button_size

                            fillMode: Image.PreserveAspectFit

                            MouseArea {
                                anchors.fill: parent

                                onClicked: {
                                    media_player.previouse()
                                }
                            }
                        }

                        // =========================
                        // Play / Pause
                        // =========================

                        Image {
                            id: playPauseAudioID

                            source: media_player.playing_state
                                    ? "images/pause.png"
                                    : "images/play.png"

                            width: root.button_size
                            height: root.button_size

                            fillMode: Image.PreserveAspectFit

                            MouseArea {
                                anchors.fill: parent

                                onClicked: {
                                    media_player.playPause()
                                }
                            }
                        }


                        // =========================
                        // Stop
                        // =========================

                        Image {
                            id: stopAudioID

                            source: "images/stop.png"

                            width: root.button_size
                            height: root.button_size

                            fillMode: Image.PreserveAspectFit

                            MouseArea {
                                anchors.fill: parent

                                onClicked: {
                                    media_player.stop()
                                }
                            }
                        }


                        // =========================
                        // Next
                        // =========================

                        Image {
                            id: nextAudioID

                            source: "images/Next.png"

                            width: root.button_size
                            height: root.button_size

                            fillMode: Image.PreserveAspectFit

                            MouseArea {
                                anchors.fill: parent

                                onClicked: {
                                    media_player.next()
                                }
                            }
                        }
                    }

                    // =====================================================
                    // VOLUME
                    // Completely independent from mainControls
                    // =====================================================

                    Row {
                        id: volumeContainer

                        anchors.left: mainControls.right
                        anchors.leftMargin: 30
                        anchors.verticalCenter: mainControls.verticalCenter

                        spacing: 8

                        // Mute
                        Image {
                            id: mutedUnmutedAudioID

                            source: media_player.volume === 0
                                    ? "images/muted.png"
                                    : media_player.muted
                                      ? "images/muted.png"
                                      : "images/unmuted.png"

                            width: root.mute_size
                            height: root.mute_size

                            fillMode: Image.PreserveAspectFit

                            // مهم جدًا
                            anchors.verticalCenter: parent.verticalCenter

                            MouseArea {
                                anchors.fill: parent

                                onClicked: {
                                    media_player.muted =
                                            !media_player.muted
                                }
                            }
                        }

                        // Volume Slider
                        Slider {
                            id: volumeProgress

                            width: Math.max(
                                80,
                                Math.min(140,root.screenSize * 0.20 )
                            )
                            height: 40
                            from: 0
                            to: 1
                            value: media_player.volume

                            anchors.verticalCenter: parent.verticalCenter
                            onMoved: {
                                media_player.volume = value
                            }
                        }

                        // Volume %
                        Text {
                            id: volumeLevelID

                            text: Math.round(media_player.volume * 100) + " %"

                            font.pixelSize: 14
                            color: "white"
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }


                    // =====================================================
                    // Folder Dialog
                    // =====================================================

                    FolderDialog {
                        id: folderDialogID

                        onAccepted: {
                            media_player.loadFolder(selectedFolder)
                        }
                    }
                }
        }
    }

}