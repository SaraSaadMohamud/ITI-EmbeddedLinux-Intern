import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {

    id: splashPageId

    signal splashFinished()

    background: Rectangle {
        color: "#050708"
    }

    Rectangle {
        anchors.fill: parent
        color: "#050708"

        // ==========================================
        // Background Image
        // ==========================================
        Image {
            id: splashImage

            anchors.fill: parent
            source: "images/splashPage.png"
            fillMode: Image.PreserveAspectCrop
        }

        // ==========================================
        // Application Information
        // ==========================================
        ColumnLayout {
            id: splashContent

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.01

            spacing: parent.height * 0.018
           opacity: 0
            scale: 0.95

            Behavior on opacity {
                NumberAnimation {
                    duration: 900
                    easing.type: Easing.OutCubic
                }
            }

            Behavior on scale {
                NumberAnimation {
                    duration: 900
                    easing.type: Easing.OutBack
                }
            }

            // ======================================
            // Application Name
            // ======================================
            Label {

                Layout.alignment: Qt.AlignHCenter

                text: "AUDIO PLAYER"
                color: "#F5F3FA"
                font.pixelSize: Math.max(24, parent.width * 0.035)
                font.bold: true
                renderType: Text.NativeRendering
            }

            // ======================================
            // Supported Sources
            // ======================================
            Label {
                Layout.alignment: Qt.AlignHCenter

                text: "AUDIO  •  RADIO  •  USB  •  BLUETOOTH "
                color: "#D9F7FF"
                font.pixelSize: Math.max(13, parent.width * 0.014)
                font.bold: true
                opacity: 0.95
                horizontalAlignment: Text.AlignHCenter
            }


            // ======================================
            // Loading Indicator
            // ======================================
            BusyIndicator {

                id: loadingIndicator

                Layout.alignment: Qt.AlignHCenter
                width: Math.min(parent.width * 0.055, 38)
                height: width

                running: splashTimer.running
            }
        }


        // ==========================================
        // Start Content Animation
        // ==========================================
        Component.onCompleted: {

            splashContent.opacity = 1
            splashContent.scale = 1
        }


        // ==========================================
        // Splash Timer
        // ==========================================
        Timer {

            id: splashTimer

            interval: 2000
            repeat: false
            running: true

            onTriggered: {
                console.log("========== SPLASH FINISHED ==========")
                splashPageId.splashFinished()
            }
        }
    }
}