#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Для сохранения настроек проргаммы необходимо внести
    //ее в ереестр
    QCoreApplication::setOrganizationName("Verloka");
    QCoreApplication::setOrganizationDomain("verloka.github.io");
    QCoreApplication::setApplicationName("043.QT_AppSettings");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
