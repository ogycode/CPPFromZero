#include "database.h"

//Конструктор
Database::Database(QObject *parent) : QObject(parent){}

//Деструктор
Database::~Database() {  this->CloseDatabase(); }

//Метод подключения к базе данных
void Database::ConnectToBase()
{
    //Если бд нет, то восстанавливаем ее
    //Если есть то открываем
    if(QFile("C:/DB/" DATABSE_NAME).exists())
        this->OpenDatabase();
    else
        this->RestoreDatabase();
}

//Метод восстоновления бд
bool Database::RestoreDatabase()
{
    if(this->OpenDatabase())
    {
         return this->CreateMainTable() && this->CreateDeviceTable();
    }
    else
    {
        qDebug() << "Can't restore DB!";
        return false;
    }
}

//Открытие базы данных
bool Database::OpenDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOST_NAME);
    db.setDatabaseName("C:/DB/" DATABSE_NAME);

    qDebug() << "Database opened!";

    return db.open();
}

//Метод создания Main таблицы
//В данном случае выполняется сырой
//sql запрос
bool Database::CreateMainTable()
{
    QSqlQuery q;
    if(q.exec("CREATE TABLE " MAIN_TABLE_NAME "("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               MAIN_TABLE_DATE           " DATE         NOT NULL,"
               MAIN_TABLE_TIME           " DATETIME     NOT NULL,"
               MAIN_TABLE_IP             " INTEGER      NOT NULL,"
               MAIN_TABLE_HOST           " INTEGER      NOT NULL)"))
    {
        qDebug() << "Table " MAIN_TABLE_NAME " created!";
        return true;
    }
    else
    {
        qDebug() << "Databse: error of create " << MAIN_TABLE_NAME;
        qDebug() << q.lastError().text();
        return false;
    }
}

//Метод создания Device таблицы
//В данном случае выполняется сырой
//sql запрос
bool Database::CreateDeviceTable()
{
    QSqlQuery q;
    if(q.exec("CREATE TABLE " DEVICE_TABLE_NAME "("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               DEVICE_TABLE_HOST      " VARCHAR(255)      NOT NULL,"
               DEVICE_TABLE_IP        " VARCHAR(16)       NOT NULL)"))
    {
        qDebug() << "Table " DEVICE_TABLE_NAME " created!";
        return true;
    }
    else
    {
        qDebug() << "Databse: error of create " << DEVICE_TABLE_NAME;
        qDebug() << q.lastError().text();
        return false;
    }
}

//Метод для добавления данных в Main таблицу
bool Database::InserToMainTable(const QVariantList &data)
{
    QSqlQuery q;

    //Формируется sql запрос с ключами которые
    //потом свяжутся с данными из QVariantList
    q.prepare("INSERT INTO " MAIN_TABLE_NAME " (" MAIN_TABLE_DATE ","
                                                  MAIN_TABLE_TIME ","
                                                  MAIN_TABLE_IP ","
                                                  MAIN_TABLE_HOST ")"
              " VALUES (:Date, :Time, :Ip, :Host)");

    //Связываем данные sql запроса с данными из QVariantList
    q.bindValue(":Date", data[0].toDate().toString("yyyy-MM-dd"));
    q.bindValue(":Time", data[1].toTime().toString("hh:mm"));
    q.bindValue(":Ip", data[2].toString());
    q.bindValue(":Host", data[3].toString());

    //Выполняем запрос
    if(q.exec())
        return true;
    else
    {
        qDebug() << "Error insert into " << MAIN_TABLE_NAME;
        qDebug() << q.lastError().text();
        return false;
    }
}

//Метод для добавления данных в Device таблицу
bool Database::InserToDeviceTable(const QVariantList &data)
{
    QSqlQuery q;

    //Формируется sql запрос с ключами которые
    //потом свяжутся с данными из QVariantList
    q.prepare("INSERT INTO " DEVICE_TABLE_NAME " (" DEVICE_TABLE_HOST ","
                                                    DEVICE_TABLE_IP ")"
              " VALUES (:Host, :Ip)");

    //Связываем данные sql запроса с данными из QVariantList
    q.bindValue(":Host", data[0].toString());
    q.bindValue(":Ip", data[1].toString());

    //Выполняем запрос
    if(q.exec())
        return true;
    else
    {
        qDebug() << "Error insert into " << DEVICE_TABLE_NAME;
        qDebug() << q.lastError().text();
        return false;
    }
}

void Database::CloseDatabase()
{
    if(db.isOpen())
        db.close();
}
