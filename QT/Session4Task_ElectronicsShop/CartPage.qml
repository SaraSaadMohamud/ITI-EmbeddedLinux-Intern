import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page {

    id: cartPage

    background: Rectangle {
        color: "#F5F7FA"
    }

    // =====================================================
    // Main ScrollView
    // Header + Cart Content are inside the ScrollView
    // =====================================================

    ScrollView {

        anchors.fill: parent

        clip: true

        ColumnLayout {

            width: cartPage.width

            spacing: 0

            // =================================================
            // Page Header
            // =================================================

            Rectangle {

                id: pageHeader

                Layout.fillWidth: true
                Layout.preferredHeight: 450

                color: "#0F172A"

                clip: true

                // =================================================
                // Background Image
                // =================================================

                Image {

                    anchors.fill: parent

                    source:
                        "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/electronics_bg.png"

                    fillMode:
                        Image.PreserveAspectCrop

                    opacity: 0.35
                }

                // =================================================
                // Dark Overlay
                // =================================================

                Rectangle {

                    anchors.fill: parent

                    color: "#0F172A"

                    opacity: 0.55
                }

                // =================================================
                // Header Content
                // =================================================

                ColumnLayout {

                    anchors.centerIn: parent

                    spacing: 8

                    Label {

                        text:
                            qsTr("Shopping Cart")

                        color: "#FFFFFF"

                        font.pixelSize: 32
                        font.bold: true

                        Layout.alignment:
                            Qt.AlignHCenter
                    }

                    Label {

                        text:
                            qsTr("Review your selected products")

                        color: "#CBD5E1"

                        font.pixelSize: 15

                        Layout.alignment:
                            Qt.AlignHCenter
                    }
                }

                // =================================================
                // Cyan Bottom Line
                // =================================================

                Rectangle {

                    anchors.bottom: parent.bottom

                    anchors.horizontalCenter:
                        parent.horizontalCenter

                    width: 100

                    height: 4

                    radius: 2

                    color: "#00C2FF"
                }
            }


            // =====================================================
            // Main Cart Content
            // =====================================================

            ColumnLayout {

                Layout.fillWidth: true

                spacing: 20


                // =================================================
                // Empty Cart
                // =================================================

                Item {

                    visible:
                        cartModel.count === 0

                    Layout.fillWidth: true

                    Layout.preferredHeight: 450

                    ColumnLayout {

                        anchors.centerIn: parent

                        spacing: 12


                        Label {

                            text: "🛒"

                            font.pixelSize: 65

                            Layout.alignment:
                                Qt.AlignHCenter
                        }


                        Label {

                            text:
                                qsTr("Your cart is empty")

                            color: "#1E293B"

                            font.pixelSize: 24
                            font.bold: true

                            Layout.alignment:
                                Qt.AlignHCenter
                        }


                        Label {

                            text:
                                qsTr(
                                    "Add some products to your cart to get started."
                                )

                            color: "#64748B"

                            font.pixelSize: 14

                            Layout.alignment:
                                Qt.AlignHCenter
                        }
                    }
                }


                // =================================================
                // Cart Content
                // =================================================

                ColumnLayout {

                    visible:
                        cartModel.count > 0

                    Layout.fillWidth: true

                    Layout.leftMargin: 35
                    Layout.rightMargin: 35

                    Layout.topMargin: 30
                    Layout.bottomMargin: 40

                    spacing: 20


                    // =================================================
                    // Top Row
                    // =================================================

                    RowLayout {

                        Layout.fillWidth: true

                        Label {

                            text:
                                cartModel.totalItems()
                                + " "
                                + qsTr("items in cart")

                            color: "#64748B"

                            font.pixelSize: 14

                            Layout.fillWidth: true
                        }
                    }


                    // =================================================
                    // Cart Items
                    // =================================================

                    Repeater {

                        model:
                            cartModel


                        delegate: Rectangle {

                            Layout.fillWidth: true

                            Layout.preferredHeight: 130

                            radius: 14

                            color: "#FFFFFF"

                            border.color: "#E2E8F0"

                            border.width: 1


                            RowLayout {

                                anchors.fill: parent

                                anchors.margins: 15

                                spacing: 18


                                // =====================================
                                // Product Image
                                // =====================================

                                Rectangle {

                                    Layout.preferredWidth: 100

                                    Layout.preferredHeight: 100

                                    radius: 10

                                    color: "#F1F5F9"

                                    clip: true


                                    Image {

                                        anchors.fill: parent

                                        anchors.margins: 5

                                        source:
                                            model.productImage

                                        fillMode:
                                            Image.PreserveAspectFit

                                        smooth: true

                                        mipmap: true

                                        visible:
                                            model.productImage !== ""
                                    }


                                    Label {

                                        anchors.centerIn: parent

                                        text: "📦"

                                        font.pixelSize: 35

                                        visible:
                                            model.productImage === ""
                                    }
                                }


                                // =====================================
                                // Product Info
                                // =====================================

                                ColumnLayout {

                                    Layout.fillWidth: true

                                    spacing: 5


                                    Label {

                                        text:
                                            model.productName

                                        color: "#1E293B"

                                        font.pixelSize: 16

                                        font.bold: true

                                        Layout.fillWidth: true

                                        elide:
                                            Text.ElideRight
                                    }


                                    Label {

                                        text:
                                            model.productCategory

                                        color: "#0891B2"

                                        font.pixelSize: 12

                                        font.bold: true
                                    }


                                    Label {

                                        text:
                                            model.productPrice
                                            + " "
                                            + qsTr("each")

                                        color: "#64748B"

                                        font.pixelSize: 12
                                    }
                                }


                                // =====================================
                                // Quantity
                                // =====================================

                                ColumnLayout {

                                    spacing: 5


                                    Label {

                                        text:
                                            qsTr("Quantity")

                                        color: "#64748B"

                                        font.pixelSize: 11

                                        Layout.alignment:
                                            Qt.AlignHCenter
                                    }


                                    RowLayout {

                                        spacing: 5


                                        // ---------------------------------
                                        // Minus Button
                                        // ---------------------------------

                                        Button {

                                            id: minusButton

                                            text: "−"

                                            Layout.preferredWidth: 32

                                            Layout.preferredHeight: 32


                                            contentItem: Text {

                                                text:
                                                    minusButton.text

                                                color: "#334155"

                                                font.pixelSize: 18

                                                font.bold: true

                                                horizontalAlignment:
                                                    Text.AlignHCenter

                                                verticalAlignment:
                                                    Text.AlignVCenter
                                            }


                                            background: Rectangle {

                                                radius: 7

                                                color:
                                                    minusButton.hovered
                                                    ? "#E2E8F0"
                                                    : "#F8FAFC"

                                                border.color:
                                                    "#CBD5E1"

                                                border.width: 1
                                            }


                                            onClicked: {

                                                cartModel.decreaseQuantity(
                                                    index
                                                )
                                            }
                                        }


                                        // ---------------------------------
                                        // Quantity Number
                                        // ---------------------------------

                                        Label {

                                            text:
                                                model.quantity

                                            color: "#1E293B"

                                            font.pixelSize: 14

                                            font.bold: true

                                            Layout.preferredWidth: 30

                                            horizontalAlignment:
                                                Text.AlignHCenter

                                            verticalAlignment:
                                                Text.AlignVCenter
                                        }


                                        // ---------------------------------
                                        // Plus Button
                                        // ---------------------------------

                                        Button {

                                            id: plusButton

                                            text: "+"

                                            Layout.preferredWidth: 32

                                            Layout.preferredHeight: 32


                                            contentItem: Text {

                                                text:
                                                    plusButton.text

                                                color: "#FFFFFF"

                                                font.pixelSize: 18

                                                font.bold: true

                                                horizontalAlignment:
                                                    Text.AlignHCenter

                                                verticalAlignment:
                                                    Text.AlignVCenter
                                            }


                                            background: Rectangle {

                                                radius: 7

                                                color:
                                                    plusButton.pressed
                                                    ? "#007A9E"
                                                    : plusButton.hovered
                                                      ? "#008FB8"
                                                      : "#0891B2"
                                            }


                                            onClicked: {

                                                cartModel.increaseQuantity(
                                                    index
                                                )
                                            }
                                        }
                                    }
                                }


                                // =====================================
                                // Product Total
                                // =====================================

                                ColumnLayout {

                                    Layout.preferredWidth: 100

                                    spacing: 5


                                    Label {

                                        text:
                                            qsTr("Total")

                                        color: "#64748B"

                                        font.pixelSize: 11

                                        Layout.alignment:
                                            Qt.AlignRight
                                    }


                                    Label {

                                        text:
                                            "$"
                                            + cartModel
                                                .productTotal(index)
                                                .toFixed(2)

                                        color: "#0891B2"

                                        font.pixelSize: 16

                                        font.bold: true

                                        Layout.alignment:
                                            Qt.AlignRight
                                    }
                                }


                                // =====================================
                                // Remove Button
                                // =====================================

                                Button {

                                    id: removeButton

                                    text: "×"

                                    Layout.preferredWidth: 35

                                    Layout.preferredHeight: 35


                                    contentItem: Text {

                                        text:
                                            removeButton.text

                                        color: "#DC2626"

                                        font.pixelSize: 22

                                        font.bold: true

                                        horizontalAlignment:
                                            Text.AlignHCenter

                                        verticalAlignment:
                                            Text.AlignVCenter
                                    }


                                    background: Rectangle {

                                        radius: 8

                                        color:
                                            removeButton.hovered
                                            ? "#FEE2E2"
                                            : "transparent"
                                    }


                                    onClicked: {

                                        cartModel.removeProduct(
                                            index
                                        )
                                    }
                                }
                            }
                        }
                    }


                    // =================================================
                    // Divider
                    // =================================================

                    Rectangle {

                        Layout.fillWidth: true

                        height: 1

                        color: "#E2E8F0"
                    }


                    // =================================================
                    // Checkout Button
                    // =================================================

                    Button {

                        id: checkoutButton

                        Layout.alignment:
                            Qt.AlignRight

                        Layout.preferredWidth: 180

                        Layout.preferredHeight: 48

                        text:
                            qsTr("Checkout")


                        contentItem: Text {

                            text:
                                checkoutButton.text

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
                                checkoutButton.pressed
                                ? "#007A9E"
                                : checkoutButton.hovered
                                  ? "#008FB8"
                                  : "#0891B2"
                        }


                        onClicked: {

                            checkoutPopup.open()
                        }
                    }
                }
            }
        }
    }


    // =====================================================
    // Checkout Popup
    // =====================================================

    Popup {

        id: checkoutPopup

        anchors.centerIn: parent

        width: 350

        height: 190

        modal: true

        dim: true

        padding: 20


        background: Rectangle {

            radius: 14

            color: "#FFFFFF"

            border.color: "#E2E8F0"

            border.width: 1
        }


        ColumnLayout {

            anchors.fill: parent

            spacing: 12


            Label {

                text:
                    qsTr("Order Confirmed!")

                color: "#16A34A"

                font.pixelSize: 20

                font.bold: true

                Layout.alignment:
                    Qt.AlignHCenter
            }


            Label {

                text:
                    qsTr(
                        "Thank you for your order!"
                    )

                color: "#334155"

                font.pixelSize: 14

                Layout.alignment:
                    Qt.AlignHCenter
            }


            Label {

                text:
                    "$"
                    + cartModel
                        .cartTotal()
                        .toFixed(2)

                color: "#0891B2"

                font.pixelSize: 20

                font.bold: true

                Layout.alignment:
                    Qt.AlignHCenter
            }


            Button {

                id: closeCheckoutButton

                text:
                    qsTr("Close")

                Layout.preferredWidth: 100

                Layout.preferredHeight: 35

                Layout.alignment:
                    Qt.AlignHCenter


                contentItem: Text {

                    text:
                        closeCheckoutButton.text

                    color: "#FFFFFF"

                    font.pixelSize: 12

                    font.bold: true

                    horizontalAlignment:
                        Text.AlignHCenter

                    verticalAlignment:
                        Text.AlignVCenter
                }


                background: Rectangle {

                    radius: 8

                    color: "#0891B2"
                }


                onClicked: {

                    checkoutPopup.close()

                    cartModel.clearCart()

                    stackView.pop(null)
                }
            }
        }
    }
}