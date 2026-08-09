import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

ApplicationWindow {
    CartModel {
        id: cartModel
    }
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
            cartModel: cartModel

            onExploreProductsClicked: {
                stackView.push("ProductPage.qml",{cartModel: cartModel})
            }

            onCategoryClicked: function(categoryName) {
                stackView.push(
                    "CategoriesPage.qml",
                    {
                        selectedCategory: categoryName,
                        cartModel: cartModel
                    }
                )
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
            stackView.pop(null)
        }

        onProductsClicked: {
            console.log("TEST: Products clicked")
            stackView.push(
                "ProductPage.qml",
                {cartModel: cartModel}
            )
        }

        onCategoriesClicked: {
            console.log("TEST: Categories clicked")
            stackView.push(
                "CategoriesPage.qml",
                {cartModel: cartModel}
            )
        }

        onSearchClicked: {
            console.log("TEST: Search clicked")
            stackView.push(
                "SearchPage.qml",
                {cartModel: cartModel}
            )
        }

        onLanguageSelected: function(language) {
            console.log("Selected language:", language)
            languageManager.setLanguage(language)
        }

        onCartClicked: {
            console.log("TEST: Cart clicked")
            stackView.push("CartPage.qml")
        }
    }
}
