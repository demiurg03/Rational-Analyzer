import QtQuick 2.0
import QtQuick.Controls 2.12

Item {




    Button{
        id: addProductButton
        x: 14
        y: 196
        width: 133
        height: 34
        text: qsTr("add product")
        onClicked: {

            var productName = productNameEdit.text;
            var productCalories = productCaloriesEdit.getValue();
            Backend.addProduct(productName, productCalories);


        }
    }


    SpinBox{
        id: productCaloriesEdit
        x: 14
        y: 142
        width: 133
        height: 32
    }

    TextField {
        id: productNameEdit
        x: 14
        y: 81
        width: 133
        height: 32
        placeholderText: qsTr("Text Field")
    }


}
