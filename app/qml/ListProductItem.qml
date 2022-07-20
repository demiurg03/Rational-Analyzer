import QtQuick 2.0
import QtQuick.Controls 2.12

Item {

    Connections {
        target: Backend



        function onUpdateDatabase() {
            updateList();
        }


    }

    function updateList(){
        productListView.model.clear();

        var productList = Backend.getAllProduct();

        for (var index in productList) {
            var elm = productList[index];
            productListView.model.append({itemId: elm.id,  itemName:  elm.name })

        }
    }

    function removeProduct(id){
        Backend.removeProduct(id);
    }

    ListView {
        id: productListView
        anchors.fill: parent

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
                    text: "x"
                    onClicked: {
                        removeProduct(itemId);
                    }
                }

                spacing: 10
            }
        }
    }



    Component.onCompleted:{
        updateList();
    }

}

