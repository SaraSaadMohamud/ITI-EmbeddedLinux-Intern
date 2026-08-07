import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {

    id: settingsPage

    property StackView stackView
    property int languageVersion: 0

    Connections {
        target: languageManager

        function onLanguageChanged() {

            settingsPage.languageVersion++

            languageCombo.model = [
                qsTr("English"),
                qsTr("Arabic"),
                qsTr("French")
            ]
        }
    }

    background: Rectangle {
        color: "#F4F7FB"
    }

    ScrollView {
        anchors.fill: parent
        anchors.margins: 20
        clip: true

        contentWidth: availableWidth

        ColumnLayout {

            width: Math.min(
                availableWidth,
                600
            )

            x: (availableWidth - width) / 2

            spacing: 18

            // =========================================
            // TITLE
            // =========================================

            Label {
                Layout.fillWidth: true

                text: {
                    settingsPage.languageVersion
                    return qsTr("Settings")
                }

                font.pixelSize: 30
                font.bold: true
                color: "#1F2937"

                horizontalAlignment: Text.AlignHCenter

                Layout.bottomMargin: 5
            }

            // =========================================
            // LANGUAGE
            // =========================================

            Label {
                Layout.fillWidth: true

                text: {
                    settingsPage.languageVersion
                    return qsTr("Application Language")
                }

                color: "#374151"
                font.pixelSize: 15
                font.bold: true
            }

            ComboBox {
                id: languageCombo

                Layout.fillWidth: true

                model: [
                    qsTr("English"),
                    qsTr("Arabic"),
                    qsTr("French")
                ]

                contentItem: Text {
                    text: languageCombo.displayText
                    color: "#1F2937"
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 12
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    radius: 8
                    color: "#FFFFFF"
                    border.color: "#D1D5DB"
                    border.width: 1
                }

                onActivated: {

                    console.log(
                        "Selected language:",
                        currentText
                    )

                    if (index === 0)
                        languageManager.setLanguage("English")

                    else if (index === 1)
                        languageManager.setLanguage("Arabic")

                    else if (index === 2)
                        languageManager.setLanguage("French")
                }
            }

            // =========================================
            // BRIGHTNESS
            // =========================================

            Label {

                Layout.fillWidth: true

                text: {
                    settingsPage.languageVersion

                    return qsTr("Screen Brightness: ") +
                           Math.round(brightnessSlider.value) +
                           "%"
                }

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

            // =========================================
            // TEMPERATURE
            // =========================================

            Label {

                Layout.fillWidth: true

                text: {
                    settingsPage.languageVersion

                    return qsTr("Room Temperature: ") +
                           Math.round(temperatureDial.value) +
                           "°C"
                }

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

            // =========================================
            // NOTIFICATIONS
            // =========================================

            CheckBox {

                id: notificationCheckBox

                text: {
                    settingsPage.languageVersion
                    return qsTr("Enable Notifications")
                }

                checked: true

                Layout.fillWidth: true

                contentItem: Text {

                    text: notificationCheckBox.text

                    color: "#374151"

                    verticalAlignment: Text.AlignVCenter

                    leftPadding: 30

                    elide: Text.ElideRight
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

            // =====================================================
            // NEW DEVICES SETTINGS
            // =====================================================

            Rectangle {
                Layout.fillWidth: true
                height: 1
                color: "#D1D5DB"

                Layout.topMargin: 5
                Layout.bottomMargin: 5
            }

            Label {

                Layout.fillWidth: true

                text: {
                    settingsPage.languageVersion
                    return qsTr("Smart Devices")
                }

                font.pixelSize: 20
                font.bold: true

                color: "#1F2937"
            }

            // =====================================================
            // SECURITY CAMERA
            // =====================================================

            CheckBox {

                id: cameraCheckBox

                text: {
                    settingsPage.languageVersion
                    return qsTr("Security Camera")
                }

                checked: true

                Layout.fillWidth: true

                contentItem: Text {

                    text: cameraCheckBox.text

                    color: "#374151"

                    verticalAlignment: Text.AlignVCenter

                    leftPadding: 30

                    elide: Text.ElideRight
                }

                indicator: Rectangle {

                    implicitWidth: 20
                    implicitHeight: 20

                    x: cameraCheckBox.leftPadding

                    y: parent.height / 2 - height / 2

                    radius: 5

                    color: cameraCheckBox.checked
                           ? "#00A6D6"
                           : "#FFFFFF"

                    border.color: cameraCheckBox.checked
                                  ? "#00A6D6"
                                  : "#9CA3AF"

                    Text {
                        anchors.centerIn: parent

                        text: "✓"

                        color: "white"

                        visible: cameraCheckBox.checked
                    }
                }
            }

            // =====================================================
            // SMART TV
            // =====================================================

            CheckBox {

                id: tvCheckBox

                text: {
                    settingsPage.languageVersion
                    return qsTr("Smart TV")
                }

                checked: true

                Layout.fillWidth: true

                contentItem: Text {

                    text: tvCheckBox.text

                    color: "#374151"

                    verticalAlignment: Text.AlignVCenter

                    leftPadding: 30

                    elide: Text.ElideRight
                }

                indicator: Rectangle {

                    implicitWidth: 20
                    implicitHeight: 20

                    x: tvCheckBox.leftPadding

                    y: parent.height / 2 - height / 2

                    radius: 5

                    color: tvCheckBox.checked
                           ? "#00A6D6"
                           : "#FFFFFF"

                    border.color: tvCheckBox.checked
                                  ? "#00A6D6"
                                  : "#9CA3AF"

                    Text {
                        anchors.centerIn: parent

                        text: "✓"

                        color: "white"

                        visible: tvCheckBox.checked
                    }
                }
            }

            // =====================================================
            // WASHING MACHINE
            // =====================================================

            CheckBox {

                id: washingCheckBox

                text: {
                    settingsPage.languageVersion
                    return qsTr("Washing Machine")
                }

                checked: false

                Layout.fillWidth: true

                contentItem: Text {

                    text: washingCheckBox.text

                    color: "#374151"

                    verticalAlignment: Text.AlignVCenter

                    leftPadding: 30

                    elide: Text.ElideRight
                }

                indicator: Rectangle {

                    implicitWidth: 20
                    implicitHeight: 20

                    x: washingCheckBox.leftPadding

                    y: parent.height / 2 - height / 2

                    radius: 5

                    color: washingCheckBox.checked
                           ? "#00A6D6"
                           : "#FFFFFF"

                    border.color: washingCheckBox.checked
                                  ? "#00A6D6"
                                  : "#9CA3AF"

                    Text {
                        anchors.centerIn: parent

                        text: "✓"

                        color: "white"

                        visible: washingCheckBox.checked
                    }
                }
            }

            // =====================================================
            // HEATER TEMPERATURE
            // =====================================================

            Label {

                Layout.fillWidth: true

                text: {
                    settingsPage.languageVersion

                    return qsTr("Heater Temperature: ") +
                           Math.round(heaterDial.value) +
                           "°C"
                }

                color: "#374151"

                font.pixelSize: 15
                font.bold: true
            }

            Dial {

                id: heaterDial

                Layout.alignment: Qt.AlignHCenter

                from: 18
                to: 30

                value: 22

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

                    x: heaterDial.background.width / 2 -
                       width / 2

                    y: heaterDial.background.height / 2 -
                       height / 2
                }
            }

            // =====================================================
            // SMART DOOR LOCK
            // =====================================================

            CheckBox {

                id: smartLockCheckBox

                text: {
                    settingsPage.languageVersion
                    return qsTr("Smart Door Lock")
                }

                checked: true

                Layout.fillWidth: true

                contentItem: Text {

                    text: smartLockCheckBox.text

                    color: "#374151"

                    verticalAlignment: Text.AlignVCenter

                    leftPadding: 30

                    elide: Text.ElideRight
                }

                indicator: Rectangle {

                    implicitWidth: 20
                    implicitHeight: 20

                    x: smartLockCheckBox.leftPadding

                    y: parent.height / 2 - height / 2

                    radius: 5

                    color: smartLockCheckBox.checked
                           ? "#00A6D6"
                           : "#FFFFFF"

                    border.color: smartLockCheckBox.checked
                                  ? "#00A6D6"
                                  : "#9CA3AF"

                    Text {

                        anchors.centerIn: parent

                        text: "✓"

                        color: "white"

                        visible: smartLockCheckBox.checked
                    }
                }
            }

            // =====================================================
            // SAVE BUTTON
            // =====================================================

            Button {

                id: saveButton

                text: {
                    settingsPage.languageVersion
                    return qsTr("Save Settings")
                }

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

                    console.log(
                        "========== Settings =========="
                    )

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
                        "Security Camera:",
                        cameraCheckBox.checked
                    )

                    console.log(
                        "Smart TV:",
                        tvCheckBox.checked
                    )

                    console.log(
                        "Washing Machine:",
                        washingCheckBox.checked
                    )

                    console.log(
                        "Heater Temperature:",
                        Math.round(
                            heaterDial.value
                        ) + "°C"
                    )

                    console.log(
                        "Smart Door Lock:",
                        smartLockCheckBox.checked
                    )

                    console.log(
                        "Settings saved successfully (simulation)"
                    )

                    console.log(
                        "=============================="
                    )
                }
            }

            // =====================================================
            // BACK BUTTON
            // =====================================================

            Button {

                id: backButton

                text: {
                    settingsPage.languageVersion
                    return qsTr("Back to Dashboard")
                }

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

                    console.log(
                        "Returning to Dashboard"
                    )

                    if (settingsPage.stackView) {

                        settingsPage.stackView.pop()

                    } else {

                        console.log(
                            "ERROR: StackView reference is missing"
                        )
                    }
                }
            }

            // Bottom spacing
            Item {
                Layout.preferredHeight: 20
            }
        }
    }
}