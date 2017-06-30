#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Обьект для работы с настройками приложения
    QSettings settings("Verloka", "043.QT_AppSettings");

    //Загружаем сохраненые настрройки
    int left = settings.value("LEFT", 150).toInt();
    int right = settings.value("RIGHT", 150).toInt();
    int width = settings.value("WIDTH", 150).toInt();
    int height = settings.value("HEIGHT", 150).toInt();

    //применяем настройки
    this->setGeometry(left,right,width,height);

    //назначаем сигнал и слот для кнопки
    connect(ui->btnSave, SIGNAL(clicked(bool)),this, SLOT(btnSaveAppSettingClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Обработка события нажатия кнопки
void MainWindow::btnSaveAppSettingClick()
{
    //Сохранение параметров
    QSettings settings("Verloka", "043.QT_AppSettings");

    settings.setValue("LEFT", this->geometry().x());
    settings.setValue("RIGHT", this->geometry().y());
    settings.setValue("WIDTH", this->geometry().width());
    settings.setValue("HEIGHT", this->geometry().height());

    settings.sync();

    //MessageBox
    QMessageBox::information(this, trUtf8("Information"), trUtf8("Saving completed!"));
}
