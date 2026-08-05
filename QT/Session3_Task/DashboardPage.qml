import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: dashboardPage

    property StackView stackView

    background: Rectangle {
        color: "#F4F7FB"
    }

    ListModel {
        id: devicesModel

        ListElement {
            name: "Living Room Light"
            image: "images/light.png"
            status: false
            usage: 0.75
        }

        ListElement {
            name: "Bedroom Light"
            image: "images/bedroom_light.png"
            status: false
            usage: 0.35
        }

        ListElement {
            name: "Air Conditioner"
            image: "images/air_conditioner.png"
            status: false
            usage: 0.60
        }

        ListElement {
            name: "Fan"
            image: "images/fan.png"
            status: false
            usage: 0.25
        }

        ListElement {
            name: "Garage Door"
            image: "images/garage_door.png"
            status: false
            usage: 0.45
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 25
        spacing: 20

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Label {
                text: "Smart Home Dashboard"
                font.pixelSize: 28
                font.bold: true
                Layout.fillWidth: true
            }

            Button {
                id: settingsButton

                text: "Settings"

                contentItem: Text {
                    text: settingsButton.text
                    color: "#FFFFFF"
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
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
                    console.log("Opening Settings")

                    if (dashboardPage.stackView) {

                        dashboardPage.stackView.push(
                            "SettingsPage.qml",
                            {
                                stackView: dashboardPage.stackView
                            }
                        )

                    } else {
                        console.log("ERROR: StackView reference is missing")
                    }
                }
            }

            Button {
                id: logoutButton

                text: "Logout"

                contentItem: Text {
                    text: logoutButton.text
                    color: "#FFFFFF"
                    font.bold: true

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
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
                    console.log("Logging out")

                    if (dashboardPage.stackView) {
                        dashboardPage.stackView.pop()
                    }
                }
            }
        }

        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            ListView {
                id: devicesList

                width: parent.width
                spacing: 15
                model: devicesModel

                delegate: Rectangle {
                    width: devicesList.width
                    height: 120
                    radius: 15
                    color: "white"

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        spacing: 20

                        Image {
                            Layout.preferredWidth: 70
                            Layout.preferredHeight: 70
                            fillMode: Image.PreserveAspectFit
                            source: model.image
                        }

                        ColumnLayout {
                            Layout.fillWidth: true
                            spacing: 10

                            Label {
                                text: model.name
                                font.pixelSize: 20
                                font.bold: true
                            }

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
                                        width: usageBar.visualPosition * parent.width
                                        height: parent.height
                                        radius: 4
                                        color: "#00B4D8"
                                    }
                                }
                            }
                        }

                        ColumnLayout {
                            Layout.alignment: Qt.AlignVCenter
                            spacing: 3

                            Switch {
                                id: deviceSwitch

                                checked: model.status

                                indicator: Rectangle {
                                    implicitWidth: 45
                                    implicitHeight: 25
                                    radius: 13

                                    color: deviceSwitch.checked
                                           ? "#00A6D6"
                                           : "#D1D5DB"

                                    Rectangle {
                                        width: 19
                                        height: 19
                                        radius: 10

                                        anchors.verticalCenter: parent.verticalCenter

                                        x: deviceSwitch.checked
                                           ? parent.width - width - 3
                                           : 3

                                        color: "white"
                                    }
                                }

                                onToggled: {
                                    console.log(
                                        model.name +
                                        " is now " +
                                        (checked ? "ON" : "OFF")
                                    )
                                }
                            }

                            Label {
                                Layout.alignment: Qt.AlignHCenter

                                text: deviceSwitch.checked ? "ON" : "OFF"

                                font.pixelSize: 14
                                font.bold: true

                                color: deviceSwitch.checked
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