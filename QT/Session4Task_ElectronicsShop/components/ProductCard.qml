import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Rectangle{
    id: productCard

    property string productName: "Arduino Uno R3"
    property string productImage: ""
    property string productPrice: "$24.99"
    property string productCategory: "Development Boards"
    property bool productAvailable: true

    // Product Details - Back Side
    property string productBrand: "Arduino"
    property string productVersion: "R3"
    property string productColor: "Green"
    property string productVoltage: "5V"
    property string productInterface: "USB"

    signal addToCartClicked()
    width: 280
    height:260
    radius: 16
    color: "#FFFFFF"

    border.color: "#E2E8F0"
    border.width: 1

    property bool flipped: false
    // =====================================================
    // Flip Container
    // =====================================================

    Item {
        id: flipContainer

        anchors.fill: parent

        transform: Rotation {
            id: flipRotation

            origin.x: flipContainer.width / 2
            origin.y: flipContainer.height / 2

            axis.x: 0
            axis.y: 1
            axis.z: 0

            angle: productCard.flipped ? 180 : 0

            Behavior on angle {
                NumberAnimation {
                    duration: 500
                    easing.type: Easing.InOutCubic
                }
            }
        }


    // =================================================
    // FRONT
    // =================================================
    Rectangle{
        id: frontSide
        anchors.fill: parent
        radius: 16
        color: "#FFFFFF"
        border.color: "#E2E8F0"
        border.width: 1
        visible: flipRotation.angle < 90

        ColumnLayout{
            anchors.fill: parent
            anchors.margins: 12
            spacing: 4

            // =========================================
            // Product Image
            // =========================================
            Rectangle{

                Layout.fillWidth: true
                Layout.preferredHeight: 120
                radius: 12
                clip: true
                color: "#F1F5F9"

                Image {
                    anchors.fill: parent
                    anchors.margins: 2

                    source: productCard.productImage

                    fillMode: Image.PreserveAspectCrop

                    smooth: true
                    mipmap: true

                    visible: productCard.productImage !== ""
                }

                Label {
                    anchors.centerIn: parent
                    text: "📦"
                    font.pixelSize: 42
                    color: "#94A3B8"
                    visible: productCard.productImage === ""
                }
            }

            // =========================================
            // Category
            // =========================================

            Label{
                text:qsTr(productCard.productCategory)
                color: "#0891B2"
                Layout.fillWidth: true
                font.pixelSize: 11
                font.bold: true
            }

            // =========================================
            // Product Name
            // =========================================
            Label{
                text:qsTr(productCard.productName)
                color: "#1E293B"
                Layout.fillWidth: true
                font.pixelSize: 15
                font.bold: true
                elide: Text.ElideRight
            }

            // =========================================
            // Price + Button
            // =========================================
            RowLayout{
                Layout.fillWidth: true
                spacing: 8
                Label {
                    text: productCard.productPrice

                    color: "#0891B2"

                    font.pixelSize: 17
                    font.bold: true
                }
                Item {
                    Layout.fillWidth: true
                }

                // =========================================
                // Details Button
                // =========================================

                Button {
                    id: detailsButton

                    text: qsTr("Details")

                    Layout.preferredWidth: 68
                    Layout.preferredHeight: 30

                    contentItem: Text {
                        text: detailsButton.text

                        color: "#0891B2"

                        font.pixelSize: 11
                        font.bold: true

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }


                    background: Rectangle {
                        radius: 8

                        color: detailsButton.pressed
                               ? "#E0F2F7"
                               : detailsButton.hovered
                                 ? "#F0FAFC"
                                 : "#FFFFFF"

                        border.color: "#0891B2"
                        border.width: 1
                    }

                    onClicked: {
                        productCard.flipped = true
                    }
                }

                // =========================================
                // Add Button
                // =========================================
                Button{
                    id:addButton
                    z: 20
                    text:qsTr("Add")
                    Layout.preferredWidth: 62
                    Layout.preferredHeight:34
                    enabled: productCard.productAvailable

                    contentItem: Text {
                        text: addButton.text

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

                        color: addButton.enabled?
                               (addButton.pressed?
                                "#007A9E" : addButton.hovered
                                ? "#008FB8": "#0891B2") : "#CBD5E1"
                    }

                    onClicked: {
                        console.log(
                            "Added to cart:",
                            productCard.productName
                        )

                        productCard.addToCartClicked()
                        addedPopup.open()
                    }
                }
            }
        }
        MouseArea {
            id: frontMouseArea

            anchors.fill: parent
            hoverEnabled: true
            acceptedButtons: Qt.NoButton
            z: -1
        }
    }

    Rectangle {
        id: backSide

        anchors.fill: parent

        radius: 16

        color: "#FFFFFF"

        border.color: "#E2E8F0"
        border.width: 1

        visible: flipRotation.angle >= 90

        transform: Rotation {
            origin.x: backSide.width / 2
            origin.y: backSide.height / 2

            axis.x: 0
            axis.y: 1
            axis.z: 0

            angle: 180
        }

        // ---------------------------------------------
        // Back Content
        // ---------------------------------------------

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 18

            spacing: 10

            // -----------------------------------------
            // Header
            // -----------------------------------------

            Label {
                text: qsTr(productCard.productName)

                color: "#1E293B"

                font.pixelSize: 18
                font.bold: true

                Layout.fillWidth: true

                horizontalAlignment: Text.AlignHCenter
            }

            Label {
                text: qsTr("Product Details")

                color: "#0891B2"

                font.pixelSize: 12
                font.bold: true

                Layout.fillWidth: true

                horizontalAlignment: Text.AlignHCenter
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 1

                color: "#E2E8F0"
            }

            // -----------------------------------------
            // Details
            // -----------------------------------------

            ColumnLayout {
                Layout.fillWidth: true

                spacing: 7

                // Brand
                RowLayout {
                    Layout.fillWidth: true

                    Label {
                        text: qsTr("Brand")

                        color: "#64748B"

                        font.pixelSize: 12

                        Layout.fillWidth: true
                    }

                    Label {
                        text: productCard.productBrand

                        color: "#1E293B"

                        font.pixelSize: 12
                        font.bold: true
                    }
                }

                // Version
                RowLayout {
                    Layout.fillWidth: true

                    Label {
                        text: qsTr("Version")

                        color: "#64748B"

                        font.pixelSize: 12

                        Layout.fillWidth: true
                    }

                    Label {
                        text: productCard.productVersion

                        color: "#1E293B"

                        font.pixelSize: 12
                        font.bold: true
                    }
                }

                // Color
                RowLayout {
                    Layout.fillWidth: true

                    Label {
                        text: qsTr("Color")

                        color: "#64748B"

                        font.pixelSize: 12

                        Layout.fillWidth: true
                    }

                    Label {
                        text: productCard.productColor

                        color: "#1E293B"

                        font.pixelSize: 12
                        font.bold: true
                    }
                }

                // Voltage
                RowLayout {
                    Layout.fillWidth: true

                    Label {
                        text: qsTr("Voltage")

                        color: "#64748B"

                        font.pixelSize: 12

                        Layout.fillWidth: true
                    }

                    Label {
                        text: productCard.productVoltage

                        color: "#1E293B"

                        font.pixelSize: 12
                        font.bold: true
                    }
                }

                // Interface
                RowLayout {
                    Layout.fillWidth: true

                    Label {
                        text: qsTr("Interface")

                        color: "#64748B"

                        font.pixelSize: 12

                        Layout.fillWidth: true
                    }

                    Label {
                        text: productCard.productInterface

                        color: "#1E293B"

                        font.pixelSize: 12
                        font.bold: true
                    }
                }

                Item {
                    Layout.fillHeight: true
                }

                Button {
                    id: backButton
                    z: 20
                    text: qsTr("Back")

                    Layout.alignment: Qt.AlignHCenter

                    Layout.preferredWidth: 85
                    Layout.preferredHeight: 32

                    contentItem: Text {
                        text: backButton.text

                        color: "#FFFFFF"

                        font.pixelSize: 12
                        font.bold: true

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        radius: 8

                        color: backButton.pressed
                               ? "#007A9E"
                               : backButton.hovered
                                 ? "#008FB8"
                                 : "#0891B2"
                    }

                    onClicked: {
                        productCard.flipped = false
                    }
                }
            }
        }
        // ---------------------------------------------
        // Click anywhere on Back to return
        // ---------------------------------------------

        MouseArea {
            anchors.fill: parent

            z: -1

            onClicked: {
                productCard.flipped = false
            }
        }

    }
    // =====================================================
    // Hover Effect
    // =====================================================

    HoverHandler {
        id: cardHoverHandler
    }

    scale: !productCard.flipped && cardHoverHandler.hovered
           ? 1.02
           : 1.0

    Behavior on scale {
        NumberAnimation {
            duration: 150
        }
    }

    // =====================================================
    // Add To Cart Notification
    // =====================================================

    Popup {
        id: addedPopup

        width: 220
        height: 48

        x: (productCard.width - width) / 2
        y: -58

        padding: 0

        closePolicy: Popup.NoAutoClose

        background: Rectangle {
            radius: 10

            color: "#FFFFFF"

            border.color: "#D1FAE5"
            border.width: 1

            // Small shadow-like effect
            Rectangle {
                anchors.fill: parent
                anchors.margins: -2

                radius: 12

                color: "transparent"

                border.color: "#E2E8F0"
                border.width: 1

                z: -1
            }
        }

        contentItem: RowLayout {
            spacing: 8

            anchors.fill: parent
            anchors.leftMargin: 12
            anchors.rightMargin: 12

            Rectangle {
                width: 24
                height: 24

                radius: 12

                color: "#DCFCE7"

                Label {
                    anchors.centerIn: parent

                    text: "✓"

                    color: "#16A34A"

                    font.pixelSize: 15
                    font.bold: true
                }
            }

            Label {
                Layout.fillWidth: true

                text: qsTr("Added to cart!")

                color: "#1E293B"

                font.pixelSize: 12
                font.bold: true

                verticalAlignment: Text.AlignVCenter
            }
        }

        // Automatically hide
        Timer {
            id: popupTimer

            interval: 2000
            repeat: false

            onTriggered: {
                addedPopup.close()
            }
        }

        onOpened: {
            popupTimer.restart()
        }
    }
 }

}
