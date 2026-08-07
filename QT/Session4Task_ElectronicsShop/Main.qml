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

    HomePage{
        anchors.fill: parent
    }


    HeaderBar{

        id: headerBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        onHomeClicked: {
            console.log("TEST: Home clicked")
        }

        onProductsClicked: {
            console.log("TEST: Products clicked")
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
