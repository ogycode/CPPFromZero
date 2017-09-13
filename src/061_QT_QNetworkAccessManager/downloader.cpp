#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    //Инициализируем менеджер подлючения
    manager = new QNetworkAccessManager();
    //конектим слот завершения получения данных к слоту onResult
    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
}
Downloader::~Downloader()
{
    delete manager;
}

void Downloader::getData()
{
    qDebug() << "Start downloading...";
    QUrl url("http://www.mtbank.by/currxml.php");   //url файла для загрузки
    QNetworkRequest req;                            //запрос
    req.setUrl(url);                                //устанавливаем url в запрос
    manager->get(req);                              //ыполняем запрос с помошью менеджера подключений
}

void Downloader::onResult(QNetworkReply *reply)
{
    //Тут обработка ошибки, если такова произошла при загрузке
    if(reply->error())
    {
        qDebug() << "Error:";
        qDebug() << reply->errorString();
    }
    else
    {
        //Если ошибки нету то создаем обьект файла для подальшей работы с файлом
        QFile *file = new QFile("C:/Users/verlo/Desktop/text.xml");
        if(file->open(QFile::WriteOnly))            //Открываем или создем файл для записи
        {
            file->write(reply->readAll());          //Записываем
            file->close();                          //Закрываем

            qDebug() << "Download completed!";
            emit onReady();                         //Посылаем сигнал, что все готово
        }
    }
}
