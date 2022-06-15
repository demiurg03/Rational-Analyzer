import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: item1
    width: 480
    height: 640
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



    TextField {
        id: textFieldName
        width: 400
        height: 20
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Product name")
    }

    Button {
        id: button
        x: 40
        y: 150
        width: 80
        height: textFieldName.height
        text: qsTr("add product")
        anchors.right: textFieldCalories.right
        anchors.rightMargin: 0

        onClicked: {


            var name = textFieldName.text
            var calories = textFieldCalories.text

            Backend.addProduct(name,  calories)


        }

    }

    TextField {
        id: textFieldCalories
        width: textFieldName.width
        height: textFieldName.height
        anchors.top: textFieldName.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
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
