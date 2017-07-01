#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myDB = new Database();
    myDB->ConnectToBase();

    //Наполняем таблицу данными по 10 штук за каждый запуск приложения
    for(int i = 0; i < 10; i++)
    {
        QVariantList data;
        int random = qrand();                                   // Получаем случайные целые числа для вставки а базу данных
        data.append(QDate::currentDate());                      // Получаем текущую дату для вставки в БД
        data.append(QTime::currentTime());                      // Получаем текущее время для вставки в БД
        data.append(random);                                    // Подготавливаем полученное случайное число для вставки в БД
        data.append("Message from " + QString::number(random)); // Подготавливаем сообщение для вставки в базу данных

        // Вставляем данные в БД
        myDB->InnerToTable(data);
    }

    //Инициализируем модел для представления данных
    this->SetupModel(TABLE_NAME, QStringList()
                                       << trUtf8("id")
                                       << trUtf8("Дата")
                                       << trUtf8("Время")
                                       << trUtf8("Рандомное число")
                                       << trUtf8("Сообщение"));

    //Инициализируем внешний вид таблици с данными
    this->CreateUI();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete myDB;
    delete dbModel;
}

//Метод установки модели отображения данных
void MainWindow::SetupModel(const QString &name, const QStringList &headers)
{
    //Инициаилзация модели представления данных
    //с установкой имени таблици по которому
    //будет производится обращение к таблице
    dbModel = new QSqlTableModel(this);
    dbModel->setTable(name);

    //Устанавливаем навзания колонок в таблице
    for (int i = 0, j = 0; i < dbModel->columnCount();i++, j++)
        dbModel->setHeaderData(i, Qt::Horizontal, headers[j]);

    //Устанавливаем сортировку  по нулевому столбцу по возрастанию
    dbModel->setSort(0, Qt::AscendingOrder);
}

void MainWindow::CreateUI()
{
    ui->tableView->setModel(dbModel);                                     //привязываем модель к контролу
    ui->tableView->setColumnHidden(0, true);                            //скрываем первый столбец (id)
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);   //разрешаем выделение строк
    ui->tableView->selectionMode();                                       //Выделение только одной строки
    ui->tableView->resizeColumnsToContents();                             //Размер колонки по контенту
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);    //Запрет редактирования
    ui->tableView->horizontalHeader()->setStretchLastSection(true);       //Последняя колонка имеет макс. размер

    //Делаем выборку данных из таблицы
    dbModel->select();
}
