import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Page {
    id: loginPage

    property bool isLoading: false

    signal loginSuccessful()

    // =====================================
    // Update Texts After Language Change
    // =====================================

    function updateTexts() {

        titleLabel.text =
                qsTr("Smart Home")

        subtitleLabel.text =
                qsTr("Control Dashboard")

        descriptionLabel.text =
                qsTr("Control your smart home\nfrom one simple dashboard")

        userNameFeild.placeholderText =
                qsTr("user name")

        passwordFeild.placeholderText =
                qsTr("password")

        loginButton.text =
                qsTr("Login")

        exitButton.text =
                qsTr("Exit")
    }

    // =====================================
    // Language Manager
    // =====================================

    Connections {

        target: languageManager

        function onLanguageChanged() {

            console.log(
                "LOGIN: languageChanged received"
            )

            loginPage.updateTexts()

            console.log(
                "LOGIN: texts updated"
            )
        }
    }

    // =====================================
    // Initial Text
    // =====================================

    Component.onCompleted: {

        console.log(
            "LOGIN: Component completed"
        )

        loginPage.updateTexts()
    }

    // =====================================
    // Background Image
    // =====================================

    Image {

        id: backgroundImage

        anchors.fill: parent

        source:
            "images/smart_home_background.png"

        fillMode:
            Image.PreserveAspectCrop

        asynchronous: true

        opacity: 0.82
    }

    // =====================================
    // Dark Overlay
    // =====================================

    Rectangle {

        anchors.fill: parent

        color: "#061A2D"

        opacity: 0.60
    }

    // =====================================
    // Soft Blue Glow
    // =====================================

    Rectangle {

        id: glowCircle

        width: 500
        height: 500

        radius: width / 2

        color: "#00CFFF"

        opacity: 0.06

        x: -230

        y: parent.height / 2 - height / 2

        SequentialAnimation on x {

            loops: Animation.Infinite

            NumberAnimation {

                from: -230
                to: -160

                duration: 4000

                easing.type:
                    Easing.InOutSine
            }

            NumberAnimation {

                from: -160
                to: -230

                duration: 4000

                easing.type:
                    Easing.InOutSine
            }
        }
    }

    // =====================================
    // Main Layout
    // =====================================

    RowLayout {

        anchors.fill: parent

        anchors.leftMargin: 70
        anchors.rightMargin: 70

        anchors.topMargin: 45
        anchors.bottomMargin: 45

        spacing: 70

        // =================================
        // LEFT SIDE
        // =================================

        Item {

            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.minimumWidth: 380

            ColumnLayout {

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            anchors.horizontalCenterOffset: 230
            anchors.verticalCenterOffset:  200

                spacing: 10

                Label {
                    id: smartLabel

                    text: qsTr("SMART")

                    font.pixelSize: 18
                    font.bold: true
                    color: "#00D9FF"

                    Layout.alignment:
                        Qt.AlignHCenter
                }

                Label {
                    id: homeLabel

                    text: qsTr("HOME")

                    font.pixelSize: 58
                    font.bold: true
                    color: "#FFFFFF"

                    Layout.alignment:
                        Qt.AlignHCenter
                }

                Rectangle {
                    Layout.preferredWidth: 75
                    Layout.preferredHeight: 3

                    radius: 2
                    color: "#00BFEF"

                    Layout.alignment:
                        Qt.AlignHCenter
                }

                Label {
                    id: descriptionLabel

                    text: ""

                    font.pixelSize: 16
                    color: "#E5F8FF"

                    horizontalAlignment:
                        Text.AlignHCenter

                    Layout.alignment:
                        Qt.AlignHCenter

                    lineHeight: 1.35
                    topPadding: 8
                }
            }
        }

        // =================================
        // LOGIN CARD
        // =================================

        Item {

            Layout.preferredWidth: 360

            Layout.preferredHeight: 460

            Layout.alignment:
                Qt.AlignVCenter

            // =============================
            // Card Shadow
            // =============================

            Rectangle {

                anchors.fill: loginCard

                anchors.margins: -10

                radius: 28

                color: "#000000"

                opacity: 0.25

                z: -1
            }

            // =============================
            // Main Card
            // =============================

            Rectangle {

                id: loginCard

                anchors.fill: parent

                radius: 22

                color: "#F8FAFC"

                opacity: 0.98

                border.color: "#FFFFFF"

                border.width: 1

                // =========================
                // Card Entry Animation
                // =========================

                scale: 0.96

                Component.onCompleted: {

                    cardAnimation.start()
                }

                SequentialAnimation {

                    id: cardAnimation

                    ParallelAnimation {

                        NumberAnimation {

                            target: loginCard

                            property: "scale"

                            from: 0.96
                            to: 1.0

                            duration: 450

                            easing.type:
                                Easing.OutCubic
                        }

                        NumberAnimation {

                            target: loginCard

                            property: "opacity"

                            from: 0
                            to: 0.98

                            duration: 450

                            easing.type:
                                Easing.OutCubic
                        }
                    }
                }



                // =========================
                // Card Content
                // =========================

                ColumnLayout {

                    anchors.fill: parent

                    anchors.leftMargin: 38
                    anchors.rightMargin: 38

                    anchors.topMargin: 28
                    anchors.bottomMargin: 28

                    spacing: 12

                    // =====================
                    // User Icon
                    // =====================

                    Rectangle {

                        Layout.alignment:
                            Qt.AlignHCenter

                        Layout.preferredWidth: 64
                        Layout.preferredHeight: 64

                        radius: 32

                        color: "#E7F8FC"

                        border.color: "#D0F2FA"

                        border.width: 1

                        Image {

                            anchors.centerIn: parent

                            width: 42
                            height: 42

                            source:
                                "images/user.png"

                            fillMode:
                                Image.PreserveAspectFit
                        }
                    }

                    // =====================
                    // Title
                    // =====================

                    Label {

                        id: titleLabel

                        Layout.alignment:
                            Qt.AlignHCenter

                        text: ""

                        font.pixelSize: 25

                        font.bold: true

                        color: "#102A43"

                        topPadding: 2
                    }

                    // =====================
                    // Subtitle
                    // =====================

                    Label {

                        id: subtitleLabel

                        Layout.alignment:
                            Qt.AlignHCenter

                        text: ""

                        font.pixelSize: 14

                        color: "#00A6D6"
                    }

                    Item {

                        Layout.preferredHeight: 8
                    }

                    // =====================
                    // Username
                    // =====================

                    TextField {

                        id: userNameFeild

                        Layout.fillWidth: true

                        Layout.preferredHeight: 44

                        color: "#1F2937"

                        placeholderText: ""

                        placeholderTextColor:
                            "#9CA3AF"

                        leftPadding: 14

                        font.pixelSize: 14

                        background: Rectangle {

                            radius: 9

                            color: "#FFFFFF"

                            border.color:
                                userNameFeild.activeFocus
                                ? "#00A6D6"
                                : "#DDE3EA"

                            border.width: 1
                        }
                    }

                    // =====================
                    // Password
                    // =====================

                    TextField {

                        id: passwordFeild

                        Layout.fillWidth: true

                        Layout.preferredHeight: 44

                        color: "#1F2937"

                        placeholderText: ""

                        placeholderTextColor:
                            "#9CA3AF"

                        leftPadding: 14

                        font.pixelSize: 14

                        echoMode:
                            TextInput.Password

                        background: Rectangle {

                            radius: 9

                            color: "#FFFFFF"

                            border.color:
                                passwordFeild.activeFocus
                                ? "#00A6D6"
                                : "#DDE3EA"

                            border.width: 1
                        }
                    }

                    // =====================
                    // Error Label
                    // =====================

                    Label {

                        id: errorLabel

                        Layout.fillWidth: true

                        Layout.preferredHeight: 18

                        text: ""

                        color: "#DC2626"

                        font.pixelSize: 12

                        horizontalAlignment:
                            Text.AlignHCenter
                    }

                    // =====================
                    // Login Button
                    // =====================

                    Button {

                        id: loginButton

                        Layout.fillWidth: true

                        Layout.preferredHeight: 44

                        text: ""

                        enabled:
                            !loginPage.isLoading

                        font.bold: true

                        contentItem: Text {

                            text:
                                loginButton.text

                            color: "#FFFFFF"

                            font.pixelSize: 14

                            font.bold: true

                            horizontalAlignment:
                                Text.AlignHCenter

                            verticalAlignment:
                                Text.AlignVCenter
                        }

                        background: Rectangle {

                            radius: 9

                            color: {

                                if (!loginButton.enabled)
                                    return "#A8B0B8"

                                if (loginButton.pressed)
                                    return "#007A9E"

                                if (loginButton.hovered)
                                    return "#008FB8"

                                return "#00A6D6"
                            }
                        }

                        onClicked: {

                            if ((userNameFeild.text !== "") &&
                                (passwordFeild.text !== "")) {

                                errorLabel.text = ""

                                loginPage.isLoading = true

                                console.log(
                                    "Login Started"
                                )

                                loginTimer.start()

                            } else {

                                errorLabel.text =
                                    qsTr(
                                        "Please enter username and password"
                                    )
                            }
                        }
                    }
                    // =====================
                    // Exit Button
                    // =====================

                    Button {

                        id: exitButton

                        Layout.fillWidth: true

                        Layout.preferredHeight: 40

                        text: ""

                        contentItem: Text {

                            text: exitButton.text

                            color: exitButton.hovered
                                   ? "#FFFFFF"
                                   : "#EF4444"

                            font.pixelSize: 14

                            font.bold: true

                            horizontalAlignment:
                                Text.AlignHCenter

                            verticalAlignment:
                                Text.AlignVCenter
                        }

                        background: Rectangle {

                            radius: 9

                            color: {

                                if (exitButton.pressed)
                                    return "#DC2626"

                                if (exitButton.hovered)
                                    return "#EF4444"

                                return "#FFFFFF"
                            }

                            border.color:
                                "#EF4444"

                            border.width: 1
                        }

                        onClicked: {

                            console.log(
                                "Application closed"
                            )

                            Qt.quit()
                        }
                    }


                    // =====================
                    // Loading Indicator
                    // =====================

                    BusyIndicator {

                        Layout.alignment:
                            Qt.AlignHCenter

                        Layout.preferredWidth: 24
                        Layout.preferredHeight: 24

                        running:
                            loginPage.isLoading

                        visible:
                            loginPage.isLoading

                        palette.accent:
                            "#00A6D6"
                    }
                }
            }
        }
    }

    // =====================================
    // Login Timer
    // =====================================

    Timer {

        id: loginTimer

        interval: 2000

        repeat: false

        onTriggered: {

            loginPage.isLoading = false

            console.log(
                "Login Successful"
            )

            loginPage.loginSuccessful()
        }
    }
}