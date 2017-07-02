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
#define DATABSE_NAME        "SecondDatabase.db"

#define MAIN_TABLE_NAME     "MainTable"
#define MAIN_TABLE_DATE     "Date"
#define MAIN_TABLE_TIME     "Time"
#define MAIN_TABLE_IP       "Ip"
#define MAIN_TABLE_HOST     "Hostname"

#define DEVICE_TABLE_NAME   "DeviceTable"
#define DEVICE_TABLE_IP     "Ip"
#define DEVICE_TABLE_HOST   "Hostname"

class Database : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;

public:
    explicit Database(QObject *parent = 0);
    ~Database();

    void ConnectToBase();
    bool InserToMainTable(const QVariantList &data);
    bool InserToDeviceTable(const QVariantList &data);

private:
    bool OpenDatabase();
    bool RestoreDatabase();
    void CloseDatabase();
    bool CreateMainTable();
    bool CreateDeviceTable();
};

#endif // DATABASE_H
