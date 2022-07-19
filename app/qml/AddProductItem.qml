import QtQuick 2.0
import QtQuick.Templates 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12


Item {

    function addProduct(){
        var productName = productNameEdit.text;
        var productCalories = productCaloriesEdit.getValue();
        Backend.addProduct(productName, productCalories);

    }

    ColumnLayout {
        id: row
        anchors.fill: parent
        layer.smooth: false
        anchors.topMargin: 5
        anchors.bottomMargin: 5
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        spacing: 6.1




        SpinBox{
            id: productCaloriesEdit
            wrap: false
            Layout.fillWidth: true

        }

        TextField {
            id: productNameEdit

            horizontalAlignment: Text.AlignLeft
            placeholderText: qsTr("Text Field")
            Layout.fillWidth: true

        }

        Button{
            id: addProductButton
            text: qsTr("add product")
            Layout.fillWidth: true

            onClicked: addProduct();


        }



    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
