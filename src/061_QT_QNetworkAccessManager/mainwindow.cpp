#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Инициализируем загрузчик
    d = new Downloader();

    //По нажатию кнопки загружаем файл
    connect(ui->btnDownload, &QPushButton::clicked, d, &Downloader::getData);
    //Читаем файл если он загрузился
    connect(d, &Downloader::onReady, this, &MainWindow::readFile);
}

MainWindow::~MainWindow()
{
    delete d;
    delete ui;
}

void MainWindow::readFile()
{
    QFile file("C:/Users/verlo/Desktop/text.xml");

    //Пытаемся открыть файл, если его нету выходим из функции
    if (!file.open(QIODevice::ReadOnly))
        return;

    //Если файл есть то его содржимое записываем в текстовое поле
    ui->tbContent->setText(file.readAll());
}
