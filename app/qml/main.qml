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
        currentIndex: 0

        Item {

            WidgetStart {
                id: widgetStart
            }
        }

        Item {
            WidgetAddFood {
                id: widgetAddFood
                anchors.fill: parent
            }
        }

        Item {
            WidgetAddProduct {
                id: widgetAddProduct
                anchors.fill: parent
            }
        }
    }





}


