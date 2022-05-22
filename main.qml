import QtQuick
import QtQuick.Controls 2
import QtQuick.Layouts

Window {
    width: 440
    height: 100
    visible: true
    title: qsTr("CapApp")

    ColumnLayout {
        id: mainLayout
        GroupBox {
            Layout.fillWidth: true
            RowLayout {
                anchors.fill: parent
                Button {
                    text: "Connect"
                    onClicked: {
                        backend.portName = name.text
                        backend.portBaud = baud.text
                        backend.connect = true
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
                    text: backend.isConnected ? "CONNECTED" : "DISCONNECTED"
                }
            }
        }

        GroupBox {
            Layout.fillWidth: true

            GridLayout {
                Button {
                    text: "Start measure"
                }
                TextMetrics {
                    id: textMetrics
                    font.family: "Arial"
                    font.pixelSize: 20
                    text: "100.78pF"
                }

                Rectangle {
                    width: textMetrics.width
                    height: textMetrics.height

                    Text {
                        text: textMetrics.text
                        font: textMetrics.font
                    }
                }
            }
        }
    }
}
