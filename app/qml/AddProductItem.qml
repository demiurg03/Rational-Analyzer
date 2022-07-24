import QtQuick 2.12
import QtQuick.Templates 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3


Item {


    function showError(text){
        errorMessageDialog.text = text;
        errorMessageDialog.visible = true;

    }

    function addProduct(){
        var productName = productNameEdit.text;
        var productCalories = productCaloriesEdit.value;

        if(productName.length === 0){
            showError(qsTr("the name cannot be empty"));
            return;
        }


        if(productCalories === 0){
            showError(qsTr("calories cannot be equal to 0"));
            return;
        }


        Backend.addProduct(productName, productCalories);

    }

    MessageDialog {
        id: errorMessageDialog
        title: qsTr("Error")


    }


    ColumnLayout {
        property int margin:25

        id: row
        anchors.fill: parent
        layer.smooth: false
        anchors.topMargin: margin
        anchors.bottomMargin: margin
        anchors.leftMargin: margin
        anchors.rightMargin: margin
        spacing: 6.1




        TextField {
            id: productNameEdit

            horizontalAlignment: Text.AlignLeft
            placeholderText: qsTr("Product name")
            Layout.fillWidth: true

        }

        ColumnLayout{
            Text {
                id: text1
                text: qsTr("Calories")
                font.pixelSize: 12
            }

            SpinBox{
                id: productCaloriesEdit
                stepSize: 10
                editable: true
                to: 5000
                wrap: false
                Layout.fillWidth: true

            }
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
