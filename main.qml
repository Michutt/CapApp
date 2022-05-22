import QtQuick
import QtQuick.Controls 2
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("CapApp")

    RowLayout {
        Button {
            text: "Connect"
            onClicked: {
                backend.portName = name.text
                backend.portBaud = baud.text
                backend.isConnected = true
            }
        }
        TextField {
            id: name
            width: 160
            placeholderText: "Port Name"
        }
        TextField {
            id: baud
            width: 160
            placeholderText: "Port Baud"
        }
        Text {
            text: "CONNECTED"
        }
    }
}
