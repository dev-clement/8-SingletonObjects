import QtQuick
import QtQuick.Controls
import com.franco.custom

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: buttonId
        text: "Click"
        onClicked: function() {
            MySingleton.doSomething()
        }
    }
}
