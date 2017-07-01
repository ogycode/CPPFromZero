#include "database.h"

//Конструктор
Database::Database(QObject *parent) : QObject(parent){}

//Деструктор
Database::~Database()
{
    this->CloseDatabase();
}

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
         return this->CreateTable();
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

//Метод создания таблицы
//В данном случае выполняется сырой
//sql запрос
bool Database::CreateTable()
{
    QSqlQuery q;
    if(q.exec("CREATE TABLE " TABLE_NAME "("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               TABLE_DATE           " DATE NOT NULL,"
               TABLE_TIME           " DATETIME NOT NULL,"
               TABLE_RANDOM_NUMBER  " INTEGER NOT NULL,"
               TABLE_MESSAGE        " VARCHAR(255) NOT NULL)"))
    {
        qDebug() << "Database created!";
        return true;
    }
    else
    {
        qDebug() << "Databse: error of create " << TABLE_NAME;
        qDebug() << q.lastError().text();
        return false;
    }
}

//Метод для добавления данных в таблицу
bool Database::InnerToTable(const QVariantList &data)
{
    QSqlQuery q;

    //Формируется sql запрос с ключами которые
    //потом свяжутся с данными из QVariantList
    q.prepare("INSERT INTO " TABLE_NAME " (" TABLE_DATE ","
                                             TABLE_TIME ","
                                             TABLE_RANDOM_NUMBER ","
                                             TABLE_MESSAGE ")"
              " VALUES (:Date, :Time, :Random, :Message)");

    //Связываем данные sql запроса с данными из QVariantList
    q.bindValue(":Date", data[0].toDate().toString("yyyy-MM-dd"));
    q.bindValue(":Time", data[1].toTime().toString("hh:mm"));
    //РАНДОМНОЕ ЧИСЛО ВПИСЫВЕТСЯ В ЯЧЕЙКУ С ТИПОМ ДАННЫХ INTEGER
    //ЕСЛИ ПЕРЕДАВАТЬ ДАННЫЙ В ТАКОМ ВИДЕ, data[2].toInt()
    //то будет ошибка, неоюходимо передавать только стринговом виде
    q.bindValue(":Random", data[2].toString());
    q.bindValue(":Message", data[3].toString());

    //QString str = "INSERT INTO ExampleTable('Date', 'Time', 'Message', 'Random') VALUES('2017-04-01','12:45','4','44')";

    //Выполняем запрос
    if(q.exec())
        return true;
    else
    {
        qDebug() << "Error insert into " << TABLE_NAME;
        qDebug() << q.lastError().text();
        return false;
    }
}

void Database::CloseDatabase()
{
    if(db.isOpen())
        db.close();
}
