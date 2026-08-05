import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic


ApplicationWindow {
    id: window
    width: 1000
    height: 700
    visible: true
    color: "#F4F7FB"
    title: qsTr("Smart Home Control Dash Board")

    StackView {
        id: stackview_id

        anchors.fill: parent

        initialItem: LoginPage {
            id: loginPage

            onLoginSuccessful: {
                stackview_id.replace(
                    "DashboardPage.qml",
                    {
                        stackView: stackview_id
                    }
                )
            }
        }
    }

}
