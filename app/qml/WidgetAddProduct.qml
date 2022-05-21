import QtQuick 2.0
import QtQuick.Controls 2.12
Item {


    TextField {
        id: textFieldName
        x: 58
        y: 63
        placeholderText: qsTr("Product name")
    }

    Button {
        id: button
        x: 58
        y: 186
        text: qsTr("add product")

        onClicked: {


            var name = textFieldName.text
            var calories = textFieldCalories.text

            Backend.addProduct(name,  calories)


        }

    }

    TextField {
        id: textFieldCalories
        x: 58
        y: 114
        placeholderText: qsTr("calories ")

        onTextChanged: {
            var nowText = text;
            var atChar = nowText[nowText.length-1]

            if ( atChar < '0' || atChar > '9' || nowText.length > 3 ){
                text = nowText.substring(0, nowText.length-1)
            }


        }


    }




}
