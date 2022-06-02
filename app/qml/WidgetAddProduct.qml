import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: item1
    width: 350
    height: 250


    Rectangle {
        id: rectangle
        color: "#efefef"
        anchors.fill: parent

    }

    TextField {
        id: textFieldProduct
        x: 40
        y: 50
        width: 120
        text: "Product"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 40
        anchors.topMargin: 50
        placeholderText: qsTr("Text Field")
    }

    TextField {
        id: textFieldGrams
        x: 180
        y: 50
        width: 60
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
        width: 50
        height: 20
        text: qsTr("New")
        anchors.left: textFieldGrams.right
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.leftMargin: 20
    }




}
