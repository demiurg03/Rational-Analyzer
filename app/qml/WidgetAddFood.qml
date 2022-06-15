import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: item1
    width: 480
    height: 640



    Rectangle {
        id: rectangle
        color: "#efefef"
        anchors.fill: parent



    }

    TextField {
        id: textFieldProduct
        x: 40
        y: 50
        width: 320
        height: 20
        text: "Product"
        anchors.top: parent.top
        anchors.horizontalCenterOffset: -50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 50
        placeholderText: qsTr("Text Field")
    }

    TextField {
        id: textFieldGrams
        x: 180
        y: 50
        width: 80
        height: textFieldProduct.height
        text: "Grams"
        anchors.left: textFieldProduct.right
        anchors.top: parent.top
        anchors.leftMargin: 20
        placeholderText: qsTr("Text Field")
        anchors.topMargin: 50
    }

    Button {
        id: btnNew
        x: 247
        width: textFieldGrams.width
        height: textFieldProduct.height
        text: qsTr("New")
        anchors.left: btnConsider.left
        anchors.top: btnConsider.bottom
        anchors.topMargin: 30
        anchors.leftMargin: 0

        onClicked: {
            widgetAddProduct.visible = true ;
        }

    }

    Button {
        id: btnConsider
        x: 247
        width: textFieldGrams.width
        height: textFieldProduct.height
        text: qsTr("Consider")
        anchors.right: textFieldGrams.right
        anchors.top: textFieldGrams.bottom
        anchors.rightMargin: 0
        anchors.topMargin: 30
    }




}
