import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import FinalProject_AdioPlayer

Page {
    id: root

    readonly property real screenSize:
        Math.min(root.width, root.height)

    readonly property real icons_size:
        screenSize * 0.45

    readonly property real button_size:
        screenSize * 0.09

    readonly property real bluetooth_size:
        screenSize * 0.10


    // =====================================================
    // Bluetooth Manager
    // =====================================================

    BluetoothManager {
        id: bluetoothManager
    }


    // =====================================================
    // Background
    // =====================================================

    Rectangle {
        anchors.fill: parent

        color: "black"


        Image {
            source: "images/localPage.png"

            anchors.fill: parent

            opacity: 0.7

            fillMode:
                Image.PreserveAspectCrop
        }


        // =================================================
        // Back Button
        // =================================================

        Image {
            source: "images/return.png"

            width: 45
            height: 45

            anchors.left:
                parent.left

            anchors.top:
                parent.top

            anchors.leftMargin: 20
            anchors.topMargin: 20

            fillMode:
                Image.PreserveAspectFit


            MouseArea {
                anchors.fill: parent

                onClicked: {

                    if (bluetoothManager.scanning) {
                        bluetoothManager.stopScan()
                    }

                    root.StackView.view.pop()
                }
            }
        }


        // =================================================
        // Main Container
        // =================================================

        ColumnLayout {
            anchors.fill: parent

            // =================================================
            // Title
            // =================================================

            Text {
                Layout.alignment:
                    Qt.AlignHCenter

                Layout.topMargin: 75

                text:
                    qsTr("Bluetooth Audio")

                font.bold: true

                font.pixelSize: 30

                color:
                    "#B2EBF2"
            }


            // =================================================
            // Bluetooth Status
            // =================================================

            Text {
                Layout.alignment:
                    Qt.AlignHCenter

                text:
                    bluetoothManager.bluetoothPoweredOn
                    ? "● Bluetooth ON"
                    : "● Bluetooth OFF"

                font.pixelSize: 15

                font.bold: true

                color:
                    bluetoothManager.bluetoothPoweredOn
                    ? "#24BFB5"
                    : "#FF5252"
            }


            // =================================================
            // Bluetooth Image
            // =================================================

            Image {
                Layout.alignment:
                    Qt.AlignHCenter

                Layout.fillHeight: true

                source:
                    "images/bluetooth_page.png"

                fillMode:
                    Image.PreserveAspectFit

                Layout.preferredWidth:
                    root.icons_size

                Layout.preferredHeight:
                    root.icons_size

                smooth: true
                mipmap: true
            }


            // =================================================
            // Bottom Controls
            // =================================================

            Item {
                id: controlsContainer

                Layout.fillWidth: true

                Layout.preferredHeight:
                    root.button_size + 30


                // =============================================
                // Bluetooth Button
                // =============================================

                Image {
                    id: bluetoothButton

                    source:
                        "images/bluetooth_btn.png"

                    width:
                        root.bluetooth_size

                    height:
                        root.bluetooth_size

                    anchors.centerIn:
                        parent

                    fillMode:
                        Image.PreserveAspectFit


                    MouseArea {
                        anchors.fill: parent

                        onClicked: {

                            bluetoothPopup.open()

                        }
                    }
                }
            }
        }
    }


    // =====================================================
    // Bluetooth Popup
    // =====================================================

    Popup {
        id: bluetoothPopup

        anchors.centerIn:
            Overlay.overlay

        width: 380
        height: 360

        modal: true
        focus: true


        background: Rectangle {

            color:
                "#15191B"

            radius: 15

            border.color:
                "#24BFB5"

            border.width: 1
        }


        contentItem: ColumnLayout {

            spacing: 5


            // =================================================
            // Popup Title
            // =================================================

            Label {
                text:
                    qsTr("Bluetooth Devices")

                color:
                    "#B2EBF2"

                font.bold: true

                font.pixelSize: 20

                Layout.fillWidth: true

                Layout.preferredHeight: 50

                horizontalAlignment:
                    Text.AlignHCenter

                verticalAlignment:
                    Text.AlignVCenter
            }


            // =================================================
            // Bluetooth Status
            // =================================================

            Label {
                text:
                    bluetoothManager.bluetoothPoweredOn
                    ? qsTr("● Bluetooth ON")
                    : qsTr("● Bluetooth OFF")

                color:
                    bluetoothManager.bluetoothPoweredOn
                    ? "#24BFB5"
                    : "#FF5252"

                font.bold: true

                font.pixelSize: 14

                Layout.fillWidth: true

                horizontalAlignment:
                    Text.AlignHCenter
            }


            // =================================================
            // Scan Button
            // =================================================

            Button {
                Layout.alignment:
                    Qt.AlignHCenter

                Layout.preferredWidth: 180

                Layout.preferredHeight: 40

                enabled:
                    bluetoothManager.bluetoothPoweredOn


                text:
                    bluetoothManager.scanning
                    ? qsTr("Scanning...")
                    : qsTr("Scan Devices")


                onClicked: {

                    if (bluetoothManager.scanning) {

                        bluetoothManager.stopScan()

                    }
                    else {

                        bluetoothManager.startScan()

                    }
                }
            }


            // =================================================
            // Device Count
            // =================================================

            Label {
                text:
                    qsTr("Devices Found: ")
                    + bluetoothManager.devices.length

                color:
                    "#90A4AE"

                font.pixelSize: 12

                Layout.fillWidth: true

                horizontalAlignment:
                    Text.AlignHCenter
            }


            // =================================================
            // Devices List
            // =================================================

            ListView {
                id: bluetoothDevicesList

                Layout.fillWidth: true

                Layout.fillHeight: true

                Layout.leftMargin: 10

                Layout.rightMargin: 10

                Layout.bottomMargin: 10

                model:
                    bluetoothManager.devices

                clip: true

                spacing: 5


                // =================================================
                // Device Delegate
                // =================================================

                delegate: ItemDelegate {

                    width:
                        bluetoothDevicesList.width

                    height: 60


                    background: Rectangle {

                        radius: 8

                        color:
                            parent.hovered
                            ? "#263B3D"
                            : "#1B2022"

                        border.color:
                            parent.hovered
                            ? "#24BFB5"
                            : "transparent"

                        border.width: 1
                    }


                    contentItem: RowLayout {

                        spacing: 10


                        // =========================================
                        // Bluetooth Icon
                        // =========================================

                        Text {
                            text:
                                "ᛒ"

                            font.pixelSize: 27

                            color:
                                "#24BFB5"

                            Layout.preferredWidth:
                                35

                            horizontalAlignment:
                                Text.AlignHCenter

                            verticalAlignment:
                                Text.AlignVCenter
                        }


                        // =========================================
                        // Device Information
                        // =========================================

                        ColumnLayout {

                            Layout.fillWidth: true

                            spacing: 2


                            Text {
                                text:
                                    modelData.name

                                color:
                                    "white"

                                font.pixelSize: 14

                                font.bold: true

                                Layout.fillWidth: true

                                elide:
                                    Text.ElideRight
                            }


                            Text {
                                text:
                                    modelData.type

                                color:
                                    "#24BFB5"

                                font.pixelSize: 10

                                Layout.fillWidth: true
                            }


                            Text {
                                text:
                                    modelData.address
                                    + "   •   RSSI: "
                                    + modelData.rssi

                                color:
                                    "#78909C"

                                font.pixelSize: 10

                                Layout.fillWidth: true

                                elide:
                                    Text.ElideMiddle
                            }
                        }


                        // =========================================
                        // Arrow
                        // =========================================

                        Text {
                            text:
                                "›"

                            color:
                                "#24BFB5"

                            font.pixelSize: 28

                            Layout.preferredWidth:
                                20

                            horizontalAlignment:
                                Text.AlignHCenter
                        }
                    }


                    // =============================================
                    // Device Click
                    // =============================================

                    onClicked: {

                        console.log(
                            "================================"
                        )

                        console.log(
                            "Selected Bluetooth Device:"
                        )

                        console.log(
                            "Name:",
                            modelData.name
                        )

                        console.log(
                            "Type:",
                            modelData.type
                        )

                        console.log(
                            "Address:",
                            modelData.address
                        )

                        console.log(
                            "RSSI:",
                            modelData.rssi
                        )

                        console.log(
                            "================================"
                        )
                    }
                }


                // =================================================
                // Scroll Bar
                // =================================================

                ScrollBar.vertical:
                    ScrollBar {

                        policy:
                            ScrollBar.AsNeeded

                        width: 8


                        contentItem:
                            Rectangle {

                                implicitWidth: 8

                                radius: 4

                                color:
                                    "#24BFB5"
                            }


                        background:
                            Rectangle {

                                implicitWidth: 8

                                radius: 4

                                color:
                                    "#303638"
                            }
                    }


                // =================================================
                // Empty State
                // =================================================

                Text {

                    anchors.centerIn:
                        parent

                    visible:
                        bluetoothManager.devices.length === 0
                        &&
                        !bluetoothManager.scanning

                    text:
                        bluetoothManager.bluetoothPoweredOn
                        ? qsTr("No Bluetooth devices found")
                        : qsTr("Bluetooth is turned off")

                    color:
                        "#607D80"

                    font.pixelSize: 14
                }


                // =================================================
                // Scanning State
                // =================================================

                BusyIndicator {

                    anchors.centerIn:
                        parent

                    running:
                        bluetoothManager.scanning

                    visible:
                        bluetoothManager.scanning
                }
            }
        }
    }


    // =====================================================
    // Page Loaded
    // =====================================================

    Component.onCompleted: {

        console.log(
            "========== BLUETOOTH PAGE =========="
        )

        console.log(
            "Bluetooth Powered:",
            bluetoothManager.bluetoothPoweredOn
        )
    }
}