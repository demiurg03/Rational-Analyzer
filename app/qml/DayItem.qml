import QtQuick 2.12
import QtQuick.Templates 2.12
import QtQuick.Layouts 1.12

import QtQuick.Controls 2.12

Item {



    Component.onCompleted:{
//        productAddListView.model.clear();
//        productCurrentListView.model.clear();

//        var productList = Backend.getAllProduct();

//        for (var index in productList) {
//            var elm = productList[index];
//            productAddListView.model.append({itemId: elm.id,  itemName:  elm.name })
//            productCurrentListView.model.append({itemId: elm.id,  itemName:  elm.name })

//        }

    }


    ColumnLayout{
        property int margin:25
        anchors.fill: parent
        layer.smooth: false
        anchors.topMargin: margin
        anchors.bottomMargin: margin
        anchors.leftMargin: margin
        anchors.rightMargin: margin
        spacing: 6.4

        Item {
            id: dayInfoItem;

            Text {
                id: caloriesText
                text: qsTr("text")
            }

        }


}




}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
