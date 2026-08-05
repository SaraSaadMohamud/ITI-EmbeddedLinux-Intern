import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page{
    id: loginPage
    property bool isLoading: false
    signal loginSuccessful()
    background : Rectangle{
        color: "#F4F7FB"
    }

    ColumnLayout{
        anchors.centerIn: parent
        width: 350
        spacing: 15

        Image{
            Layout.alignment: Qt.AlignCenter
            source: "images/user.png"
            Layout.preferredWidth: 200
            Layout.preferredHeight: 200
            fillMode: Image.PreserveAspectFit
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: "Smart Home"
            font.pixelSize: 28
            font.bold: true
            color: "black"
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: "Control Dashboard"
            font.pixelSize: 16

            color: "#00A6D6"
        }


        TextField{
            id: userNameFeild

            Layout.fillWidth: true
            color: "#1F2937"
            placeholderTextColor: "#9CA3AF"
            placeholderText: "user name"

            background: Rectangle {
                    radius: 8
                    color: "#FFFFFF"
            }
        }

        TextField{
            id: passwordFeild

            Layout.fillWidth: true

            placeholderText: "password"
            color: "#1F2937"
            placeholderTextColor: "#9CA3AF"
            background: Rectangle {
                    radius: 8
                    color: "#FFFFFF"
            }

            echoMode: TextInput.Password
        }

        Label{
            id:errorLabel

            Layout.fillWidth: true

            color: "#DC2626"

            horizontalAlignment: Text.AlignHCenter
        }

        Button{

            id: loginButton
            text: "login"
            enabled: !loginPage.isLoading
            font.bold: true

            contentItem: Text {

                    text: loginButton.text
                    color: loginButton.enabled? "#FFFFFF": "#9CA3AF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

            background: Rectangle {
                    radius: 8

                    color: {
                        if (!loginButton.enabled)
                            return "#D1D5DB"

                        if (loginButton.pressed)
                            return "#007A9E"

                        if (loginButton.hovered)
                            return "#008FB8"

                        return "#00A6D6"
                    }
                }
            onClicked:{

                if ( (userNameFeild.text !== "") && (passwordFeild.text !== "") )
                {
                    errorLabel.text = ""
                    loginPage.isLoading = true
                    console.log("Login Started")

                    loginTimer.start()
                }
                else
                {
                     errorLabel.text = "Please enter username and password"
                }
            }
        }

        Button {
            id: exitButton

            text: "Exit"

            Layout.fillWidth: true

            contentItem: Text {
                text: exitButton.text
                color: "#FFFFFF"
                font.bold: true

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            background: Rectangle {
                radius: 8

                color: {
                    if (exitButton.pressed)
                        return "#991B1B"

                    if (exitButton.hovered)
                        return "#DC2626"

                    return "#EF4444"
                }
            }

            onClicked: {
                console.log("Application closed")
                Qt.quit()
            }
        }

        BusyIndicator{

            Layout.alignment: Qt.AlignHCenter
            running : loginPage.isLoading
            visible: loginPage.isLoading
            palette.accent: "#00A6D6"
        }

        Timer {

            id:loginTimer
            interval: 2000
            repeat: false

            onTriggered: {
                loginPage.isLoading = false
                console.log("Login Successfull")
                loginPage.loginSuccessful()
            }

        }
    }
}
