import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import QtQuick.Controls.Material

ApplicationWindow {
    id: window
    width: 800
    height: 480
    visible: true
    title: qsTr("Audio Player")

    Material.theme: Material.Dark
    Material.accent: "#24BFB5"

    StackView {
        id: stackView

        anchors.fill: parent

        initialItem: SplashPage {
                    onSplashFinished: {
                        console.log("========== SIGNAL RECEIVED ==========")
                        stackView.push("SourcePage.qml")
                    }
                }
    }

}
