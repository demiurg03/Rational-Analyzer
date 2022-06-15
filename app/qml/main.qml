import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    width: 480
    height: 640
    visible: true

    title: qsTr("rationalAnalyzer")





    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Item {

            WidgetStart {
                id: widgetStart
                anchors.fill: parent
            }
        }

        Item {
            WidgetAddFood {
                id: widgetAddFood
                visible: true
                anchors.fill: parent
            }
        }

        Item {
            WidgetAddProduct {
                id: widgetAddProduct
                visible: true
                anchors.fill: parent
            }
        }
    }


    TabBar {
        id: tabBar
        height: 40
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("WidgetStart")
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.topMargin: 0
        }
        TabButton {
            text: qsTr("WidgetAddProduct")
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.topMargin: 0
        }
        TabButton {
            text: qsTr("WidgetAddFood")
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.topMargin: 0
        }
    }



}


