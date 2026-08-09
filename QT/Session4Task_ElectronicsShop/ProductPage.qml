import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page {

    id: productsPage
    property ListModel cartModel

    background: Rectangle {
        color: "#F5F7FA"
    }

    ProductModel {
        id: productModel
    }

    ScrollView {
        anchors.fill: parent
        clip: true

        ColumnLayout {

            width: productsPage.width
            spacing: 0

            Rectangle {

                Layout.fillWidth: true
                Layout.preferredHeight: 450
                color: "#0F172A"

                clip: true

                Image {
                    anchors.fill: parent

                    source: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/electronics_bg.png"

                    fillMode: Image.PreserveAspectCrop

                    opacity: 0.30

                    smooth: true
                }
                Rectangle {
                    anchors.fill: parent
                    color: "#0F172A"
                    opacity: 0.40
                }

                ColumnLayout {

                    anchors.centerIn: parent

                    spacing: 8

                    Label {
                        text: qsTr("All Products")

                        color: "#FFFFFF"

                        font.pixelSize: 34
                        font.bold: true

                        Layout.alignment: Qt.AlignHCenter
                    }

                    Label {
                        text: qsTr("Explore our complete collection")

                        color: "#CBD5E1"

                        font.pixelSize: 16

                        Layout.alignment: Qt.AlignHCenter
                    }
                }
                Rectangle {
                    anchors.bottom: parent.bottom

                    anchors.horizontalCenter: parent.horizontalCenter

                    width: 120
                    height: 5

                    radius: 2

                    color: "#00C2FF"
                }
            }

            // =========================================
            // PRODUCTS
            // =========================================

            GridLayout {

                Layout.fillWidth: true

                Layout.leftMargin: 35
                Layout.rightMargin: 35
                Layout.topMargin: 30
                Layout.bottomMargin: 40

                columns: 6

                rowSpacing: 20
                columnSpacing: 20

                Repeater {

                    model: productModel

                    delegate: ProductCard {

                        productName: model.productName
                        productImage: model.productImage
                        productPrice: model.productPrice
                        productCategory: model.productCategory
                        productAvailable: model.productAvailable

                        productBrand: model.productBrand
                        productVersion: model.productVersion
                        productColor: model.productColor
                        productVoltage: model.productVoltage
                        productInterface: model.productInterface

                        onAddToCartClicked: {
                            cartModel.addProduct({
                                productName: productName,
                                productImage: productImage,
                                productPrice: productPrice,
                                productCategory: productCategory,

                                productBrand: productBrand,
                                productVersion: productVersion,
                                productColor: productColor,
                                productVoltage: productVoltage,
                                productInterface: productInterface
                            })

                            console.log("Added:", productName)
                            console.log("Cart count:", cartModel.count)
                        }
                    }
                }
            }
        }
    }
}