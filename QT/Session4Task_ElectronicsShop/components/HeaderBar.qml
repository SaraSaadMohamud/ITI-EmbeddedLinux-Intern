import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Rectangle{
    id:headerBar
    width: parent?parent.width : 1000
    height: 75
    color: "transparent"

    // =====================================================
    // Signals
    // =====================================================

    signal homeClicked()
    signal productsClicked()
    signal categoriesClicked()
    signal searchClicked()
    signal languageClicked()
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

        spacing: 10

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

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
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

                    font.pixelSize: languageButton.hovered?16:14
                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }

                background: Rectangle {

                    radius: 10

                    color: languageButton.hovered
                           ? "#1E293B"
                           : "transparent"
                }

                onClicked: {

                    console.log("Language clicked")

                    headerBar.languageClicked()
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
