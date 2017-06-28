import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Grid {
        id: grid
        antialiasing: false
        anchors.fill: parent

        Label {
            id: label
            x: 298
            y: 99
            text: qsTr("Hello Wolrd!!!")
            font.italic: true
            font.pointSize: 24
            font.family: "Verdana"
            clip: false
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenterOffset: 0
            anchors.verticalCenterOffset: -100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        BusyIndicator {
            id: busyIndicator
            x: 290
            y: 238
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
