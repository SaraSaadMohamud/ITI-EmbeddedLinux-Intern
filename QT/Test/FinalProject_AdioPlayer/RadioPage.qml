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

    RadioPlayer{
        id: media_player
    }

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
                    Layout.topMargin: 70
                    text: qsTr("Radio Player")
                    font.bold: true
                    font.pixelSize: 30
                    color: "#B2EBF2"
                }

                // App ICon Image
                Image{
                    id:adioPlayerImage
                    source: "images/radioPlayer.png"
                    fillMode: Image.PreserveAspectFit
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.preferredWidth: root.icons_size
                    Layout.preferredHeight: root.icons_size
                    smooth: true
                    mipmap: true
                }
                Text{
                    id: radioStationTitleID
                    Layout.alignment: Qt.AlignHCenter
                    text: media_player.current_radio_station
                    //font.bold: true
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    wrapMode: Text.Wrap
                }

                // Second Raw  Slider
                RowLayout {
                    id: liveStatus

                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 10
                    spacing: 8

                    Text {
                        id: radioLiveID

                        text: "🔵 LIVE"
                        font.pixelSize: 15
                        font.bold: true
                        color: "#B2EBF2"
                    }
                }

                Item {
                    id: controlsContainer

                    Layout.fillWidth: true
                    Layout.preferredHeight: root.button_size + 30

                    Image {
                        id: radioSOurceID

                        source: "images/radio_connect.png"

                        width: root.folder_size
                        height: root.folder_size

                        anchors.right: mainControls.left
                        anchors.rightMargin: 30
                        anchors.verticalCenter: mainControls.verticalCenter

                        fillMode: Image.PreserveAspectFit

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                radioStationPopupID.open();
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
                                    media_player.previousRadioStation()
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
                                   media_player.toggleRadioPlayback()
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
                                    media_player.stopRadioStation()
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
                                    media_player.nextRadioStation()
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

                            source: (media_player.muted || media_player.volume === 0)
                                    ? "images/muted.png"
                                    : "images/unmuted.png"

                            width: root.mute_size
                            height: root.mute_size

                            fillMode: Image.PreserveAspectFit
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

                    Popup {
                        id: radioStationPopupID

                        anchors.centerIn: Overlay.overlay

                        width: 340
                        height: 360

                        modal: true
                        focus: true

                        background: Rectangle {
                            color: "#15191B"
                            radius: 15
                            border.color: "#24BFB5"
                            border.width: 1
                        }

                        contentItem: ColumnLayout {
                            spacing: 0

                            // =========================
                            // Popup Title
                            // =========================
                            Label {
                                text: qsTr("Radio Stations")
                                color: "#B2EBF2"
                                font.bold: true
                                font.pixelSize: 20

                                Layout.fillWidth: true
                                Layout.preferredHeight: 50

                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }

                            // =========================
                            // Stations List
                            // =========================
                            ListView {
                                id: radioStationList

                                Layout.fillWidth: true
                                Layout.fillHeight: true

                                model: media_player.radio_station
                                clip: true
                                spacing: 5

                                delegate: ItemDelegate {

                                    width: radioStationList.width
                                    height: 55

                                    contentItem: RowLayout {
                                        spacing: 10

                                        Text {
                                            Layout.fillWidth: true
                                            text: modelData.name + " - " + modelData.country

                                            color: "white"
                                            font.pixelSize: 14

                                            elide: Text.ElideRight
                                        }

                                        /*Button {
                                            text: qsTr("Remove")

                                            onClicked: {
                                                media_player.removeRadioStation(modelData.url)
                                            }
                                        }*/
                                    }

                                    background: Rectangle {
                                        radius: 8
                                        color: parent.hovered ? "#263B3D" : "transparent"
                                    }

                                    onClicked: {
                                        media_player.playRadioStation(index)
                                        radioStationPopupID.close()
                                    }
                                }

                                // =========================
                                // Vertical Scroll Bar
                                // =========================
                                ScrollBar.vertical: ScrollBar {
                                    policy: ScrollBar.AsNeeded

                                    width: 8

                                    contentItem: Rectangle {
                                        implicitWidth: 8
                                        radius: 4
                                        color: "#24BFB5"
                                    }

                                    background: Rectangle {
                                        implicitWidth: 8
                                        radius: 4
                                        color: "#303638"
                                    }
                                }
                            }

                            Button {
                                id: addStationButton

                                text: qsTr("+ Add Radio Station")

                                Layout.fillWidth: true
                                Layout.preferredHeight: 45
                                Layout.leftMargin: 15
                                Layout.rightMargin: 15
                                Layout.bottomMargin: 10

                                onClicked: {
                                    radioStationPopupID.close()
                                    addStationPopup.open()
                                }
                            }
                        }
                    }

                    Popup {
                        id: addStationPopup

                        anchors.centerIn: Overlay.overlay

                        width: 350
                        height: 350
                        modal: true
                        focus: true

                        background: Rectangle {
                            color: "#15191B"

                            radius: 15
                            border.color: "#24BFB5"
                            border.width: 1
                        }

                        contentItem: ColumnLayout {
                            spacing: 12
                            Label {
                                text: qsTr("Add Radio Station")

                                color: "#B2EBF2"
                                font.bold: true
                                font.pixelSize: 20

                                Layout.fillWidth: true
                                Layout.preferredHeight: 45
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }

                            TextField {
                                id: stationNameField

                                placeholderText: qsTr("Station Name")

                                Layout.fillWidth: true
                                Layout.leftMargin: 20
                                Layout.rightMargin: 20
                            }

                            TextField {
                                id: stationCountryField

                                placeholderText: qsTr("Country")

                                Layout.fillWidth: true
                                Layout.leftMargin: 20
                                Layout.rightMargin: 20
                            }

                            TextField {
                                id: stationUrlField

                                placeholderText: qsTr("Stream URL")

                                Layout.fillWidth: true
                                Layout.leftMargin: 20
                                Layout.rightMargin: 20
                            }

                            RowLayout {

                                Layout.fillWidth: true
                                Layout.leftMargin: 20
                                Layout.rightMargin: 20

                                spacing: 10

                                Button {
                                    id: cancelButton

                                    text: qsTr("Cancel")

                                    Layout.fillWidth: true
                                    contentItem: Text {
                                        text: cancelButton.text

                                        color: "#FFFFFF"
                                        font.pixelSize: 15
                                        font.bold: true

                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                    }

                                    background: Rectangle {
                                        radius: 8

                                        color: cancelButton.pressed ? "#37474F" : cancelButton.hovered ? "#455A64" : "#263238"

                                        border.width: 1
                                        border.color: "#546E7A"

                                        Behavior on color {
                                            ColorAnimation {
                                                duration: 120
                                            }
                                        }
                                    }

                                    onClicked: {
                                        addStationPopup.close()
                                    }
                                }

                                Button {
                                    id: addButton

                                    Layout.fillWidth: true

                                    text: qsTr("Add")

                                    enabled: stationNameField.text.trim() !== "" && stationCountryField.text.trim() !== "" &&
                                            stationUrlField.text.trim() !== ""

                                    contentItem: Text {
                                        text: addButton.text

                                        color: addButton.enabled ? "#FFFFFF" : "#607D80"

                                        font.pixelSize: 15
                                        font.bold: true

                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                    }

                                    background: Rectangle {
                                        radius: 8

                                        color: !addButton.enabled ? "#263238" : addButton.pressed ? "#168F89" : addButton.hovered
                                                ? "#24BFB5" : "#1B7F7A"

                                        border.width: 1
                                        border.color: "#24BFB5"

                                        Behavior on color {
                                            ColorAnimation {
                                                duration: 120
                                            }
                                        }
                                    }

                                    onClicked: {
                                        media_player.addRadioStation(
                                            stationNameField.text,
                                            stationCountryField.text,
                                            stationUrlField.text
                                        )

                                        stationNameField.clear()
                                        stationCountryField.clear()
                                        stationUrlField.clear()

                                        addStationPopup.close()
                                    }
                                }
                            }
                        }
                    }
                }
        }
    }

}