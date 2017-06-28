import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        id: labelForChange
        x: 229
        y: 125
        text: qsTr("Text for experience")
        font.pointSize: 24
        font.family: "Verdana"
        anchors.verticalCenterOffset: -150
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    RowLayout {
        id: rowLayout
        x: 0
        y: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        ComponentCellColor {fillItemColor: "white"; onClicked: labelForChange.color = fillItemColor}
        ComponentCellColor {fillItemColor: "red"; onClicked: labelForChange.color = fillItemColor}
        ComponentCellColor {fillItemColor: "yellow"; onClicked: labelForChange.color = fillItemColor}
        ComponentCellColor {fillItemColor: "blue"; onClicked: labelForChange.color = fillItemColor}
        ComponentCellColor {fillItemColor: "green"; onClicked: labelForChange.color = fillItemColor}
        ComponentCellColor {fillItemColor: "cyan"; onClicked: labelForChange.color = fillItemColor}
        ComponentCellColor {fillItemColor: "black"; onClicked: labelForChange.color = fillItemColor}
    }
}
