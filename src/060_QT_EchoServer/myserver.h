#ifndef MYSERVER_H
#define MYSERVER_H

#include <QDebug>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyServer : public QObject
{
    Q_OBJECT
private:
    QTcpServer *server;
    QTcpSocket *socket;

public:
    explicit MyServer(QObject *parent = 0);
    ~MyServer();

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
};

#endif // MYSERVER_H
