#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    point = new MyPoint();

    //коннектим сигнал и слот
    connect(point, SIGNAL(pointClick()),this, SLOT(slotFromForm()));

    //устанавливаем сцену и точку на нее
    ui->graphicsView->setScene(scene);
    scene->addItem(point);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete point;
    delete scene;
}

void MainWindow::slotFromForm()
{
    QMessageBox::information(this, "Clicked", "You are click the button, now");
}
