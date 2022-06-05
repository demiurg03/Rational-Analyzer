import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: item1
    width: 360
    height: 250


    Rectangle {
        id: rectangle
        color: "#efefef"
        anchors.fill: parent

        Button {
            id: btnCloseFood
            x: 308
            width: 20
            height: 20
            text: qsTr("X")
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 1
            anchors.rightMargin: 1
            onClicked: {
                widgetAddFood.visible = false ;
            }
        }

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
        width: 60
        height: 20
        text: qsTr("New")
        anchors.left: textFieldGrams.right
        anchors.top: btnConsider.bottom
        anchors.topMargin: 30
        anchors.leftMargin: 20

        onClicked: {
                        widgetAddProduct.visible = true ;
                    }

    }

    Button {
        id: btnConsider
        x: 247
        width: 60
        height: 20
        text: qsTr("Consider")
        anchors.left: textFieldGrams.right
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.leftMargin: 20
    }




}
