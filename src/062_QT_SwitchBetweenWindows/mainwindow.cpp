#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //инициализируем второе окно
    sc = new MainWindowSecond();
    //конектим слот к сигналу
    connect(sc,&MainWindowSecond::firstWindow, this, &MainWindow::show);

    connect(ui->btnCallSecond, &QPushButton::clicked, this, &MainWindow::btnCallSecontClick);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sc;
}

void MainWindow::btnCallSecontClick()
{
    sc->show();         //показываем второе окно
    this->close();      //закрываем текущее
}
