#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Инициализация иконки трея
    iconTray = new QSystemTrayIcon(this);
    iconTray->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
    iconTray->setToolTip("ToolTip!!!");

    //Создаем контекстное меню
    QMenu *menu = new QMenu(this);

    //Создаем наполенение для контексттного меню
    QAction *showWindow = new QAction(trUtf8("Show window"), this);
    QAction *appExit = new QAction(trUtf8("Close application"), this);

    //Добавляем наполенение в меню
    menu->addAction(showWindow);
    menu->addSeparator();
    menu->addAction(appExit);

    //Установка меню трею
    iconTray->setContextMenu(menu);

    //Установка сигналов
    //т.е. например:
    //iconTray, сигнал активации (клика) обработает слот iconTrayClick
    connect(showWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(appExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(iconTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
                      SLOT(iconTrayClick(QSystemTrayIcon::ActivationReason)));

    //Отображаем иконку в трее
    iconTray->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод, который переопределенный и срабатывает при закрытии приложения
void MainWindow::closeEvent(QCloseEvent *event)
{
    //Если окно видимо и стоит галочка, прятать приложение
    if(this->isVisible() && ui->cbHideToTray->isChecked())
    {
        //игнорируем выход
        event->ignore();
        //прячем окно
        this->hide();

        //Показываем сообжение, которое информирует, что приложение
        //свернуто в трей, для иоткрытия котрого необходимо кликнуть на иконку
        QSystemTrayIcon::MessageIcon msg = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        iconTray->showMessage("Message", trUtf8("For open click on icon"), msg, 1500);
    }
}

//Слот, оброботчик события кликанья по иконке трея
void MainWindow::iconTrayClick(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger && !this->isVisible())
        this->show();
}









