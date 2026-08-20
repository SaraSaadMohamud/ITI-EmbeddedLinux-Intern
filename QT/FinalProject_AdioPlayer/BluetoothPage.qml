import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import FinalProject_AdioPlayer

Page {
    id: root

    readonly property real screenSize: Math.min(root.width, root.height)
    readonly property real icons_size: screenSize * 0.42
    readonly property real button_size: screenSize * 0.085
    readonly property real mute_size: screenSize * 0.075

    BluetoothManager {
        id: bluetoothManager
    }

    AudioPlayer {
        id: audioPlayer
    }

    property bool audioReceived: false
    property string receivedAudioPath: ""
    readonly property real remainingTime: Math.max( 0, 
                                          audioPlayer.duration -  audioPlayer.position)

    Rectangle {
        anchors.fill: parent
        color: "black"

        Image {
            anchors.fill: parent

            source:"images/localPage.png"
            fillMode:Image.PreserveAspectCrop

            opacity: 0.7  
        }

        Rectangle {
            anchors.fill: parent
            color: "#050708"
            opacity: 0.30
        }
    }

    // =====================================================
    // Back Button
    // =====================================================
    Image {
        id: backButton

        source:"images/return.png"
        fillMode:Image.PreserveAspectFit

        width: 45
        height: 45

        anchors.left:parent.left
        anchors.top:parent.top
        anchors.leftMargin: 20
        anchors.topMargin: 20

        z: 20
        MouseArea {
            anchors.fill: parent

            onClicked: {

                if (bluetoothManager.scanning) {
                    bluetoothManager.stopScan()
                }

                audioPlayer.stop()
                root.StackView.view.pop()
            }
        }
    }

    // =====================================================
    // Main Container
    // =====================================================
    ColumnLayout {
        id: mainContainer

        anchors.fill:parent
        anchors.leftMargin: 25
        anchors.rightMargin: 25
        spacing: 8

        // =================================================
        // TITLE
        // =================================================
        Text {

            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 65
            text: qsTr("Bluetooth Audio")

            font.bold:true
            font.pixelSize:30
            color:"#B2EBF2"
        }

        // =================================================
        // RECEIVING SCREEN
        // =================================================
        ColumnLayout {
            id: receivingScreen

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter

            spacing: 10

            visible: !root.audioReceived


            // =============================================
            // Bluetooth Status
            // =============================================
            Text {

                Layout.alignment:Qt.AlignHCenter
                text:bluetoothManager.bluetoothPoweredOn ? 
                                      qsTr("● Bluetooth ON") : qsTr("● Bluetooth OFF")

                font.pixelSize: 14
                font.bold:true

                color:bluetoothManager.bluetoothPoweredOn ? "#24BFB5" : "#FF5252"
            }

            // =============================================
            // Bluetooth Image
            // =============================================
            Image {

                Layout.alignment: Qt.AlignHCenter
                Layout.fillHeight: true
                Layout.preferredWidth: root.icons_size
                Layout.preferredHeight:  root.icons_size

                source:"images/1.png"
                fillMode: Image.PreserveAspectFit

                smooth:true
                mipmap:true
                opacity:bluetoothManager.receivingFile ? 0.45 : 1.0
            }

            // =============================================
            // Connection Status
            // =============================================
            Text {

                Layout.alignment:Qt.AlignHCenter

                text:bluetoothManager.connected? bluetoothManager.connectedDeviceName
                    : qsTr("No device connected")

                color:bluetoothManager.connected? "#FFFFFF" : "#78909C"

                font.pixelSize: 13
                font.bold: true
                elide:Text.ElideRight
            }

            Text {

                Layout.alignment:Qt.AlignHCenter

                text:bluetoothManager.connectionStatus

                color:bluetoothManager.receivingFile ? "#FFD54F" : "#90A4AE"
                font.pixelSize: 11
                elide: Text.ElideRight
            }

            // =============================================
            // Receiving Status
            // =============================================
            Rectangle {

                Layout.alignment:Qt.AlignHCenter
                Layout.preferredWidth: Math.min( 360, root.width - 50 )
                Layout.preferredHeight: 55

                visible:  bluetoothManager.receivingFile
                radius:  10

                color: "#1A211F"
                border.width: 1
                border.color: "#24BFB5"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing:  10

                    BusyIndicator {
                        running:bluetoothManager.receivingFile
                        Layout.preferredWidth:25
                        Layout.preferredHeight: 25
                    }

                    Text {
                        Layout.fillWidth: true

                        text:qsTr( "Receiving Bluetooth Audio..." )
                        color: "#24BFB5"

                        font.bold: true
                        font.pixelSize:  12
                    }
                }
            }


            // =============================================
            // Bluetooth Button
            // =============================================
            Image {

                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth: root.mute_size
                Layout.preferredHeight: root.mute_size

                source:"images/bluetooth_btn.png"
                fillMode: Image.PreserveAspectFit

                MouseArea {
                    anchors.fill: parent

                    onClicked:
                        bluetoothPopup.open()
                }
            }

            Item {
                Layout.preferredHeight: 10
            }
        }


        // =================================================
        // AUDIO PLAYER
        // =================================================
        ColumnLayout {
            id: playerScreen

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter

            spacing: 5
            visible: root.audioReceived

            Text {
                
                Layout.preferredWidth: root.width * 0.7
                horizontalAlignment: Text.AlignHCenter

                text: bluetoothManager.connected ? bluetoothManager.connectedDeviceName
                    : qsTr("Bluetooth Device")

                color:  "#24BFB5"
                font.pixelSize:  13
                font.bold: true

                elide:Text.ElideRight
            }

            // =============================================
            // IMAGE + METADATA
            // Same philosophy as LocalPage
            // =============================================
            Item {
    id: audioInfoContainer

    Layout.fillWidth: true
    Layout.fillHeight: true

    // =========================================
    // IMAGE + METADATA CENTERED
    // =========================================
    Row {
        id: audioInfoRow

        anchors.centerIn: parent

        spacing: root.width * 0.015

        // =====================================
        // Audio Image
        // =====================================
        Image {
            id: audioImage

            width: root.icons_size
            height: root.icons_size

            anchors.verticalCenter: parent.verticalCenter

            source: "images/1.png"
            fillMode: Image.PreserveAspectFit

            smooth: true
            mipmap: true
        }

        // =====================================
        // Metadata
        // =====================================
        Column {
            id: audioMetadata

            width: Math.min(root.width * 0.40, 320)

            anchors.verticalCenter: parent.verticalCenter

            spacing: 8

            Text {
                width: parent.width

                text: audioPlayer.audio_title !== ""
                      ? audioPlayer.audio_title
                      : qsTr("Bluetooth Audio")

                font.pixelSize: 21
                color: "#FFFFFF"

                horizontalAlignment: Text.AlignLeft

                wrapMode: Text.Wrap
                maximumLineCount: 2
                elide: Text.ElideRight
            }

            Text {
                width: parent.width

                text: audioPlayer.audio_author !== ""
                      ? audioPlayer.audio_author
                      : qsTr("Unknown Artist")

                font.pixelSize: 16
                color: "#B2EBF2"

                horizontalAlignment: Text.AlignLeft

                wrapMode: Text.Wrap
                maximumLineCount: 2
                elide: Text.ElideRight
            }

            Text {
                width: parent.width

                text: audioPlayer.audio_genre !== ""
                      ? audioPlayer.audio_genre
                      : qsTr("Bluetooth Audio")

                font.pixelSize: 13
                color: "#546E7A"

                horizontalAlignment: Text.AlignLeft

                elide: Text.ElideRight
            }

            Text {
                width: parent.width

                text: audioPlayer.audio_album !== ""
                      ? audioPlayer.audio_album
                      : qsTr("Bluetooth Received File")

                font.pixelSize: 12
                font.bold: true
                color: "#B2EBF2"

                horizontalAlignment: Text.AlignLeft

                wrapMode: Text.Wrap
                elide: Text.ElideRight
            }
        }
    }
}

            // =============================================
            // Progress
            // =============================================
            RowLayout {

                id: durationRow

                Layout.fillWidth:  true
                spacing:  8

                Text {
                    text: audioPlayer.formateTime(audioPlayer.position )
                    font.pixelSize: 13
                    color:"white"
                }

                Slider {
                    id: audioProgress

                    Layout.fillWidth:true

                    from:0
                    to:Math.max( 1, audioPlayer.duration )
                    value: audioPlayer.position

                    enabled: audioPlayer.duration > 0

                    onMoved: {
                        audioPlayer.position = value
                    }
                }

                Text {
                    text: audioPlayer.formateTime( Math.max(  0,
                                audioPlayer.duration - audioPlayer.position ) )

                    font.pixelSize: 13
                    color: "white"
                }
            }

    // =============================================
    // MAIN CONTROLS + VOLUME
    // =============================================
    Item {
    id: controlsContainer

    Layout.fillWidth: true
    Layout.preferredHeight: root.button_size + 20

    Row {
        id: mainControls

        anchors.centerIn: parent
        spacing: Math.max(12, root.screenSize * 0.025)

        // =====================================
        // PLAY / PAUSE
        // =====================================
        Image {
            id: playPauseAudio

            source: audioPlayer.playing_state ? "images/pause.png" : "images/play.png"
            fillMode: Image.PreserveAspectFit

            width: root.button_size
            height: root.button_size

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.log("Play/Pause clicked")
                    audioPlayer.playPause()
                }
            }
        }

        // =====================================
        // STOP
        // =====================================
        Image {
            id: stopAudio

            source: "images/stop.png"
            fillMode: Image.PreserveAspectFit

            width: root.button_size
            height: root.button_size

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.log("Stop clicked")
                    audioPlayer.stop()
                }
            }
        }

        // =====================================
        // VOLUME
        // =====================================
        Row {
            id: volumeContainer

            spacing: 8
            anchors.verticalCenter: parent.verticalCenter

            // =================================
            // MUTE
            // =================================
            Image {
                id: muteButton

                source: audioPlayer.volume === 0 || audioPlayer.muted ? "images/muted.png" : "images/unmuted.png"
                fillMode: Image.PreserveAspectFit

                width: root.mute_size
                height: root.mute_size

                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        audioPlayer.muted = !audioPlayer.muted
                    }
                }
            }

            // =================================
            // VOLUME SLIDER
            // =================================
            Slider {
                id: volumeSlider

                width: Math.max( 100, Math.min(150, root.screenSize * 0.20) )
                height: 40

                anchors.verticalCenter: parent.verticalCenter

                from: 0
                to: 1
                value: audioPlayer.volume

                onMoved: {
                    audioPlayer.volume = value
                }
            }

            // =================================
            // VOLUME %
            // =================================
            Text {
                text: Math.round(audioPlayer.volume * 100) + " %"

                font.pixelSize: 13
                color: "white"

                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
    }
            // =============================================
            // DISCONNECT ONLY
            // =============================================
            Button {
                id: disconnectButton

                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth:  170
                Layout.preferredHeight: 42
                Layout.bottomMargin:  8

                text: qsTr("Disconnect")

                onClicked: {
                    console.log( "Disconnect Bluetooth" )
                    audioPlayer.stop()

                    bluetoothManager.disconnectDevice()

                    root.audioReceived = false
                    root.receivedAudioPath = ""
                }
            }
        }
    }

    // =====================================================
    // BLUETOOTH POPUP
    // =====================================================
    Popup {

        id: bluetoothPopup

        anchors.centerIn: Overlay.overlay
        width: Math.min( 380, root.width - 30 )
        height: Math.min( 500, root.height - 50 )

        modal:true
        focus:true

        background: Rectangle {
            color:  "#15191B"
            radius: 15
            border.color: "#24BFB5"
            border.width: 1
        }

        contentItem:
            ColumnLayout {

                spacing:6

                // =========================================
                // Title
                // =========================================
                Label {
                    text: qsTr("Bluetooth Devices")

                    color: "#B2EBF2"
                    font.bold: true
                    font.pixelSize: 20

                    Layout.fillWidth: true
                    Layout.preferredHeight: 45
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                // =========================================
                // Bluetooth Status
                // =========================================
                Label {

                    text:bluetoothManager.bluetoothPoweredOn ? qsTr("● Bluetooth ON")
                        : qsTr("● Bluetooth OFF")

                    color: bluetoothManager.bluetoothPoweredOn ? "#24BFB5" : "#FF5252"
                    font.bold: true
                    font.pixelSize: 13

                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                }

                // =========================================
                // Connected Device
                // =========================================
                Label {

                    visible: bluetoothManager.connected

                    text:  qsTr("Connected: ") + bluetoothManager.connectedDeviceName

                    color: "#90A4AE"
                    font.pixelSize: 11

                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter

                    elide: Text.ElideRight
                }


                // =========================================
                // Scan
                // =========================================

                Button {

                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 40
                    enabled: bluetoothManager.bluetoothPoweredOn

                    text: bluetoothManager.scanning ? qsTr("Scanning...") : qsTr("Scan Devices")

                    onClicked: {
                        if (bluetoothManager.scanning ) 
                        {
                            bluetoothManager.stopScan()
                        } 
                        else 
                        {
                            bluetoothManager.startScan()
                        }
                    }
                }


                // =========================================
                // Scan Progress
                // =========================================
                ColumnLayout {

                    Layout.fillWidth: true
                    visible: bluetoothManager.scanning
                    spacing:  2

                    ProgressBar {

                        Layout.fillWidth: true

                        from: 0
                        to: 100
                        value: bluetoothManager.scanProgress
                    }

                    Label {

                        Layout.fillWidth: true
                        horizontalAlignment: Text.AlignHCenter

                        text: bluetoothManager.scanProgress + "%   •   " +
                            bluetoothManager.scanElapsedSeconds + "s"

                        color: "#78909C"
                        font.pixelSize: 10  
                    }
                }

                // =========================================
                // Device Count
                // =========================================
                Label {

                    text: qsTr("Devices Found: ") + bluetoothManager.devices.length

                    color: "#90A4AE"
                    font.pixelSize: 11

                    Layout.fillWidth: true

                    horizontalAlignment: Text.AlignHCenter
                }

                // =========================================
                // Devices List
                // =========================================

                ListView {
                    id: bluetoothDevicesList

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.leftMargin: 10
                    Layout.rightMargin: 10
                    Layout.bottomMargin: 10

                    model: bluetoothManager.devices
                    clip: true
                    spacing: 5

                    delegate:
                        ItemDelegate {
                            width: bluetoothDevicesList.width
                            height: 65

                            background: Rectangle {
                                radius: 8
                                color: parent.hovered ? "#263B3D" : "#1B2022"
                                border.color:  parent.hovered ? "#24BFB5" : "transparent"
                                border.width: 1
                            }

                            contentItem:
                                RowLayout {
                                    spacing: 10
                                    Text {

                                        text:  "ᛒ"

                                        font.pixelSize:  27
                                        color: "#24BFB5"

                                        Layout.preferredWidth: 35
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                    }

                                    ColumnLayout {

                                        Layout.fillWidth: true
                                        spacing: 2

                                        Text {
                                            text: modelData.name

                                            color: "white"
                                            font.pixelSize: 13
                                            font.bold: true

                                            Layout.fillWidth: true
                                            elide: Text.ElideRight
                                        }

                                        Text {

                                            text:modelData.type

                                            color:"#24BFB5"
                                            font.pixelSize: 10

                                            Layout.fillWidth:  true
                                        }

                                        Text {

                                            text:modelData.address + "   •   RSSI: " + modelData.rssi

                                            color: "#78909C"
                                            font.pixelSize: 9

                                            Layout.fillWidth: true
                                            elide:Text.ElideMiddle
                                        }
                                    }

                                    Text {

                                        text: bluetoothManager.connected &&
                                            bluetoothManager.connectedDeviceName ===
                                            modelData.name ? "✓" : "›"

                                        color: "#24BFB5"
                                        font.pixelSize:  25

                                        Layout.preferredWidth: 25
                                        horizontalAlignment: Text.AlignHCenter
                                    }
                                }

                            onClicked: {
                                if ( bluetoothManager.connected ) 
                                {
                                    bluetoothManager.disconnectDevice()
                                }

                                bluetoothManager.pairAndConnect( modelData.address,
                                    modelData.name
                                )
                            }
                        }

                    ScrollBar.vertical:
                        ScrollBar {

                            policy: ScrollBar.AsNeeded
                            width:  8

                            contentItem:  Rectangle {
                                implicitWidth: 8
                                radius: 4
                                color: "#24BFB5"
                            }

                            background: Rectangle {
                                implicitWidth: 8
                                radius:  4
                                color: "#303638"
                            }
                        }

                    Text {

                        anchors.centerIn: parent

                        visible: bluetoothManager.devices.length === 0 &&
                                !bluetoothManager.scanning

                        text: bluetoothManager.bluetoothPoweredOn ? qsTr(
                                "No Bluetooth devices found"  ) : qsTr(
                                "Bluetooth is turned off" )

                        color:  "#607D80"
                        font.pixelSize: 13
                    }

                    BusyIndicator {

                        anchors.centerIn: parent
                        running: bluetoothManager.scanning
                        visible: bluetoothManager.scanning
                    }
                }

                // =========================================
                // Close
                // =========================================
                Button {

                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 120
                    text: qsTr("Close")

                    onClicked:
                        bluetoothPopup.close()
                }
            }
    }

    // =====================================================
    // FILE RECEIVED
    // =====================================================
    Connections {

        target: bluetoothManager

        function onFileReceived(filePath) {
            console.log( "================================"  )
            console.log( "Bluetooth Audio Received:" )
            console.log( filePath )
            console.log("================================" )

            root.receivedAudioPath = filePath
            bluetoothPopup.close()
            root.audioReceived = true

            // =============================================
            // Load received file
            // =============================================
            audioPlayer.playBluetoothFile( filePath )
        }
    }

    // =====================================================
    // AUDIO ERROR
    // =====================================================
    Connections {

        target:audioPlayer

        function onErrorOccured() {
            console.log( "Bluetooth Audio Player Error:", audioPlayer.error_string )
        }
    }

    // =====================================================
    // PAGE LOADED
    // =====================================================
    Component.onCompleted: {

        console.log( "====================================" )
        console.log( "BLUETOOTH PAGE" )
        console.log( "Bluetooth Powered:", bluetoothManager.bluetoothPoweredOn)
        console.log( "====================================" )
    }
}