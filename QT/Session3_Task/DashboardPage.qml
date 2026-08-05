import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: dashboardPage

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

            Label {
                text: "Smart Home Dashboard"

                font.pixelSize: 28
                font.bold: true

                Layout.fillWidth: true
            }


            Button {
                id: settingsButton

                text: "Settings"

                background: Rectangle {

                    radius: 8

                    color: {

                        if (!settingsButton.enabled)
                            return "#D1D5DB"

                        if (settingsButton.pressed)
                            return "#007A9E"

                        if (settingsButton.hovered)
                            return "#008FB8"

                        return "#00A6D6"
                    }
                }

                onClicked: {
                    console.log("Opening Settings")
                    console.log("StackView:", StackView.view)

                    StackView.view.push("SettingsPage.qml")
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

                                // Energy Usage

                                value: model.usage


                                background: Rectangle {

                                    implicitHeight: 8

                                    radius: 4

                                    color: "#E5E7EB"
                                }


                                contentItem: Item {

                                    Rectangle {

                                        width: usageBar.visualPosition
                                               * parent.width

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

                                Layout.alignment: Qt.AlignHCenter

                                checked: model.status

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