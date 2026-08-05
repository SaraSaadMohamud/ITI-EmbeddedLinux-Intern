import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: settingsPage

    background: Rectangle {
        color: "#F4F7FB"
    }

    ColumnLayout {
        anchors.centerIn: parent

        spacing: 20

        Label {
            text: "Settings Page"

            font.pixelSize: 32
            font.bold: true

            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Back"

            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                StackView.view.pop()
            }
        }
    }
}