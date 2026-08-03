import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic


ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World App")

    property string my_name: "Sara Saad"
    property int age: 22

    Rectangle{
        anchors.centerIn: parent
        width: 600
        height: 350
        color: "white"
        border.color: "red"
        border.width: 2
        radius: 5

        Column{
            spacing: 15
            anchors.centerIn: parent

        Text{
            id:userInfo
            font.pixelSize: 20
            font.bold: true
            text: qsTr("                            User Information")
        }

        Text{
            id:name
            text:qsTr("Name: "+my_name)
            font.pixelSize: 15
            font.bold: true
        }
        Text{
            id:ageText
            text:qsTr("Age: "+age)
            font.pixelSize: 15
            font.bold: true
        }
        Text{
            id:university
            text:qsTr("University: Al-Azher University")
            font.pixelSize: 15
            font.bold: true
        }

        Text{
            id:department
            text:qsTr("Department: Electronics and Communication Enginnering")
            font.pixelSize: 15
            font.bold: true
        }

        Text{
            id: feild
            text:qsTr("Feild: Robotics Engineer")
            font.pixelSize: 15
            font.bold: true
        }

        Text{
            id:city
            text:qsTr("City: Giza")
            font.pixelSize: 15
            font.bold: true
        }

        Text{
            id:address
            font.pixelSize: 15
            font.bold: true
            text:qsTr("Address: El Fath Street")
        }

        Text{
            id:number
            font.pixelSize: 15
            font.bold: true
            text:qsTr("PhoneNumber: +022987532062")
        }

        }


    }

}
