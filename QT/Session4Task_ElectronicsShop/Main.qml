import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

ApplicationWindow {
    id: window
    width: 1200
    height: 750
    visible: true

    title: qsTr("Electronics Shop")
    color:"#F5F7FA"

    StackView {
        id: stackView

        anchors.top: headerBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom


        initialItem: HomePage {
            onExploreProductsClicked: {
                stackView.push("ProductPage.qml")
            }
        }
    }

    HeaderBar{

        id: headerBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        onHomeClicked: {
            console.log("TEST: Home clicked")
            stackView.push("HomePage.qml")
        }

        onProductsClicked: {
            console.log("TEST: Products clicked")
            stackView.push("ProductPage.qml")
        }

        onCategoriesClicked: {
            console.log("TEST: Categories clicked")
        }

        onSearchClicked: {
            console.log("TEST: Search clicked")
        }

        onLanguageClicked: {
            console.log("TEST: Language clicked")
        }

        onCartClicked: {
            console.log("TEST: Cart clicked")
        }
    }
}
