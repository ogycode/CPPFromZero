#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new MyGraphicView();             //Инициализируем виджет
    ui->gridLayout->addWidget(view);            //кидаем его на грид
}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
}
