import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {

    id: settingsPage

    background: Rectangle {
        color: "#F4F7FB"
    }

    ColumnLayout {

        anchors.centerIn: parent

        width: 500

        spacing: 25

        Label {

            text: "Settings"

            font.pixelSize: 30

            font.bold: true

            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "Application Language"
        }

        ComboBox {

            id: languageCombo

            Layout.fillWidth: true

            model: [
                "English",
                "Arabic",
                "French"
            ]

            onCurrentTextChanged: {

                console.log(
                    "Selected language:",
                    currentText
                )
            }
        }

        Label {

            text: "Screen Brightness: " +
                  Math.round(brightnessSlider.value) +
                  "%"
        }

        Slider {

            id: brightnessSlider

            Layout.fillWidth: true

            from: 0

            to: 100

            value: 70

            onValueChanged: {

                console.log(
                    "Brightness:",
                    Math.round(value) + "%"
                )
            }
        }

        Label {

            text: "Room Temperature: " +
                  Math.round(temperatureDial.value) +
                  "°C"
        }

        Dial {

            id: temperatureDial

            Layout.alignment: Qt.AlignHCenter

            from: 16

            to: 35

            value: 24

            onValueChanged: {

                console.log(
                    "Room Temperature:",
                    Math.round(value) + "°C"
                )
            }
        }

        CheckBox {

            id: notificationCheckBox

            text: "Enable Notifications"

            checked: true

            onCheckedChanged: {

                console.log(
                    "Notifications:",
                    checked ? "Enabled" : "Disabled"
                )
            }
        }

        Button {

            text: "Save Settings"

            Layout.fillWidth: true

            onClicked: {

                console.log("========== Settings ==========")

                console.log(
                    "Language:",
                    languageCombo.currentText
                )

                console.log(
                    "Brightness:",
                    Math.round(
                        brightnessSlider.value
                    ) + "%"
                )

                console.log(
                    "Temperature:",
                    Math.round(
                        temperatureDial.value
                    ) + "°C"
                )

                console.log(
                    "Notifications:",
                    notificationCheckBox.checked
                )

                console.log(
                    "Settings saved successfully (simulation)"
                )

                console.log("==============================")
            }
        }
    }
}