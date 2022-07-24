import QtQuick 2.12
import QtQuick.Templates 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12


Rectangle {




    function addProductToDay(id){
        Backend.addProductToDay(id)
    }

    Component.onCompleted:{
        productAddListView.model.clear();

        var productList = Backend.getAllProduct();

        for (var index in productList) {
            var elm = productList[index];
            productAddListView.model.append({itemId: elm.id,  itemName:  elm.name })

        }

    }




        ListView {
            id: productAddListView
            anchors.fill: parent
            anchors.bottomMargin: 33

            model: ListModel{

            }

            delegate: Item {
                x: 5
                width: 80
                height: 40


                Row {
                    id: row1

                    Text {
                        text: itemName
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true

                    }

                    Button{
                        text: "a"
                        onClicked: {
                            addProductToDay(itemId);
                        }
                    }

                    spacing: 10
                }
            }
        }




    Button{
        id: btnOk;
        x: 8
        y: 446
        onClicked: ld.source="";
        text: qsTr("ok");
    }








}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
