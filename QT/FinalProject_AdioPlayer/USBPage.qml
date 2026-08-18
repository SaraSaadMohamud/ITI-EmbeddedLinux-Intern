import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import FinalProject_AdioPlayer

Page {
    id: root

    readonly property real screenSize: Math.min(root.width, root.height)
    readonly property real icons_size: screenSize * 0.45
    readonly property real button_size: screenSize * 0.09
    readonly property real usb_size: screenSize * 0.10
    readonly property real mute_size: screenSize * 0.075

    AudioPlayer {
        id: media_player
    }

    Timer {
        id: usbScanTimer

        interval: 300
        repeat: true
        running: true

        onTriggered: {
            var wasConnected = media_player.usb_connect
            media_player.scanUSB()

            // USB was disconnected
            if (wasConnected && !media_player.usb_connect) {
                console.log("USB disconnected")
                media_player.stop()
                media_player.clearUSB()
                usbDevicesPopup.close()
                usbFilesPopup.close()
            }

            // USB was connected
            if (!wasConnected && media_player.usb_connect) {
                console.log("USB detected")
                // Show USB selection popup
                usbDevicesPopup.open()
            }
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "black"

        Image {
            id: backgroundPattern

            source: "images/localPage.png"
            anchors.fill: parent
            opacity: 0.7
            fillMode: Image.PreserveAspectCrop
        }

        // =====================================================
        // Back Button
        // =====================================================

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

        // =====================================================
        // Main Container
        // =====================================================
        ColumnLayout {
            id: bigContainer
            anchors.fill: parent

            // =================================================
            // Application Title
            // =================================================
            Text {
                id: appTitle

                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 75

                text: qsTr("USB Audio Player")

                font.bold: true
                font.pixelSize: 30

                color: "#B2EBF2"
            }

            // =================================================
            // USB Status
            // =================================================

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 8

                Text {
                    text: media_player.usb_connect
                          ? "● USB Connected"
                          : "● USB Not Connected"

                    font.pixelSize: 15
                    font.bold: true

                    color: media_player.usb_connect
                           ? "#24BFB5"
                           : "#FF5252"
                }
            }

            // =================================================
            // USB Icon + Metadata
            // =================================================

            RowLayout {
                id: appIconMetaData

                Layout.alignment: Qt.AlignHCenter
                spacing: root.width * 0.005

                // =================================================
                // USB Image
                // =================================================
                Image {
                    id: usbPlayerImage

                    source: "images/USB_page.png"
                    fillMode: Image.PreserveAspectFit

                    Layout.alignment: Qt.AlignVCenter
                    Layout.preferredWidth: root.icons_size
                    Layout.preferredHeight: root.icons_size

                    smooth: true
                    mipmap: true
                }

                // =================================================
                // Audio Metadata
                // =================================================
                ColumnLayout {
                    id: audioMetaData

                    Layout.alignment: Qt.AlignVCenter
                    spacing: 10

                    // =================================================
                    // Current File
                    // =================================================
                    Text {
                        id: audioTitleID

                        text: {
                            if (media_player.current_playing_index < 0)
                            {
                                return "No Audio Selected"
                            }
                            if (media_player.audio_title !== "")
                            {
                                return media_player.audio_title
                            }
                            return getCurrentFileName()
                        }

                        font.pixelSize: 25
                        font.bold: false
                        color: "#FFFFFF"
                        wrapMode: Text.Wrap // fit Long Lines to multi line
                        Layout.maximumWidth: root.width * 0.40
                    }

                    // =================================================
                    // Author
                    // =================================================

                    Text {
                        id: audioAuthorID

                        text: media_player.current_playing_index >= 0 ? media_player.audio_author : ""
                        font.pixelSize: 22
                        color: "#B2EBF2"
                        wrapMode: Text.Wrap
                    }

                    // =================================================
                    // Genre
                    // =================================================
                    Text {
                        id: audioGenreID

                        text: media_player.current_playing_index >= 0 ? media_player.audio_genre : ""
                        font.pixelSize: 18
                        color: "#546E7A"
                    }

                    // =================================================
                    // Album
                    // =================================================

                    Text {
                        id: audioAlbumID

                        text: media_player.current_playing_index >= 0 ? media_player.audio_album : ""

                        font.pixelSize: 15
                        font.bold: true
                        color: "#B2EBF2"
                        wrapMode: Text.Wrap
                    }
                }
            }

            // =====================================================
            // Duration + Progress Slider
            // =====================================================
            RowLayout {
                id: durationAudioSlider

                Layout.leftMargin: 25
                Layout.rightMargin: 25
                spacing: 8

                // Elapsed Time
                Text{
                    id: elapsedTimeID

                    text: media_player.current_playing_index >= 0
                        ? media_player.formateTime(media_player.position) : "00:00"

                    font.pixelSize: 15
                    color: "white"
                }

                // Progress
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

                Text{
                    id: remainingTimeID

                    text: media_player.current_playing_index >= 0
                        ? media_player.formateTime(media_player.duration - media_player.position) : "00:00"

                    font.pixelSize: 15
                    color: "white"
                }
            }

            // =====================================================
            // Controls
            // =====================================================
            Item {
                id: controlsContainer

                Layout.fillWidth: true
                Layout.preferredHeight: root.button_size + 30

                // =================================================
                // USB Source Button
                // =================================================
                Image {
                    id: usbSourceID

                    source: "images/USB_btn.png"
                    fillMode: Image.PreserveAspectFit

                    width: root.usb_size
                    height: root.usb_size

                    anchors.right: mainControls.left
                    anchors.rightMargin: 30
                    anchors.verticalCenter: mainControls.verticalCenter

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            // No USB connected
                            if (!media_player.usb_connect) {
                                console.log("No USB connected.")
                                return
                            }

                            // Show USB selection popup
                            if (media_player.usb_devices.length > 0) {
                                usbDevicesPopup.open()
                            } else {
                                console.log("No USB devices found.")
                            }
                        }
                    }
                }

                // =================================================
                // Main Controls
                // =================================================
                Row {
                    id: mainControls

                    anchors.centerIn: parent
                    spacing: Math.max(12, root.screenSize * 0.025 )

                    // =================================================
                    // Previous
                    // =================================================
                    Image {
                        id: previousAudioID

                        source: "images/privous.png"
                        fillMode: Image.PreserveAspectFit

                        width: root.button_size
                        height: root.button_size

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                media_player.previouse()
                            }
                        }
                    }

                    // =================================================
                    // Play / Pause
                    // =================================================
                    Image {
                        id: playPauseAudioID

                        source: media_player.playing_state ? "images/pause.png" : "images/play.png"
                        fillMode: Image.PreserveAspectFit

                        width: root.button_size
                        height: root.button_size

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                media_player.playPause()
                            }
                        }
                    }

                    // =================================================
                    // Stop
                    // =================================================
                    Image {
                        id: stopAudioID

                        source: "images/stop.png"
                        fillMode: Image.PreserveAspectFit

                        width: root.button_size
                        height: root.button_size

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                media_player.stop()
                            }
                        }
                    }

                    // =================================================
                    // Next
                    // =================================================
                    Image {
                        id: nextAudioID

                        source: "images/Next.png"
                        fillMode: Image.PreserveAspectFit

                        width: root.button_size
                        height: root.button_size

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                media_player.next()
                            }
                        }
                    }
                }

                // =================================================
                // Volume
                // =================================================
                Row {
                    id: volumeContainer

                    anchors.left: mainControls.right
                    anchors.leftMargin: 30
                    anchors.verticalCenter: mainControls.verticalCenter
                    spacing: 8

                    // =================================================
                    // Mute
                    // =================================================
                    Image {
                        id: mutedUnmutedAudioID

                        source: (media_player.volume === 0 || media_player.muted) ? "images/muted.png" : "images/unmuted.png"
                        fillMode: Image.PreserveAspectFit

                        width: root.mute_size
                        height: root.mute_size
                        anchors.verticalCenter: parent.verticalCenter

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                media_player.muted = !media_player.muted
                            }
                        }
                    }

                    // =================================================
                    // Volume Slider
                    // =================================================

                    Slider {
                        id: volumeProgress

                        width: Math.max(80, Math.min(140, root.screenSize * 0.20) )
                        height: 40
                        anchors.verticalCenter:parent.verticalCenter

                        from: 0
                        to: 1
                        value: media_player.volume

                        onMoved: {
                            media_player.volume = value
                        }
                    }

                    // =================================================
                    // Volume Percentage
                    // =================================================
                    Text {
                        id: volumeLevelID

                        text:Math.round(media_player.volume * 100) + " %"

                        font.pixelSize: 14
                        color: "white"
                        anchors.verticalCenter:parent.verticalCenter
                    }
                }

                // =====================================================
                // USB Devices Popup
                // =====================================================
                Popup {
                    id: usbDevicesPopup

                    anchors.centerIn: Overlay.overlay

                    width: 360
                    height: 300

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

                        // =================================================
                        // Popup Title
                        // =================================================
                        Label {
                            text: qsTr("Select USB Device")

                            color: "#B2EBF2"
                            font.bold: true
                            font.pixelSize: 20

                            Layout.fillWidth: true
                            Layout.preferredHeight: 55

                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        // =================================================
                        // USB Devices List
                        // =================================================
                        ListView {
                            id: usbDevicesList

                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.leftMargin: 10
                            Layout.rightMargin: 10
                            Layout.bottomMargin: 10

                            model: media_player.usb_devices
                            clip: true
                            spacing: 5

                            delegate: ItemDelegate {

                                width: usbDevicesList.width
                                height: 55

                                contentItem: Text {
                                    text: modelData
                                    color: "white"
                                    font.pixelSize: 14
                                    verticalAlignment: Text.AlignVCenter
                                    elide: Text.ElideMiddle
                                }

                                background: Rectangle {
                                    radius: 8
                                    color: parent.hovered? "#263B3D" : "transparent"
                                }

                                onClicked: {

                                    console.log(
                                        "Selected USB:",
                                        modelData
                                    )

                                    // Load the selected USB
                                    media_player.loadUSB(modelData)
                                    // Close USB selection popup
                                    usbDevicesPopup.close()
                                    // Wait until the playlist is updated
                                    Qt.callLater(function() {
                                        if (media_player.playing_list.length > 0) {
                                            console.log(
                                                "USB loaded successfully"
                                            )
                                            // Open audio files popup
                                            usbFilesPopup.open()
                                        } else {
                                            console.log(
                                                "No audio files found in selected USB"
                                            )
                                        }
                                    })
                                }
                            }

                            // =================================================
                            // Scroll Bar
                            // =================================================
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
                    }
                }
                // =====================================================
                // USB Files Popup
                // =====================================================
                Popup {
                    id: usbFilesPopup

                    anchors.centerIn: Overlay.overlay

                    width: 360
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
                        spacing: 0

                        // =================================================
                        // Popup Title
                        // =================================================
                        Label {
                            text: qsTr("USB Audio Files")

                            color: "#B2EBF2"
                            font.bold: true
                            font.pixelSize: 20

                            Layout.fillWidth: true
                            Layout.preferredHeight: 55
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        // =================================================
                        // USB Path
                        // =================================================
                        Label {
                            text: media_player.usb_path

                            color: "#78909C"
                            font.pixelSize: 11

                            Layout.fillWidth: true
                            Layout.leftMargin: 15
                            Layout.rightMargin: 15

                            // Shortens the text from the middle and adds "..." when it exceeds the available width.
                            elide: Text.ElideMiddle
                            horizontalAlignment:Text.AlignHCenter
                        }

                        // =================================================
                        // Files List
                        // =================================================
                        ListView {
                            id: usbFilesList

                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.topMargin: 10
                            model: media_player.playing_list

                            // Clips child elements so they cannot appear outside this item's boundaries.
                            clip: true
                            spacing: 5

                            delegate: ItemDelegate {

                                width: usbFilesList.width
                                height: 55

                                contentItem: Text {

                                    text: getFileName(modelData)
                                    color:index === media_player.current_playlist_index ? "#24BFB5" : "white"

                                    font.pixelSize: 14
                                    verticalAlignment:Text.AlignVCenter

                                    elide:Text.ElideRight
                                }

                                background: Rectangle {

                                    radius: 8
                                    color:parent.hovered ? "#263B3D" : "transparent"
                                }

                                onClicked: {
                                    media_player.playSelected(index)
                                    usbFilesPopup.close()
                                }
                            }

                            // =================================================
                            // Scroll Bar
                            // =================================================

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
                    }
                }
            }
        }
    }

    // =====================================================
    // Helper Functions
    // =====================================================
    function getFileName(path) {
        if (!path)
        {
            return ""
        }

        var parts = path.split("/")
        return parts[parts.length - 1]
    }

    function getCurrentFileName() {
        var index = media_player.current_playlist_index
        var list = media_player.playing_list

        if (index < 0 || index >= list.length)
        {
            return "No Audio Selected"
        }

        return getFileName(list[index])
    }

    // =====================================================
    // Load USB when page opens
    // =====================================================
    Component.onCompleted: {

        Qt.callLater(function() {
            console.log("========== USB PAGE ==========")
            media_player.scanUSB()
            console.log(
                "USB Connected:",
                media_player.usb_connect
            )
            console.log(
                "USB Devices:",
                media_player.usb_devices
            )
        })
    }
}