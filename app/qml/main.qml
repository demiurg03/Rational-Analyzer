import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    width: 480
    height: 640
    visible: true

    title: qsTr("rationalAnalyzer")



    TextField {
        id: textField
        x: 124
        y: 23
        placeholderText: qsTr("Text Field")
        onEditingFinished: {

            var result = Backend.getProductForName(textField.text);

            for (var prop in result) {
                listView.model.append({itemId: result[prop].id,  name:  result[prop].name })
            }


        }
    }

    ListView {
        id: listView
        x: 45
        y: 108
        width: 366
        height: 433
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
