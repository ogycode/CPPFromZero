#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, &QTcpServer::newConnection, this, &MyServer::slotNewConnection);

    //6000 порт который слушаем
    if(server->listen(QHostAddress::Any, 6000))
        qDebug() << "Server is started!";
    else
        qDebug() << "Server isn't started!";
}

MyServer::~MyServer()
{
    delete socket;
    delete server;
}

void MyServer::slotNewConnection()
{
    socket = server->nextPendingConnection();

    socket->write("Hello world! I'm Echo Server!\r\n");

    connect(socket, &QTcpSocket::readyRead, this, &MyServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyServer::slotClientDisconnected);
}

void MyServer::slotServerRead()
{
    while(socket->bytesAvailable() > 0)
    {
        QByteArray arr = socket->readAll();
        socket->write(arr);

        qDebug() << arr;
    }
}

void MyServer::slotClientDisconnected()
{
    socket->close();

    qDebug() << "Socket was closed!";
}
