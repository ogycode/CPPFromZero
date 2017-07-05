#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Для начала на окно кидаем два грида, потом выделяем их
    //и нажымаем скомпоновать по горизонтали/вертикали с приминением сплиттера

    //Устанавливаем значение каждой секции (индекс, вес)
    //1 максимальный вес/значение
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,0);

    //Также сплитеру возможно устоновить цвет
    QPalette p;                                     //палитра
    p.setColor(QPalette::Background, Qt::cyan);     //настраиваем палитру
    ui->splitter->setPalette(p);                    //применяем палитру
}

MainWindow::~MainWindow()
{
    delete ui;
}
