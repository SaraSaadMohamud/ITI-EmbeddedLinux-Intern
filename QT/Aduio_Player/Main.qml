import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtQuick.Dialogs

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
    readonly property real mute_size: root.width * 0.035


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
                    text: qsTr("Audio Player")
                    font.bold: true
                    font.pixelSize: 30
                    color: "#24bfb5"
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

                            text: qsTr("Surah Taha")
                            font.bold: true
                            font.pixelSize: 30
                            color: "#FFFFFF"
                            wrapMode: Text.Wrap
                        }

                        //Audio Author
                        Text{
                            id: aduioAuthorID
                            text: qsTr("Ahmed Al-Nafis")
                            font.bold: false
                            font.pixelSize: 22
                            color: "#B2EBF2"
                            wrapMode: Text.Wrap
                        }

                        //Audio Type
                        Text{
                            id: appTypeID
                            Layout.alignment: Qt.AlignHCenter
                            text: qsTr("Quran")
                            font.bold: false
                            font.pixelSize: 18
                           color: "#546E7A"
                        }

                    }

                }

                // Second Raw Duration, Slider
                RowLayout{
                    id: durationAduioSlider
                    Layout.leftMargin: 25
                    Layout.rightMargin: 25
                    spacing: 10

                    // Elapsed Aduio Time
                    Text{
                        id: elapsedTimeID
                        text: qsTr("00:00")
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
                        to:1
                        value: 0.5

                        onMoved: {

                        }
                    }

                    //Remainng time
                    Text{
                        id: remainingTimeID
                        text: qsTr("00:00")
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

                            }
                        }
                    }

                    // Play, Pause Audio
                    Image{
                        id: playPauseAudioID
                        source: "imags/pause.png"
                        Layout.preferredWidth: root.button_size
                        Layout.preferredHeight: root.button_size
                        fillMode: Image.PreserveAspectFit

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {

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
                        // muted/ unmuted Audio
                        Image{
                            id: mutedUnmutedAudioID
                            source: "imags/unmuted.png"
                            Layout.preferredWidth: root.mute_size
                            Layout.preferredHeight: root.mute_size
                            fillMode: Image.PreserveAspectFit

                            MouseArea{
                                anchors.fill: parent
                                onClicked: {

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
                            value: 0.5

                            onMoved: {

                            }
                        }

                        Text{
                            id: volumeLevelID
                            text: qsTr("50%")
                            font.pixelSize: 14
                            font.bold: false
                            color: "white"
                        }

                    }

                }

        }
    }

}
