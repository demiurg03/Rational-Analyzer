import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    width: 480
    height: 640
    visible: true
    property alias button1Y: button1.y
    title: qsTr("Hello World")



    Button{
        x: 400
        y: 615
        width: 80
        height: 25
        text: "products list"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.rightMargin: 0
        onClicked: {
            Backend.getProduct(1);
        }
    }

    Button {
        id: button
        x: 485
        width: 40
        height: 40
        text: qsTr("Set...")
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.rightMargin: 15
    }

    Button {
        id: button1
        x: 435
        width: 40
        height: 40
        text: "hard"
        anchors.right: button.left
        anchors.top: parent.top
        enabled: false
        anchors.topMargin: 15
        anchors.rightMargin: 10
        font.bold: false
        font.pointSize: 10
        onClicked: {
            //Calling the "hard" widget
        }
    }

    Button {
            id: button2
            x: 435
            width: 40
            height: 40
            text: qsTr("product")
            anchors.right: button1.left
            anchors.top: parent.top
            font.pointSize: 6
            anchors.topMargin: 15
            anchors.rightMargin: 10
            font.bold: false
            onClicked: {
                widgetAddProduct.visible = true ;
            }
        }

    Button {
        id: button3
        x: 435
        width: 40
        height: 40
        text: qsTr("+")
        anchors.right: button2.left
        anchors.top: parent.top
        font.pointSize: 12
        anchors.topMargin: 15
        anchors.rightMargin: 10
        font.bold: false
        onClicked: {
            widgetAddFood.visible = true ;
        }
    }

    SpinBox {
        id: spinBox
        x: 15
        width: 100
        height: 40
        anchors.top: parent.top
        to: 99
        anchors.topMargin: 15
    }

    ScrollView {
        id: scrollView
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 25
        anchors.leftMargin: 15
        anchors.topMargin: 65
        anchors.rightMargin: 15

        Text {
            id: text1
            height: 25
            text: qsTr("Product")
            anchors.left: parent.left
            anchors.right: text2.left
            anchors.top: parent.top
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
        }

        Text {
            id: text2
            x: 28
            width: 100
            height: 25
            text: qsTr("Cal/100g")
            anchors.right: text3.left
            anchors.top: parent.top
            font.pixelSize: 12
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }

        Text {
            id: text3
            width: 100
            height: 25
            text: qsTr("Grams")
            anchors.right: text4.left
            anchors.top: parent.top
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }

        Text {
            id: text4
            width: 100
            height: 25
            text: qsTr("Calories")
            anchors.right: parent.right
            anchors.top: parent.top
            font.pixelSize: 12
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }
    }





    WidgetAddFood {
        id: widgetAddFood
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
    WidgetAddProduct{
        id: widgetAddProduct
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter

    }
}
