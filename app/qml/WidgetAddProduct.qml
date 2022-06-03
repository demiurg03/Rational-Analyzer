import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: item1
    width: 200
    height: 225
    layer.smooth: false
    layer.mipmap: false



    Rectangle {
        id: rectangle
        color: "#EFEFEF"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 0
        layer.enabled: false
    }

    Button {
        id: btnCloseProduct
        x: 172
        y: 8
        width: 20
        height: 20
        text: qsTr("X")
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 1
        anchors.topMargin: 1
        onClicked: {
        widgetAddProduct.visible = false ;
        }
    }

    TextField {
        id: textFieldName
        x: 40
        y: 50
        width: 120
        placeholderText: qsTr("Product name")
    }

    Button {
        id: button
        x: 40
        y: 150
        width: 80
        height: 25
        text: qsTr("add product")

        onClicked: {


            var name = textFieldName.text
            var calories = textFieldCalories.text

            Backend.addProduct(name,  calories)


        }

    }

    TextField {
        id: textFieldCalories
        x: 40
        y: 100
        width: 120
        placeholderText: qsTr("calories ")

        onTextChanged: {
            var nowText = text;
            var atChar = nowText[nowText.length-1]

            if ( atChar < '0' || atChar > '9' || nowText.length > 3 ){
                text = nowText.substring(0, nowText.length-1)
            }


        }


    }







}
