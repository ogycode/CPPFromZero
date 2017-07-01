#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOST_NAME  "MyQTDatabase"
#define DATABSE_NAME        "FirstDatabase.db"

#define TABLE_NAME          "ExampleTable"
#define TABLE_DATE          "Date"
#define TABLE_TIME          "Time"
#define TABLE_MESSAGE       "Message"
#define TABLE_RANDOM_NUMBER "Random"


class Database : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;

public:
    explicit Database(QObject *parent = 0);
    ~Database();

    void ConnectToBase();
    bool InnerToTable(const QVariantList &data);

private:
    bool OpenDatabase();
    bool RestoreDatabase();
    void CloseDatabase();
    bool CreateTable();
};

#endif // DATABASE_H
