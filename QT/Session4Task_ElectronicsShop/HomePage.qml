import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page {
    id: homePage
    background: Rectangle {
        color: "#F5F7FA"
    }

    ScrollView {
        anchors.fill: parent
        clip: true

        ColumnLayout {
            width: homePage.width
            spacing: 0

            // =========================================
            // HERO SECTION
            // =========================================
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 380
                color: "#0F172A"

                clip: true
                Image {
                    anchors.fill: parent
                    source: "imags/electronics_bg.png"
                    fillMode: Image.PreserveAspectCrop
                    opacity: 0.50
                }

                Rectangle {
                    anchors.fill: parent
                    color: "#0F172A"
                    opacity: 0.65
                }
                ColumnLayout {
                    anchors.centerIn: parent
                    spacing: 12
                    width: parent.width * 0.8

                    Label {
                        text: qsTr("Build. Create. Innovate.")
                        color: "#FFFFFF"
                        font.bold: true
                        font.pixelSize: 42
                        Layout.alignment: Qt.AlignHCenter
                    }

                    Label {
                        text: qsTr("Premium Electronics for Makers, Engineers & Robotics")
                        color: "#CBD5E1"
                        font.pixelSize: 18
                        Layout.alignment: Qt.AlignHCenter
                        wrapMode: Text.WordWrap
                        horizontalAlignment: Text.AlignHCenter
                    }

                    Button {
                        id: exploreButton
                        text: qsTr("Explore Products")
                        Layout.preferredWidth: 190
                        Layout.preferredHeight: 48
                        Layout.topMargin: 15
                        Layout.alignment: Qt.AlignHCenter

                        contentItem: Text {
                            text: exploreButton.text
                            color: "#FFFFFF"
                            font.pixelSize: 15
                            font.bold: true
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        background: Rectangle {
                            radius: 10
                            color: exploreButton.pressed ? "#0891B2" : "#06B6D4"
                        }
                    }
                }
            }

            // =========================================
            // CATEGORIES SECTION
            // =========================================
            ColumnLayout {
                Layout.fillWidth: true
                Layout.margins: 35
                spacing: 18

                Label {
                    text: qsTr("Shop by Category")
                    color: "#111827"
                    font.pixelSize: 28
                    font.bold: true
                }

                RowLayout {
                    Layout.fillWidth: true
                    spacing: 15

                    Repeater {
                        model: [
                            { name: "Embedded Systems", icon: "🔌" },
                            { name: "Robotics", icon: "🤖" },
                            { name: "Development Boards", icon: "🛠️" },
                            { name: "Sensors", icon: "📡" },
                            { name: "Electronic Tools", icon: "⚙️" }
                        ]

                        delegate: Rectangle {
                            color: "#FFFFFF"
                            Layout.fillWidth: true
                            Layout.preferredHeight: 90
                            radius: 14
                            border.color: "#E2E8F0"
                            border.width: 1

                            ColumnLayout {
                                anchors.centerIn: parent
                                spacing: 6

                                Label {
                                    text: modelData.icon
                                    font.pixelSize: 24
                                    Layout.alignment: Qt.AlignHCenter
                                }

                                Label {
                                    text: qsTr(modelData.name)
                                    font.pixelSize: 13
                                    font.bold: true
                                    color: "#334155"
                                    Layout.alignment: Qt.AlignHCenter
                                    horizontalAlignment: Text.AlignHCenter
                                    wrapMode: Text.WordWrap
                                }
                            }
                        }
                    }
                }
            }

            // =========================================
            // POPULAR PRODUCTS TITLE
            // =========================================
            RowLayout {
                Layout.fillWidth: true
                Layout.leftMargin: 35
                Layout.rightMargin: 35
                Layout.topMargin: 10

                Label {
                    text: qsTr("Popular Products")
                    Layout.fillWidth: true
                    font.pixelSize: 28
                    font.bold: true
                    color: "#111827"
                }

                Button {
                    id: viewAllButton
                    text: qsTr("View All →")
                    flat: true

                    contentItem: Text {
                        text: viewAllButton.text
                        color: "#0891B2"
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }

            // =========================================
            // PRODUCTS
            // =========================================
            GridLayout {
                Layout.fillWidth: true
                Layout.leftMargin: 35
                Layout.rightMargin: 35
                Layout.topMargin: 15
                Layout.bottomMargin: 40
                columns: 5
                rowSpacing: 20
                columnSpacing: 20

                Repeater {
                    model: 10

                    delegate: Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 270
                        color: "#FFFFFF"
                        radius: 16
                        border.color: "#E2E8F0"
                        border.width: 1

                        ColumnLayout {
                            anchors.fill: parent
                            spacing: 8
                            anchors.margins: 14

                            // صورة المنتج
                            Rectangle {
                                Layout.fillWidth: true
                                Layout.preferredHeight: 140
                                radius: 12
                                color: "#F1F5F9"
                                clip: true

                                Label {
                                    anchors.centerIn: parent
                                    text: "📦"
                                    font.pixelSize: 42
                                    color: "#94A3B8"
                                }
                            }

                            Label {
                                text: qsTr("Arduino Uno R3")
                                font.pixelSize: 15
                                font.bold: true
                                color: "#1E293B"
                                elide: Text.ElideRight
                                Layout.fillWidth: true
                            }

                            Label {
                                text: "$24.99"
                                font.pixelSize: 17
                                font.bold: true
                                color: "#0891B2"
                            }

                            Button {
                                id: addToCart
                                text: qsTr("Add to Cart")
                                Layout.fillWidth: true

                                contentItem: Text {
                                    text: addToCart.text
                                    color: "#FFFFFF"
                                    font.bold: true
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }

                                background: Rectangle {
                                    color: "#0F172A"
                                    radius: 8
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}