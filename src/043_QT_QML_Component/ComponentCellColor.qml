//Это файл компонента, что-то наподобии UserControll в WPF

import QtQuick 2.0

Item {
    id: container
    //Обьявление буюличного свойства для установки цвета
    //в данном случае это свойство является псевдонимом для rectangle.color
    property alias fillItemColor: rectangle.color
    signal clicked(color FillItemColor)
    width: 50
    height: 50
    visible: true
    clip: false


    //Rectangle, в данном случае, устанавливает, какой будет
    //именть вид наш контролл
    Rectangle {
            id: rectangle
            width: 50
            height: 50
            color: "#ffffff"
            radius: 10
            border.width: 3
        }

    //Место, в данном случае, весь контрол, где будет срабатывать сигнал(событие)
    //нажатие кнопки мыши, клик
    MouseArea {
                anchors.fill: parent
                onClicked: container.clicked(container.FillItemColor)
            }
}
