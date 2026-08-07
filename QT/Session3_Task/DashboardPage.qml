import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: dashboardPage

    property StackView stackView
    property int languageVersion: 0

    // =====================================================
    // Language
    // =====================================================

    Connections {
        target: languageManager

        function onLanguageChanged() {
            dashboardPage.languageVersion++
        }
    }

    // =====================================================
    // Background
    // =====================================================

    background: Rectangle {
        color: "#F4F7FB"
    }

    // =====================================================
    // Devices Model
    // =====================================================

    ListModel {
        id: devicesModel

        // -------------------------------------------------
        // 1 - Living Room Light
        // -------------------------------------------------

        ListElement {
            name: "Living Room Light"
            image: "images/light.png"
            status: false
            usage: 0.75
        }

        // -------------------------------------------------
        // 2 - Bedroom Light
        // -------------------------------------------------

        ListElement {
            name: "Bedroom Light"
            image: "images/bedroom_light.png"
            status: false
            usage: 0.35
        }

        // -------------------------------------------------
        // 3 - Air Conditioner
        // -------------------------------------------------

        ListElement {
            name: "Air Conditioner"
            image: "images/air_conditioner.png"
            status: false
            usage: 0.60
        }

        // -------------------------------------------------
        // 4 - Fan
        // -------------------------------------------------

        ListElement {
            name: "Fan"
            image: "images/fan.png"
            status: false
            usage: 0.25
        }

        // -------------------------------------------------
        // 5 - Garage Door
        // -------------------------------------------------

        ListElement {
            name: "Garage Door"
            image: "images/garage_door.png"
            status: false
            usage: 0.45
        }

        // -------------------------------------------------
        // 6 - Security Camera
        // -------------------------------------------------

        ListElement {
            name: "Security Camera"
            image: "images/security_camera.png"
            status: false
            usage: 0.55
        }

        // -------------------------------------------------
        // 7 - Smart TV
        // -------------------------------------------------

        ListElement {
            name: "Smart TV"
            image: "images/smart_tv.png"
            status: false
            usage: 0.40
        }

        // -------------------------------------------------
        // 8 - Washing Machine
        // -------------------------------------------------

        ListElement {
            name: "Washing Machine"
            image: "images/washing_machine.png"
            status: false
            usage: 0.65
        }

        // -------------------------------------------------
        // 9 - Heater
        // -------------------------------------------------

        ListElement {
            name: "Heater"
            image: "images/thermostat.png"
            status: false
            usage: 0.50
        }

        // -------------------------------------------------
        // 10 - Smart Door Lock
        // -------------------------------------------------

        ListElement {
            name: "Smart Door Lock"
            image: "images/smart_lock.png"
            status: false
            usage: 0.20
        }
    }

    // =====================================================
    // Main Layout
    // =====================================================

    ColumnLayout {

        anchors.fill: parent

        anchors.margins: 25

        spacing: 20

        // =================================================
        // HEADER
        // =================================================

        RowLayout {

            Layout.fillWidth: true

            spacing: 10

            // ---------------------------------------------
            // Dashboard Title
            // ---------------------------------------------

            Label {

                text: {
                    dashboardPage.languageVersion

                    return qsTr(
                        "Smart Home Dashboard"
                    )
                }

                font.pixelSize: 28

                font.bold: true

                Layout.fillWidth: true
            }

            // ---------------------------------------------
            // Settings Button
            // ---------------------------------------------

            Button {

                id: settingsButton

                text: {
                    dashboardPage.languageVersion

                    return qsTr("Settings")
                }

                contentItem: Text {

                    text: settingsButton.text

                    color: "#FFFFFF"

                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 8

                    color: {

                        if (settingsButton.pressed)
                            return "#007A9E"

                        if (settingsButton.hovered)
                            return "#008FB8"

                        return "#00A6D6"
                    }
                }

                onClicked: {

                    console.log(
                        "Opening Settings"
                    )

                    if (dashboardPage.stackView) {

                        dashboardPage.stackView.push(
                            "SettingsPage.qml",
                            {
                                stackView:
                                    dashboardPage.stackView
                            }
                        )

                    } else {

                        console.log(
                            "ERROR: StackView reference is missing"
                        )
                    }
                }
            }

            // ---------------------------------------------
            // Logout Button
            // ---------------------------------------------

            Button {

                id: logoutButton

                text: {

                    dashboardPage.languageVersion

                    return qsTr("Logout")
                }

                contentItem: Text {

                    text: logoutButton.text

                    color: "#FFFFFF"

                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 8

                    color: {

                        if (logoutButton.pressed)
                            return "#991B1B"

                        if (logoutButton.hovered)
                            return "#DC2626"

                        return "#EF4444"
                    }
                }

                onClicked: {

                    console.log(
                        "Logging out"
                    )

                    if (dashboardPage.stackView) {

                        dashboardPage.stackView.pop()
                    }
                }
            }
        }

        // =================================================
        // DEVICES LIST
        // =================================================

        ScrollView {

            Layout.fillWidth: true

            Layout.fillHeight: true

            clip: true

            ListView {

                id: devicesList

                width: parent.width

                spacing: 15

                model: devicesModel

                // =================================================
                // DEVICE CARD
                // =================================================

                delegate: Rectangle {

                    width: devicesList.width

                    height: 120

                    radius: 15

                    color: "white"

                    // ---------------------------------------------
                    // Device Row
                    // ---------------------------------------------

                    RowLayout {

                        anchors.fill: parent

                        anchors.margins: 15

                        spacing: 20

                        // -----------------------------------------
                        // Device Image
                        // -----------------------------------------

                        Image {

                            Layout.preferredWidth: 70

                            Layout.preferredHeight: 70

                            fillMode:
                                Image.PreserveAspectFit

                            source: model.image
                        }

                        // -----------------------------------------
                        // Device Name + Usage
                        // -----------------------------------------

                        ColumnLayout {

                            Layout.fillWidth: true

                            spacing: 10

                            Label {

                                text: {

                                    dashboardPage.languageVersion

                                    if (
                                        model.name ===
                                        "Living Room Light"
                                    )
                                        return qsTr(
                                            "Living Room Light"
                                        )

                                    if (
                                        model.name ===
                                        "Bedroom Light"
                                    )
                                        return qsTr(
                                            "Bedroom Light"
                                        )

                                    if (
                                        model.name ===
                                        "Air Conditioner"
                                    )
                                        return qsTr(
                                            "Air Conditioner"
                                        )

                                    if (
                                        model.name ===
                                        "Fan"
                                    )
                                        return qsTr(
                                            "Fan"
                                        )

                                    if (
                                        model.name ===
                                        "Garage Door"
                                    )
                                        return qsTr(
                                            "Garage Door"
                                        )

                                    if (
                                        model.name ===
                                        "Kitchen Light"
                                    )
                                        return qsTr(
                                            "Kitchen Light"
                                        )

                                    if (
                                        model.name ===
                                        "Smart TV"
                                    )
                                        return qsTr(
                                            "Smart TV"
                                        )

                                    if (
                                        model.name ===
                                        "Washing Machine"
                                    )
                                        return qsTr(
                                            "Washing Machine"
                                        )

                                    if (
                                        model.name ===
                                        "Heater"
                                    )
                                        return qsTr(
                                            "Heater"
                                        )

                                    if (
                                        model.name ===
                                        "Smart Door Lock"
                                    )
                                        return qsTr(
                                            "Smart Door Lock"
                                        )

                                    return model.name
                                }

                                font.pixelSize: 20

                                font.bold: true
                            }

                            // -----------------------------------------
                            // Usage Bar
                            // -----------------------------------------

                            ProgressBar {

                                id: usageBar

                                Layout.fillWidth: true

                                value: model.usage

                                background: Rectangle {

                                    implicitHeight: 8

                                    radius: 4

                                    color: "#E5E7EB"
                                }

                                contentItem: Item {

                                    Rectangle {

                                        width:
                                            usageBar.visualPosition *
                                            parent.width

                                        height:
                                            parent.height

                                        radius: 4

                                        color: "#00B4D8"
                                    }
                                }
                            }

                            // -----------------------------------------
                            // Usage Percentage
                            // -----------------------------------------

                            Label {

                                text:
                                    Math.round(
                                        model.usage * 100
                                    ) + "%"

                                font.pixelSize: 12

                                color: "#6B7280"
                            }
                        }

                        // -----------------------------------------
                        // Switch + Status
                        // -----------------------------------------

                        ColumnLayout {

                            Layout.alignment:
                                Qt.AlignVCenter

                            spacing: 3

                            Switch {

                                id: deviceSwitch

                                checked: model.status

                                indicator: Rectangle {

                                    implicitWidth: 45

                                    implicitHeight: 25

                                    radius: 13

                                    color:
                                        deviceSwitch.checked
                                        ? "#00A6D6"
                                        : "#D1D5DB"

                                    Rectangle {

                                        width: 19

                                        height: 19

                                        radius: 10

                                        anchors.verticalCenter:
                                            parent.verticalCenter

                                        x:
                                            deviceSwitch.checked
                                            ? parent.width -
                                              width - 3
                                            : 3

                                        color: "white"
                                    }
                                }

                                onToggled: {

                                    console.log(
                                        model.name +
                                        " is now " +
                                        (
                                            checked
                                            ? "ON"
                                            : "OFF"
                                        )
                                    )
                                }
                            }

                            Label {

                                Layout.alignment:
                                    Qt.AlignHCenter

                                text: {

                                    dashboardPage.languageVersion

                                    return deviceSwitch.checked
                                           ? qsTr("ON")
                                           : qsTr("OFF")
                                }

                                font.pixelSize: 14

                                font.bold: true

                                color:
                                    deviceSwitch.checked
                                    ? "#00A6D6"
                                    : "#6B7280"
                            }
                        }
                    }
                }
            }
        }
    }
}