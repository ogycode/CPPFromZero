#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    f11 = new QShortcut(this);
    f11->setKey(Qt::Key_F11);
    connect(f11,SIGNAL(activated()),this,SLOT(goFullscreen()));

    ctrm = new QShortcut(this);
    ctrm->setKey(Qt::CTRL + Qt::Key_M);
    connect(ctrm, SIGNAL(activated()),this,SLOT(showMessage()));

    custom = new QShortcut(this);
    connect(custom, SIGNAL(activated()),this,SLOT(showMessage()));

    connect(ui->btnSetNew, SIGNAL(clicked(bool)),this,SLOT(btnSetNewClick()));
    connect(ui->cbEnable, SIGNAL(clicked(bool)), this, SLOT(SetEnableKeySec()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete f11;
    delete ctrm;
    delete custom;
}

void MainWindow::goFullscreen()
{
    if(this->isFullScreen())
        this->showNormal();
    else
        this->showFullScreen();
}

void MainWindow::showMessage()
{
    QMessageBox::information(this,"Shortkey", "Wow, message was shown by using shortcut! Awesome.", QMessageBox::Ok);
}

void MainWindow::btnSetNewClick()
{
    custom->setKey(ui->kseCustom->keySequence());
}

void MainWindow::SetEnableKeySec()
{
    ui->kseCustom->setEnabled(ui->cbEnable->isChecked());
}
