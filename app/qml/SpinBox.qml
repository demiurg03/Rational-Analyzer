import QtQuick 2.0
import QtQuick.Controls 2.12
Item {


    function getValue(){
        return parseInt(textField.text)
    }


    property int inputLength: 3

    TextField {
        id: textField
        x: 40
        y: 100
        width: 120


        onTextChanged: {
            var nowText = text;
            var atChar = nowText[nowText.length-1]

            if ( atChar < '0' || atChar > '9' || nowText.length > inputLength ){
                text = nowText.substring(0, nowText.length-1)
            }


        }


    }

}
