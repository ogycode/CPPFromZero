#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCursor cTarget = QCursor(QPixmap(":/cursors/target.png"));
    ui->graphicsView->setCursor(cTarget);

    QCursor cRed = QCursor(QPixmap(":/cursors/red.png"));
    ui->pushButton->setCursor(cRed);

    QCursor cGreen = QCursor(QPixmap(":/cursors/green.png"));
    this->setCursor(cGreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}
