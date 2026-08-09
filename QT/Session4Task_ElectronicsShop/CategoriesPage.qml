import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page {

    id: categoriesPage
    property ListModel cartModel

    background: Rectangle {
        color: "#F5F7FA"
    }

    ProductModel {
        id: productModel
    }

    property string selectedCategory: ""

    ScrollView {

        anchors.fill: parent
        clip: true

        ColumnLayout {

            width: categoriesPage.width
            spacing: 0

            Rectangle {

                Layout.fillWidth: true
                Layout.preferredHeight: 450

                color: "#0F172A"

                clip: true

                // =========================================
                // Background Image
                // =========================================

                Image {

                    anchors.fill: parent

                    source: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/electronics_bg.png"

                    fillMode: Image.PreserveAspectCrop

                    opacity: 0.35
                }

                // =========================================
                // Dark Overlay
                // =========================================

                Rectangle {

                    anchors.fill: parent

                    color: "#0F172A"

                    opacity: 0.55
                }

                // =========================================
                // Hero Content
                // =========================================

                ColumnLayout {

                    anchors.centerIn: parent

                    spacing: 8

                    Label {

                        text: qsTr("Shop by Category")

                        color: "#FFFFFF"

                        font.pixelSize: 32

                        font.bold: true

                        Layout.alignment:
                            Qt.AlignHCenter
                    }

                    Label {

                        text:
                            qsTr(
                                "Explore our electronics by category"
                            )

                        color: "#CBD5E1"

                        font.pixelSize: 15

                        Layout.alignment:
                            Qt.AlignHCenter
                    }
                }

                // =========================================
                // Cyan Bottom Line
                // =========================================

                Rectangle {

                    anchors.bottom: parent.bottom

                    anchors.horizontalCenter: parent.horizontalCenter

                    width: 100

                    height: 4

                    radius: 2

                    color: "#00C2FF"
                }
            }

            ColumnLayout {

                Layout.fillWidth: true

                Layout.leftMargin: 35
                Layout.rightMargin: 35
                Layout.topMargin: 35

                spacing: 20

                Label {

                    text: qsTr("Categories")

                    color: "#111827"

                    font.pixelSize: 28
                    font.bold: true
                }

                GridLayout {

                    Layout.fillWidth: true

                    columns: 5

                    rowSpacing: 20
                    columnSpacing: 15

                    Repeater {

                        model: [
                            {
                                name: "Electronic Components",
                                icon: "🔧"
                            },
                            {
                                name: "Robotics",
                                icon: "🤖"
                            },
                            {
                                name: "Development Boards",
                                icon: "🛠️"
                            },
                            {
                                name: "Sensors",
                                icon: "📡"
                            },
                            {
                                name: "Electronic Tools",
                                icon: "⚙️"
                            }
                        ]

                        delegate: Rectangle {

                            property bool selected:
                                categoriesPage.selectedCategory
                                === modelData.name

                            Layout.fillWidth: true

                            Layout.preferredHeight: 110

                            radius: 14

                            color:
                                selected
                                ? "#E0F7FA"
                                : "#FFFFFF"

                            border.color:
                                selected
                                ? "#0891B2"
                                : "#E2E8F0"

                            border.width:
                                selected ? 2 : 1

                            ColumnLayout {

                                anchors.centerIn: parent

                                spacing: 8

                                Label {

                                    text: modelData.icon

                                    font.pixelSize: 28

                                    Layout.alignment:
                                        Qt.AlignHCenter
                                }

                                Label {

                                    text:
                                        qsTr(modelData.name)

                                    color: "#334155"

                                    font.pixelSize: 13
                                    font.bold: true

                                    Layout.alignment:
                                        Qt.AlignHCenter

                                    horizontalAlignment:
                                        Text.AlignHCenter

                                    wrapMode:
                                        Text.WordWrap
                                }
                            }

                            MouseArea {

                                anchors.fill: parent

                                cursorShape:
                                    Qt.PointingHandCursor

                                onClicked: {

                                    categoriesPage.selectedCategory =
                                        modelData.name

                                    console.log(
                                        "Selected Category:",
                                        categoriesPage.selectedCategory
                                    )
                                }
                            }
                        }
                    }
                }


                // =========================================
                // SELECTED CATEGORY TITLE
                // =========================================

                Label {

                    visible:
                        categoriesPage.selectedCategory !== ""

                    text:
                        qsTr("Products in ") +
                        qsTr(categoriesPage.selectedCategory)

                    color: "#111827"

                    font.pixelSize: 28
                    font.bold: true

                    Layout.topMargin: 25
                }


                // =========================================
                // PRODUCTS GRID
                // =========================================

                GridLayout {

                    visible:
                        categoriesPage.selectedCategory !== ""

                    Layout.fillWidth: true

                    columns: 6

                    rowSpacing: 20
                    columnSpacing: 20

                    Layout.bottomMargin: 40

                    Repeater {

                        model:
                            categoriesPage.selectedCategory === ""
                            ? []
                            : productModel.getProductsByCategory(
                                  categoriesPage.selectedCategory
                              )

                        delegate: ProductCard {

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
                                if (categoriesPage.cartModel)
                                {
                                    categoriesPage.cartModel.addProduct(modelData)
                                    console.log(
                                        "Added to cart from Categories:",
                                        modelData.productName
                                    )
                                    console.log(
                                        "Cart items:",
                                        categoriesPage.cartModel.count
                                    )

                                }
                                else
                                {
                                    console.log("ERROR: cartModel is null")
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}