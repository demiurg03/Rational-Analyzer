import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: item1
    width: 480
    height: 640


        TextField {
            id: textField
            anchors.top: parent.top
            anchors.topMargin: 25
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: qsTr("Text Field")
            onEditingFinished: {

//FIXME: reanme getProductByName
                var result = Backend.getProductForName(textField.text);

                for (var prop in result) {
                    listView.model.append({itemId: result[prop].id,  name:  result[prop].name })
                }


            }
        }

        ListView {
            id: listView
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: textField.bottom
            anchors.bottom: parent.bottom
            anchors.topMargin: 25
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
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
                            console.log(itemId)
                            listView.model.remove(index);
                        }
                    }

                    spacing: 10
                }
            }
        }

}
