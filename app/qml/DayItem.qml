import QtQuick 2.12
import QtQuick.Templates 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    id: item1





    Button{
        onClicked:{
            ld.source="addDayProduct.qml"
        }
    }








    Loader{
        id:ld;
        anchors.fill: parent;

}





}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
