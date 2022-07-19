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
        listView.model.clear();

        var productList = Backend.getAllProduct();

        for (var index in productList) {
            var elm = productList[index];
            listView.model.append({itemId: elm.id,  name:  elm.name })

        }
    }

    ListView {
        id: listView
        anchors.fill: parent

        model: ListModel {
        }


        delegate: Item {
            x: 5
            width: 80
            height: 40


            Row {
                id: row1

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true

                }

                Button{
                    text: "x"
                    onClicked: {
                        listView.model.remove(index);
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

