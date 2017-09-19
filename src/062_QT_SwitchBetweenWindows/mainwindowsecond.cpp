#include "mainwindowsecond.h"
#include "ui_mainwindowsecond.h"

MainWindowSecond::MainWindowSecond(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindowSecond)
{
    ui->setupUi(this);

    connect(ui->btnCallFirst, &QPushButton::clicked, this, &MainWindowSecond::btnCallFirstClick);
}

MainWindowSecond::~MainWindowSecond()
{
    delete ui;
}

void MainWindowSecond::btnCallFirstClick()
{
    this->close();          //закрываем окно
    emit firstWindow();     //вызываем первое окно
}
