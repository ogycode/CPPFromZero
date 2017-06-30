#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * В данном приложении в поле для редактирования возможно
 * вводить только ip адрес, другие символы просто не будут
 * вводится, только точка, после каждого номера
 * 255.255.255.255 - введется
 * 256.255.255.255 - нет
*/

//Конструктор окна
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Строка регулярного выражения
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";

    //Регулярное выражение
    QRegExp ipRegex ("^" + ipRange + "\\." + ipRange + "\\." + ipRange + "\\." + ipRange + "$");

    //Валидатор, применится к leIpAddress
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);

    //Установка валидатора на поле
    ui->leIpAddress->setValidator(ipValidator);
}

//Деструктор
MainWindow::~MainWindow()
{
    delete ui;
}
