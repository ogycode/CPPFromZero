#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>

class Downloader : public QObject
{
    Q_OBJECT
private:
    //менеджер для доступа в сеть
    QNetworkAccessManager *manager;

public:
    explicit Downloader(QObject *parent = 0);
    ~Downloader();

signals:
    void onReady();

public slots:
    void getData();                         //запрос на получение данных
    void onResult(QNetworkReply *reply);    //ответ о полученых данных
};

#endif // DOWNLOADER_H
