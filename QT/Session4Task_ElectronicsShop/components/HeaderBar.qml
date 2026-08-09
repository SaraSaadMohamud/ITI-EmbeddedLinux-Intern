import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Rectangle{
    id:headerBar
    width: parent?parent.width : 1000
    height: 75
    color: "#0F172A"

    // =====================================================
    // Signals
    // =====================================================

    signal homeClicked()
    signal productsClicked()
    signal categoriesClicked()
    signal searchClicked()
    signal languageSelected(string language)
    signal cartClicked()

    Rectangle {

        anchors.bottom: parent.bottom
        width: parent.width
        height: 2
        color: "#00C2FF"
        opacity: 0.8
        }

    RowLayout {

        anchors.fill: parent

        anchors.leftMargin: 30
        anchors.rightMargin: 30

        spacing: 25

            Image {
                source: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/logo.png"
                Layout.preferredWidth: 150
                Layout.preferredHeight: 60
                fillMode: Image.PreserveAspectFit
                smooth: true
                antialiasing: true

            }
            Button {

                id: homeButton

                text: qsTr("Home")

                flat: true

                contentItem: Text {

                    text: homeButton.text

                    color: homeButton.hovered
                           ? "#00C2FF"
                           : "#E2E8F0"

                    font.pixelSize: homeButton.hovered?16:14
                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 8

                    color: homeButton.hovered
                           ? "#1E293B"
                           : "transparent"
                }

                onClicked: {

                    console.log("Home clicked")
                    headerBar.homeClicked()
                }
            }

            // =============================================
            // Products
            // =============================================

            Button {

                id: productsButton

                text: qsTr("Products")

                flat: true

                contentItem: Text {

                    text: productsButton.text

                    color: productsButton.hovered
                           ? "#00C2FF"
                           : "#E2E8F0"

                    font.pixelSize: productsButton.hovered?16:14
                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 8

                    color: productsButton.hovered
                           ? "#1E293B"
                           : "transparent"
                }

                onClicked: {

                    console.log("Products clicked")
                    headerBar.productsClicked()
                }
            }


            // =============================================
            // Categories
            // =============================================

            Button {

                id: categoriesButton

                text: qsTr("Categories")

                flat: true

                contentItem: Text {

                    text: categoriesButton.text

                    color: categoriesButton.hovered
                           ? "#00C2FF"
                           : "#E2E8F0"

                    font.pixelSize: categoriesButton.hovered?16:14
                    font.bold: true
                    horizontalAlignment:Text.AlignHCenter
                    verticalAlignment:Text.AlignVCenter
                }

                background: Rectangle {
                    radius: 8
                    color: categoriesButton.hovered
                           ? "#1E293B"
                           : "transparent"
                }

                onClicked: {
                    console.log("Categories clicked")
                    headerBar.categoriesClicked()
                }

        }
        Item {
            Layout.fillWidth: true
        }

        RowLayout {

            Layout.alignment: Qt.AlignVCenter

            spacing: 10

            // =============================================
            // Search Button
            // =============================================

            Button {

                id: searchButton

                width: 42
                height: 42

                text: "⌕"

                flat: true

                contentItem: Text {

                    text: searchButton.text

                    color: searchButton.hovered
                           ? "#00C2FF"
                           : "#E2E8F0"

                    font.pixelSize: searchButton.hovered?35:30
                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 10

                    color: searchButton.hovered
                           ? "#1E293B"
                           : "transparent"
                }

                onClicked: {
                    console.log("Search clicked")
                    headerBar.searchClicked()
                }
            }

            // =============================================
            // Language Button
            // =============================================

            Button {

                id: languageButton

                width: 70
                height: 42

                text: "🌐 EN"

                flat: true

                contentItem: Text {

                    text: languageButton.text

                    color: languageButton.hovered
                           ? "#00C2FF"
                           : "#E2E8F0"

                    font.pixelSize: languageButton.hovered ? 16 : 14
                    font.bold: true

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 10

                    color: languageButton.hovered
                           ? "#1E293B"
                           : "transparent"
                }

                onClicked: {
                    languagePopup.open()

                }
            }


            // =============================================
            // Language Popup
            // =============================================

            Popup {

                id: languagePopup

                x: languageButton.x + languageButton.width - width
                y: languageButton.y + languageButton.height + 8

                width: 190
                height: 210

                padding: 10

                modal: false

                closePolicy:
                    Popup.CloseOnEscape |
                    Popup.CloseOnPressOutside


                background: Rectangle {

                    radius: 12

                    color: "#FFFFFF"

                    border.color: "#E2E8F0"
                    border.width: 1
                }


                ColumnLayout {

                    anchors.fill: parent

                    spacing: 5


                    Label {

                        text: "🌐  " + qsTr("Language")

                        color: "#0F172A"

                        font.pixelSize: 15
                        font.bold: true

                        Layout.leftMargin: 8
                        Layout.bottomMargin: 5
                    }


                    // =====================================
                    // English
                    // =====================================

                    Button {

                        id: englishButton

                        text: "🇬🇧  English"

                        Layout.fillWidth: true
                        Layout.preferredHeight: 38

                        flat: true

                        contentItem: Text {

                            text: englishButton.text

                            color: "#334155"

                            font.pixelSize: 14

                            horizontalAlignment:
                                Text.AlignLeft

                            verticalAlignment:
                                Text.AlignVCenter

                            leftPadding: 10
                        }

                        background: Rectangle {

                            radius: 8

                            color:
                                englishButton.hovered
                                ? "#E0F7FA"
                                : "transparent"
                        }

                        onClicked: {

                            languageButton.text = "🌐 EN"

                            languagePopup.close()

                            headerBar.languageSelected("en")
                        }
                    }


                    // =====================================
                    // Arabic
                    // =====================================

                    Button {

                        id: arabicButton

                        text: "🇪🇬  العربية"

                        Layout.fillWidth: true
                        Layout.preferredHeight: 38

                        flat: true

                        contentItem: Text {

                            text: arabicButton.text

                            color: "#334155"

                            font.pixelSize: 14

                            horizontalAlignment:
                                Text.AlignLeft

                            verticalAlignment:
                                Text.AlignVCenter

                            leftPadding: 10
                        }

                        background: Rectangle {

                            radius: 8

                            color:
                                arabicButton.hovered
                                ? "#E0F7FA"
                                : "transparent"
                        }

                        onClicked: {

                            languageButton.text = "🌐 AR"

                            languagePopup.close()

                            headerBar.languageSelected("ar")
                        }
                    }


                    // =====================================
                    // French
                    // =====================================

                    Button {

                        id: frenchButton

                        text: "🇫🇷  Français"

                        Layout.fillWidth: true
                        Layout.preferredHeight: 38

                        flat: true

                        contentItem: Text {

                            text: frenchButton.text

                            color: "#334155"

                            font.pixelSize: 14

                            horizontalAlignment:
                                Text.AlignLeft

                            verticalAlignment:
                                Text.AlignVCenter

                            leftPadding: 10
                        }

                        background: Rectangle {

                            radius: 8

                            color:
                                frenchButton.hovered
                                ? "#E0F7FA"
                                : "transparent"
                        }

                        onClicked: {

                            languageButton.text = "🌐 FR"

                            languagePopup.close()

                            headerBar.languageSelected("fr")
                        }
                    }


                    // =====================================
                    // German
                    // =====================================

                    Button {

                        id: germanButton

                        text: "🇩🇪  Deutsch"

                        Layout.fillWidth: true
                        Layout.preferredHeight: 38

                        flat: true

                        contentItem: Text {

                            text: germanButton.text

                            color: "#334155"

                            font.pixelSize: 14

                            horizontalAlignment:
                                Text.AlignLeft

                            verticalAlignment:
                                Text.AlignVCenter

                            leftPadding: 10
                        }

                        background: Rectangle {

                            radius: 8

                            color:
                                germanButton.hovered
                                ? "#E0F7FA"
                                : "transparent"
                        }

                        onClicked: {

                            languageButton.text = "🌐 DE"

                            languagePopup.close()

                            headerBar.languageSelected("de")
                        }
                    }
                }
            }

            // =============================================
            // Cart
            // =============================================


            Button {

                id: cartButton

                width: 48
                height: 42

                text: "🛒"

                flat: true

                contentItem: Text {

                    text: cartButton.text

                    color: cartButton.hovered
                           ?"#00C2FF"
                           : "#E2E8F0"

                    font.pixelSize: cartButton.hovered?25:20
                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 10

                    color: cartButton.hovered
                           ? "#1E293B"
                           : "transparent"
                }

                onClicked: {

                    console.log("Cart clicked")
                    headerBar.cartClicked()
                }
            }
        }
    }
}
