#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    numberOfButtons = 0;

    connect(ui->btnAddWidget,SIGNAL(clicked(bool)),this,SLOT(AddButtonClick()));
    connect(ui->btnRemove,SIGNAL(clicked(bool)),this,SLOT(RemoveLastButtonClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddButtonClick()
{
    numberOfButtons++;

    QPushButton *btn = new QPushButton(this);                               //Создаем кнопку

    QString name = QString("Button #%1").arg(numberOfButtons);              //Установка имени для кнопки
    btn->setText(name);                                                     //тут

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(AddedButtonClick()));       //Вешаем обработчик на клик
    ui->layoutWidgets->addWidget(btn);                                      //Добавляем кнопку в слой
}

void MainWindow::RemoveLastButtonClick()
{
    if(numberOfButtons == 0)
        return;

    QString name = QString("Button #%1").arg(numberOfButtons);                      //Имя последней кнопки

    //Т.к. в слое есть изначально label то устанавливаем i = 1
    //чтобы программа работала корректно
    for(int i = 1; i < ui->layoutWidgets->count(); i++)
    {
        QPushButton *btn = (QPushButton*)(ui->layoutWidgets->itemAt(i)->widget());

        /*
         * qobject_cast<QPushButton*> такое выражение ранво (QPushButton*) т.е.
         * если написать вместо этого
         *  QPushButton *btn = (QPushButton*)(ui->layoutWidgets->itemAt(i)->widget());
         * вот это
         *  QPushButton *btn = qobject_cast<QPushButton*>(ui->layoutWidgets->itemAt(i)->widget());
         * работа программы не изменится, это один из спсобов привести "подобные"
         * преобразование к типу
        */

        if(btn->text() == name)                                                     //Если найденая кнопка имет
        {                                                                           //установленое имя то удаляем ее
            delete btn;
            numberOfButtons--;
        }
    }
}

void MainWindow::AddedButtonClick()
{
    //Тут выводим в LineEdit имя нажатой кнопки
    QPushButton *btn = (QPushButton*) sender();
    ui->leNumber->setText(btn->text());
}
