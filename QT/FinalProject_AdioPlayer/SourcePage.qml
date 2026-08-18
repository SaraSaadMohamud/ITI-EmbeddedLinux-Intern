import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    readonly property real horizontalSpacing: 25
    readonly property real availableCardWidth:(width - 2 * 25 - horizontalSpacing) / 2
    readonly property real availableCardHeight:(height - 170) / 2
    readonly property real cardWidth:Math.max(120,Math.min(300,availableCardWidth,availableCardHeight * 0.67))
    readonly property real cardHeight:cardWidth / 0.67

    Rectangle {
        anchors.fill: parent
        color: "#050708"

        // =====================================================
        // Background
        // =====================================================
        Image {
            anchors.fill: parent
            source: "images/sourcepage.png"
            fillMode: Image.PreserveAspectCrop
            opacity: 0.7
        }

        // =====================================================
        // Main Content
        // =====================================================
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 25
            spacing: 15

            // =====================================================
            // Page Title
            // =====================================================
            Text {
                id: pageTitle

                text: qsTr("SOURCE AUDIOS")
                color: "#F5F3FA"
                font.bold: true
                font.pixelSize:Math.max(22,Math.min(30, parent.width * 0.035))
                Layout.alignment: Qt.AlignHCenter
            }

            // =====================================================
            // Source Cards
            // =====================================================
            GridLayout {
                id: sourceGrid

                columns: 2
                columnSpacing: horizontalSpacing
                rowSpacing: 18

                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth: cardWidth * 2 + columnSpacing
                Layout.preferredHeight: cardHeight * 2 + rowSpacing

                // =================================================
                // LOCAL AUDIO
                // =================================================
                Rectangle {
                    id: localAudioCard

                    Layout.preferredWidth: cardWidth
                    Layout.preferredHeight: cardHeight
                    radius: 18

                    color: "#0D1517"
                    border.width: localMouse.containsMouse ? 3 : 2
                    border.color: localMouse.containsMouse ? "#24BFB5" : "#168F89"
                    clip: true

                    // -------------------------------------------------
                    // Image
                    // -------------------------------------------------
                    Image {
                        anchors.fill: parent
                        anchors.margins: 2

                        source: "images/localAduio.png"
                        fillMode: Image.PreserveAspectFit

                        smooth: true
                        mipmap: true
                    }

                    // -------------------------------------------------
                    // Hover Overlay
                    // -------------------------------------------------
                    Rectangle {
                        anchors.fill: parent
                        radius: parent.radius
                        color: "#24BFB5"
                        opacity: localMouse.containsMouse  ? 0.08 : 0
                        Behavior on opacity { NumberAnimation { duration: 150} }
                    }

                    // -------------------------------------------------
                    // Mouse
                    // -------------------------------------------------
                    MouseArea {
                        id: localMouse

                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor

                        onClicked: {
                            stackView.push("LocalAudioPage.qml")
                        }
                    }

                    // -------------------------------------------------
                    // Hover Scale
                    // -------------------------------------------------
                    scale: localMouse.containsMouse ? 1.025 : 1.0
                    Behavior on scale { NumberAnimation { duration: 120 } }
                    Behavior on border.width {NumberAnimation { duration: 120 } }
                }


                // =================================================
                // RADIO
                // =================================================

                Rectangle {

                    id: radioCard

                    Layout.preferredWidth: cardWidth
                    Layout.preferredHeight: cardHeight
                    radius: 18

                    color: "#0D1517"
                    border.width: radioMouse.containsMouse ? 3 : 2
                    border.color: radioMouse.containsMouse  ? "#24BFB5" : "#168F89"
                    clip: true

                    Image {
                        anchors.fill: parent
                        anchors.margins: 2

                        source: "images/radio.png"
                        fillMode: Image.PreserveAspectFit

                        smooth: true
                        mipmap: true
                    }

                    Rectangle {
                        anchors.fill: parent
                        radius: parent.radius
                        color: "#24BFB5"

                        opacity: radioMouse.containsMouse ? 0.08 : 0
                        Behavior on opacity { NumberAnimation { duration: 150 } }
                    }

                    MouseArea {
                        id: radioMouse

                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape:Qt.PointingHandCursor

                        onClicked: {
                            stackView.push("RadioPage.qml")
                        }
                    }

                    scale:radioMouse.containsMouse? 1.025 : 1.0
                    Behavior on scale {NumberAnimation { duration: 120 } }

                    Behavior on border.width { NumberAnimation { duration: 120 } }
                }

                // =================================================
                // USB AUDIO
                // =================================================

                Rectangle {

                    id: usbCard

                    Layout.preferredWidth: cardWidth
                    Layout.preferredHeight: cardHeight
                    radius: 18

                    color: "#0D1517"
                    border.width:usbMouse.containsMouse ? 3 : 2
                    border.color:usbMouse.containsMouse ? "#24BFB5" : "#168F89"
                    clip: true

                    Image {
                        anchors.fill: parent
                        anchors.margins: 2

                        source: "images/USB.png"
                        fillMode: Image.PreserveAspectFit

                        smooth: true
                        mipmap: true
                    }

                    Rectangle {
                        anchors.fill: parent
                        radius: parent.radius

                        color: "#24BFB5"
                        opacity:usbMouse.containsMouse ? 0.08 : 0

                        Behavior on opacity { NumberAnimation { duration: 150 } }
                    }

                    MouseArea {
                        id: usbMouse

                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape:Qt.PointingHandCursor

                        onClicked: {
                            stackView.push("USBPage.qml" )
                        }
                    }


                    scale: usbMouse.containsMouse ? 1.025 : 1.0
                    Behavior on scale { NumberAnimation { duration: 120 } }
                    Behavior on border.width { NumberAnimation { duration: 120 } }
                }

                // =================================================
                // BLUETOOTH
                // =================================================

                Rectangle {
                    id: bluetoothCard

                    Layout.preferredWidth: cardWidth
                    Layout.preferredHeight: cardHeight
                    radius: 18

                    color: "#0D1517"
                    border.width: bluetoothMouse.containsMouse ? 3 : 2
                    border.color: bluetoothMouse.containsMouse ? "#24BFB5" : "#168F89"
                    clip: true

                    Image {
                        anchors.fill: parent
                        anchors.margins: 2

                        source: "images/blutooth.png"
                        fillMode: Image.PreserveAspectFit

                        smooth: true
                        mipmap: true
                    }

                    Rectangle {
                        anchors.fill: parent
                        radius: parent.radius

                        color: "#24BFB5"
                        opacity:bluetoothMouse.containsMouse ? 0.08 : 0
                        Behavior on opacity {NumberAnimation { duration: 150 } }
                    }

                    MouseArea {
                        id: bluetoothMouse

                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor

                        onClicked: {
                            stackView.push("BluetoothPage.qml")
                        }
                    }

                    scale:bluetoothMouse.containsMouse ? 1.025  : 1.0
                    Behavior on scale { NumberAnimation { duration: 120 } }

                    Behavior on border.width { NumberAnimation { duration: 120 } }
                }
            }
        }
    }
}