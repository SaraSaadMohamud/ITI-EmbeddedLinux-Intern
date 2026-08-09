import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page {

    id: searchPage
    property ListModel cartModel

    background: Rectangle {
        color: "#F5F7FA"
    }

    ProductModel {
        id: productModel
    }

    property var searchResults: []

    function performSearch() {

        searchPage.searchResults =
                productModel.searchProducts(
                    searchField.text
                )

        console.log(
            "Search:",
            searchField.text
        )

        console.log(
            "Results:",
            searchPage.searchResults.length
        )
    }

    ScrollView {

        anchors.fill: parent

        clip: true

        ColumnLayout {

            width: searchPage.width

            spacing: 0

            // =================================================
            // SEARCH HERO
            // =================================================

            Rectangle {

                Layout.fillWidth: true
                Layout.preferredHeight: 450

                color: "#0F172A"

                clip: true

                // -------------------------------------------------
                // Background Image
                // -------------------------------------------------

                Image {

                    anchors.fill: parent

                    source: "imags/electronics_bg.png"

                    fillMode:
                        Image.PreserveAspectCrop

                    opacity: 0.30
                }

                // -------------------------------------------------
                // Dark Overlay
                // -------------------------------------------------

                Rectangle {

                    anchors.fill: parent

                    color: "#0F172A"

                    opacity: 0.45
                }

                // -------------------------------------------------
                // Hero Content
                // -------------------------------------------------

                ColumnLayout {

                    anchors.centerIn: parent

                    width:
                        Math.min(
                            searchPage.width - 100,
                            1100
                        )

                    spacing: 14

                    // -------------------------------------------------
                    // Title
                    // -------------------------------------------------

                    Label {

                        text:
                            qsTr("Find What You Need")

                        color: "#FFFFFF"

                        font.pixelSize: 32
                        font.bold: true

                        Layout.alignment:
                            Qt.AlignHCenter
                    }

                    // -------------------------------------------------
                    // Description
                    // -------------------------------------------------

                    Label {

                        text:
                            qsTr(
                                "Search our electronics and find the perfect product for your project"
                            )

                        color: "#CBD5E1"

                        font.pixelSize: 15

                        Layout.fillWidth: true

                        horizontalAlignment:
                            Text.AlignHCenter

                        wrapMode:
                            Text.WordWrap

                        Layout.alignment:
                            Qt.AlignHCenter
                    }

                    // -------------------------------------------------
                    // Search Area
                    // -------------------------------------------------

                    RowLayout {

                        Layout.fillWidth: true

                        Layout.topMargin: 12

                        spacing: 12

                        // -------------------------------------------------
                        // Search Field
                        // -------------------------------------------------

                        TextField {

                            id: searchField

                            Layout.fillWidth: true

                            Layout.preferredHeight: 55

                            placeholderText:
                                qsTr(
                                    "Search by product name, brand, category..."
                                )

                            font.pixelSize: 16

                            leftPadding: 20
                            rightPadding: 20

                            color: "#0F172A"

                            background: Rectangle {

                                radius: 10

                                color: "#FFFFFF"

                                border.color:
                                    searchField.activeFocus
                                    ? "#06B6D4"
                                    : "#CBD5E1"

                                border.width:
                                    searchField.activeFocus
                                    ? 2
                                    : 1
                            }

                            Keys.onReturnPressed: {

                                searchPage.performSearch()
                            }
                        }

                        // -------------------------------------------------
                        // Search Button
                        // -------------------------------------------------

                        Button {

                            id: searchButton

                            Layout.preferredWidth: 125
                            Layout.preferredHeight: 55

                            text:
                                qsTr("Search")

                            contentItem: Text {

                                text:
                                    searchButton.text

                                color: "#FFFFFF"

                                font.pixelSize: 15
                                font.bold: true

                                horizontalAlignment:
                                    Text.AlignHCenter

                                verticalAlignment:
                                    Text.AlignVCenter
                            }

                            background: Rectangle {

                                radius: 10

                                color:
                                    searchButton.pressed
                                    ? "#0891B2"
                                    : "#06B6D4"
                            }

                            onClicked: {

                                searchPage.performSearch()
                            }
                        }
                    }

                    // -------------------------------------------------
                    // Results Count
                    // -------------------------------------------------

                    Label {

                        visible:
                            searchField.text.trim() !== ""

                        text:
                            searchPage.searchResults.length
                            + " "
                            + qsTr("products found")

                        color: "#CBD5E1"

                        font.pixelSize: 14
                        Layout.topMargin: 4

                        Layout.alignment:
                            Qt.AlignHCenter
                    }
                }
            }

            // =================================================
            // SEARCH RESULTS
            // =================================================

            ColumnLayout {

                Layout.fillWidth: true

                Layout.leftMargin: 35
                Layout.rightMargin: 35
                Layout.topMargin: 35
                Layout.bottomMargin: 40

                spacing: 20

                // =================================================
                // PRODUCTS GRID
                // =================================================

                GridLayout {

                    Layout.fillWidth: true

                    columns: 6

                    rowSpacing: 20
                    columnSpacing: 20

                    Repeater {

                        model:
                            searchPage.searchResults

                        delegate: ProductCard {

                            // IMPORTANT:
                            // Do NOT use Layout.fillWidth here

                            productName:
                                modelData.productName

                            productImage:
                                modelData.productImage

                            productPrice:
                                modelData.productPrice

                            productCategory:
                                modelData.productCategory

                            productAvailable:
                                modelData.productAvailable

                            productBrand:
                                modelData.productBrand

                            productVersion:
                                modelData.productVersion

                            productColor:
                                modelData.productColor

                            productVoltage:
                                modelData.productVoltage

                            productInterface:
                                modelData.productInterface

                            onAddToCartClicked: {


                                cartModel.addProduct(modelData)
                                console.log(
                                    "Added to cart:",
                                    modelData.productName
                                )
                            }
                        }
                    }
                }

                // =================================================
                // NO RESULTS
                // =================================================

                Item {

                    visible:
                        searchField.text.trim() !== ""
                        && searchPage.searchResults.length === 0

                    Layout.fillWidth: true

                    Layout.preferredHeight: 300

                    ColumnLayout {

                        anchors.centerIn: parent

                        spacing: 10

                        // -------------------------------------------------
                        // Search Icon
                        // -------------------------------------------------

                        Label {

                            text: "🔍"

                            font.pixelSize: 45

                            Layout.alignment:
                                Qt.AlignHCenter
                        }

                        // -------------------------------------------------
                        // No Products Text
                        // -------------------------------------------------

                        Label {

                            text:
                                qsTr(
                                    "No products found"
                                )

                            font.pixelSize: 20

                            font.bold: true

                            color: "#334155"

                            Layout.alignment:
                                Qt.AlignHCenter

                            horizontalAlignment:
                                Text.AlignHCenter
                        }

                        // -------------------------------------------------
                        // Description
                        // -------------------------------------------------

                        Label {

                            text:
                                qsTr(
                                    "Try another product name, brand or category."
                                )

                            font.pixelSize: 14

                            color: "#64748B"

                            Layout.alignment:
                                Qt.AlignHCenter

                            horizontalAlignment:
                                Text.AlignHCenter
                        }
                    }
                }
            }
        }
    }
}