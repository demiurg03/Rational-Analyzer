import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: window
    width: 480
    height: 640
    visible: true

    title: qsTr("rationalAnalyzer")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        DayItem{

        }

        AddProductItem{

        }

        ListProductItem{

        }

    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("day")
        }

        TabButton {
            text: qsTr("add product")
        }
        TabButton {
            text: qsTr("list product")
        }

    }









}


