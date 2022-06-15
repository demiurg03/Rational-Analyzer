import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: item1
    width: 480
    height: 640

    WidgetCircularCalories {
        id: widgetCircularCalories
        x: 68
        width: widgetCircularCalories.height
        anchors.right: parent.right
        anchors.top: text1.top
        anchors.bottom: text3.bottom
        anchors.bottomMargin: -20
        anchors.topMargin: -20
        anchors.rightMargin: 20
    }

    Text {
        id: text1
        y: 50
        height: text1.font.pixelSize
        text: qsTr("Сalories:")
        anchors.left: parent.left
        font.pixelSize: text2.font.pixelSize
        anchors.leftMargin: 20
    }

    Text {
        id: text2
        y: text1.y
        height: text1.height
        text: qsTr("Calories spent:")
        anchors.left: text6.right
        font.pixelSize: 15
        anchors.leftMargin: 20
    }

    Text {
        id: text3
        x: text1.x
        height: text1.height
        text: qsTr("Calorie allowance:")
        anchors.top: text1.bottom
        font.pixelSize: text1.font.pixelSize
        anchors.topMargin: 30
    }

    Text {
        id: text4
        y: text1.y
        height: text1.height
        text: qsTr("1456")
        anchors.left: text1.right
        font.pixelSize: text1.font.pixelSize
        anchors.leftMargin: 0
    }

    Text {
        id: text5
        y: text1.y
        height: text1.height
        text: qsTr("325")
        anchors.left: text2.right
        font.pixelSize: text1.font.pixelSize
        anchors.leftMargin: 0
    }

    Text {
        id: text6
        height: text1.height
        text: qsTr("1900")
        anchors.left: text3.right
        anchors.top: text1.bottom
        font.pixelSize: text1.font.pixelSize
        anchors.leftMargin: 0
        anchors.topMargin: 30
    }



}
