import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page {

    id: homePage

    signal exploreProductsClicked()

    property string selectedCategory: ""
    property bool showAllProducts: false
    property bool showingAllProducts: false

    background: Rectangle {
        color: "#F5F7FA"
    }

    ProductModel{
        id: productModel
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
                Layout.preferredHeight: 750
                color: "#0F172A"

                clip: true
                Image {
                    anchors.fill: parent
                    source: "imags/electronics_bg.png"
                    fillMode: Image.PreserveAspectCrop
                    opacity: 0.30
                }

                Rectangle {
                    anchors.fill: parent
                    color: "#0F172A"
                    opacity: 0.40
                }

                ColumnLayout {
                    anchors.centerIn: parent
                    spacing: 12
                    width: parent.width * 0.8
                    anchors.verticalCenterOffset: 65

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
                        font.pixelSize: 20
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

                        onClicked: {
                            homePage.exploreProductsClicked()
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
                            { name: "Electronic Components", icon: "🔧" },
                            { name: "Robotics", icon: "🤖" },
                            { name: "Development Boards", icon: "🛠️" },
                            { name: "Sensors", icon: "📡" },
                            { name: "Electronic Tools", icon: "⚙️" }
                        ]

                        delegate: Rectangle {

                            property bool selected:
                                homePage.selectedCategory === modelData.name

                            color: selected
                                   ? "#E0F7FA"
                                   : "#FFFFFF"

                            Layout.fillWidth: true
                            Layout.preferredHeight: 90

                            radius: 14

                            border.color:
                                selected
                                ? "#0891B2"
                                : "#E2E8F0"

                            border.width:
                                selected ? 2 : 1

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

                            MouseArea {
                                anchors.fill: parent

                                cursorShape: Qt.PointingHandCursor

                                onClicked: {

                                    if (homePage.selectedCategory === modelData.name) {

                                        homePage.selectedCategory = ""

                                    } else {

                                        homePage.selectedCategory = modelData.name
                                    }

                                    homePage.showAllProducts = false
                                    homePage.showingAllProducts = false

                                    console.log(
                                        "Selected Category:",
                                        homePage.selectedCategory
                                    )
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
                    text: homePage.showingAllProducts
                          ? (homePage.selectedCategory === ""
                             ? qsTr("All Store Products")
                             : qsTr(homePage.selectedCategory))
                          : (homePage.selectedCategory === ""
                             ? qsTr("Popular Products")
                             : qsTr(homePage.selectedCategory))

                    Layout.fillWidth: true
                    font.pixelSize: 28
                    font.bold: true
                    color: "#111827"
                }

                // =========================================
                // VIEW ALL / SHOW ALL BUTTON
                // =========================================
                Button {
                    id: viewAllButton
                    visible: homePage.selectedCategory !== ""
                             && !homePage.showingAllProducts

                    text: qsTr("Show All →")

                    flat: true

                    contentItem: Text {
                        text: viewAllButton.text
                        color: "#0891B2"
                        font.bold: true

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    onClicked: {
                        homePage.showAllProducts = true
                        homePage.showingAllProducts = true
                    }
                }


                // =========================================
                // RETURN TO POPULAR
                // =========================================
                Button {
                    id: returnButton

                    visible: homePage.showingAllProducts

                    text: qsTr("Return")

                    flat: true

                    contentItem: Text {
                        text: returnButton.text
                        color: "#64748B"
                        font.bold: true

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    onClicked: {

                        homePage.showAllProducts = false
                        homePage.showingAllProducts = false
                        homePage.selectedCategory = ""
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

                columns: 6

                rowSpacing: 20
                columnSpacing: 20

                Repeater {

                    model: {

                        // =====================================
                        // CATEGORY SELECTED
                        // =====================================
                        if (homePage.selectedCategory !== "") {

                            var categoryProducts =
                                    productModel.getProductsByCategory(
                                        homePage.selectedCategory
                                    )
                            if (homePage.showAllProducts) {
                                return categoryProducts
                            }
                            return categoryProducts.slice(0, 6)
                        }

                        // =====================================
                        // NO CATEGORY SELECTED
                        // =====================================
                        if (homePage.showAllProducts) {
                            var allProducts = []

                            for (var j = 0; j < productModel.count; j++) {
                                allProducts.push(productModel.get(j))
                            }

                            return allProducts
                        }

                        // =====================================
                        // POPULAR PRODUCTS
                        // =====================================

                        var popularProducts = []

                        for (
                            var i = 0;
                            i < Math.min(12, productModel.count);
                            i++
                        ) {
                            popularProducts.push(
                                productModel.get(i)
                            )
                        }

                        return popularProducts
                    }

                    delegate: ProductCard {

                        productName: modelData.productName
                        productImage: modelData.productImage
                        productPrice: modelData.productPrice
                        productCategory: modelData.productCategory
                        productAvailable: modelData.productAvailable

                        productBrand: modelData.productBrand
                        productVersion: modelData.productVersion
                        productColor: modelData.productColor
                        productVoltage: modelData.productVoltage
                        productInterface: modelData.productInterface

                        onAddToCartClicked: {

                            console.log(
                                "Cart:",
                                productName
                            )
                        }
                    }
                }
            }
        }
    }
}
}