import QtQuick

ListModel {
    id: cartModel

    // =====================================================
    // Add Product To Cart
    // =====================================================
    function addProduct(product) {

        if (!product)
            return

        // Check if product already exists
        for (var i = 0; i < count; i++) {

            var item = get(i)

            if (item.productName === product.productName) {

                setProperty(
                    i,
                    "quantity",
                    item.quantity + 1
                )

                return
            }
        }

        // Product doesn't exist -> add new item
        append({
            productName: product.productName,
            productImage: product.productImage,
            productPrice: product.productPrice,
            productCategory: product.productCategory,

            productBrand: product.productBrand,
            productVersion: product.productVersion,
            productColor: product.productColor,
            productVoltage: product.productVoltage,
            productInterface: product.productInterface,

            quantity: 1
        })
    }

    // =====================================================
    // Increase Quantity
    // =====================================================

    function increaseQuantity(index) {

        if (index < 0 || index >= count)
            return

        var item = get(index)

        setProperty(
            index,
            "quantity",
            item.quantity + 1
        )
    }

    // =====================================================
    // Decrease Quantity
    // =====================================================

    function decreaseQuantity(index) {

        if (index < 0 || index >= count)
            return

        var item = get(index)

        if (item.quantity > 1) {

            setProperty(
                index,
                "quantity",
                item.quantity - 1
            )

        } else {

            remove(index)
        }
    }

    // =====================================================
    // Remove Product
    // =====================================================

    function removeProduct(index) {

        if (index < 0 || index >= count)
            return

        remove(index)
    }

    // =====================================================
    // Clear Cart
    // =====================================================

    function clearCart() {

        clear()
    }

    // =====================================================
    // Number Of Items
    // =====================================================

    function totalItems() {

        var total = 0

        for (var i = 0; i < count; i++) {

            total += get(i).quantity
        }

        return total
    }

    // =====================================================
    // Convert Price String To Number
    // =====================================================
    function priceToNumber(price) {

        if (!price)
            return 0

        var value = parseFloat(
            price.toString().replace("$", "")
        )

        if (isNaN(value))
            return 0

        return value
    }

    // =====================================================
    // Product Total
    // =====================================================

    function productTotal(index) {

        if (index < 0 || index >= count)
            return 0

        var item = get(index)

        return priceToNumber(item.productPrice)
               * item.quantity
    }


    // =====================================================
    // Cart Total
    // =====================================================

    function cartTotal() {

        var total = 0

        for (var i = 0; i < count; i++) {

            total +=
                priceToNumber(get(i).productPrice)
                * get(i).quantity
        }

        return total
    }
}