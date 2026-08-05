import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {

    id: settingsPage

    property StackView stackView

    background: Rectangle {
        color: "#F4F7FB"
    }

    ColumnLayout {

        anchors.centerIn: parent

        width: 500

        spacing: 20

        Label {

            text: "Settings"

            font.pixelSize: 30
            font.bold: true

            color: "#1F2937"

            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "Application Language"

            color: "#374151"

            font.pixelSize: 15
            font.bold: true
        }

        ComboBox {

            id: languageCombo

            Layout.fillWidth: true

            model: [
                "English",
                "Arabic",
                "French"
            ]

            contentItem: Text {

                text: languageCombo.displayText

                color: "#1F2937"

                verticalAlignment: Text.AlignVCenter

                leftPadding: 12
            }

            background: Rectangle {

                radius: 8

                color: "#FFFFFF"

                border.color: "#D1D5DB"
                border.width: 1
            }

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

            color: "#374151"

            font.pixelSize: 15
            font.bold: true
        }

        Slider {

            id: brightnessSlider

            Layout.fillWidth: true

            from: 0
            to: 100
            value: 70

            background: Rectangle {

                x: brightnessSlider.leftPadding

                y: brightnessSlider.topPadding +
                   brightnessSlider.availableHeight / 2 -
                   height / 2

                width: brightnessSlider.availableWidth

                height: 6

                radius: 3

                color: "#D1D5DB"

                Rectangle {

                    width: brightnessSlider.visualPosition *
                           parent.width

                    height: parent.height

                    radius: 3

                    color: "#00A6D6"
                }
            }

            handle: Rectangle {

                x: brightnessSlider.leftPadding +
                   brightnessSlider.visualPosition *
                   brightnessSlider.availableWidth -
                   width / 2

                y: brightnessSlider.topPadding +
                   brightnessSlider.availableHeight / 2 -
                   height / 2

                width: 18
                height: 18

                radius: 9

                color: "#00A6D6"

                border.color: "#FFFFFF"
                border.width: 2
            }

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

            color: "#374151"

            font.pixelSize: 15
            font.bold: true
        }

        Dial {

            id: temperatureDial

            Layout.alignment: Qt.AlignHCenter

            from: 16
            to: 35
            value: 24

            background: Rectangle {

                implicitWidth: 80
                implicitHeight: 80

                radius: width / 2

                color: "#E5E7EB"

                border.color: "#D1D5DB"
                border.width: 2
            }

            handle: Rectangle {

                width: 12
                height: 12

                radius: 6

                color: "#00A6D6"

                x: temperatureDial.background.width / 2 -
                   width / 2

                y: temperatureDial.background.height / 2 -
                   height / 2
            }

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

            contentItem: Text {

                text: notificationCheckBox.text

                color: "#374151"

                verticalAlignment: Text.AlignVCenter

                leftPadding: 30
            }

            indicator: Rectangle {

                implicitWidth: 20
                implicitHeight: 20

                x: notificationCheckBox.leftPadding

                y: parent.height / 2 - height / 2

                radius: 5

                color: notificationCheckBox.checked
                       ? "#00A6D6"
                       : "#FFFFFF"

                border.color: notificationCheckBox.checked
                              ? "#00A6D6"
                              : "#9CA3AF"

                border.width: 1

                Text {

                    anchors.centerIn: parent

                    text: "✓"

                    color: "white"

                    font.bold: true

                    visible: notificationCheckBox.checked
                }
            }

            onCheckedChanged: {

                console.log(
                    "Notifications:",
                    checked ? "Enabled" : "Disabled"
                )
            }
        }

        Button {

            id: saveButton

            text: "Save Settings"

            Layout.fillWidth: true

            contentItem: Text {

                text: saveButton.text

                color: "#FFFFFF"

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                font.bold: true
            }

            background: Rectangle {

                radius: 8

                color: {

                    if (saveButton.pressed)
                        return "#007A9E"

                    if (saveButton.hovered)
                        return "#008FB8"

                    return "#00A6D6"
                }
            }

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

        Button {

            id: backButton

            text: "Back to Dashboard"

            Layout.fillWidth: true

            contentItem: Text {

                text: backButton.text

                color: "#00A6D6"

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                font.bold: true
            }

            background: Rectangle {

                radius: 8

                color: "#FFFFFF"

                border.color: "#00A6D6"
                border.width: 1
            }

            onClicked: {

                console.log("Returning to Dashboard")

                if (settingsPage.stackView) {

                    settingsPage.stackView.pop()

                } else {

                    console.log(
                        "ERROR: StackView reference is missing"
                    )
                }
            }
        }
    }
}