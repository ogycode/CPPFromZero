#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Первым делом необходимо создать обьект базы данных
    db = new Database();
    db->ConnectToBase();

    //Наполняем контентом базу данных
    for(int i = 0; i < 10; i++)
    {
        QVariantList data;
        QString random = QString::number(1 + qrand() % 3);
        data.append(QDate::currentDate());
        data.append(QTime::currentTime());
        data.append(random);
        data.append(random);
        db->InserToMainTable(data);
    }
    for(int i = 1; i < 4; i++)
    {
        QVariantList data;
        data.append("Device " + QString::number(i));
        data.append("192.168.0." + QString::number(i));
        db->InserToDeviceTable(data);
    }

    //Инициализация моделей для представления
    this->SetupMainModel(MAIN_TABLE_NAME, QStringList()
                         << trUtf8("id")
                         << trUtf8("Date")
                         << trUtf8("Time")
                         << trUtf8("Ip")
                         << trUtf8("Host"));

    this->SetupDeviceModel(DEVICE_TABLE_NAME, QStringList()
                           << trUtf8("id")
                           << trUtf8("Host")
                           << trUtf8("Ip"));


    this->SetupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;
    delete mainModel;
    delete deviceModel;
}

void MainWindow::SetupMainModel(const QString &name, const QStringList &headers)
{
    //Инициализация модели и установка имени табицы
    mainModel = new QSqlRelationalTableModel(this);
    mainModel->setTable(name);

    //Установка связей таблиц
    //Метод setRelation указывается номер колонки в которую будет подставлятся
    //подстановка данных, а также с помощью QSqlRelation указывается имя таблицы
    //и параметр по которому будет производится выборка строки и колонка с
    //которой будут взяты данные

    //т.е. при наполнении таблицы в ячейки main таблицы записываются рандомные
    //числа (в данном случае от 1 до 3) и это является id девайсов в
    //device таблице
    mainModel->setRelation(3, QSqlRelation(DEVICE_TABLE_NAME, "id", DEVICE_TABLE_IP));
    mainModel->setRelation(4, QSqlRelation(DEVICE_TABLE_NAME, "id", DEVICE_TABLE_HOST));

    //Установка названия колонок в таблице
    for(int i = 0, j = 0; i < mainModel->columnCount(); i++, j++)
        mainModel->setHeaderData(i,Qt::Horizontal,headers[j]);

    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    mainModel->setSort(0,Qt::AscendingOrder);


    // Делаем выборку данных из таблицы
    mainModel->select();
}

void MainWindow::SetupDeviceModel(const QString &name, const QStringList &headers)
{
    //Инициализация модели и установка имени табицы
    deviceModel = new QSqlRelationalTableModel(this);
    deviceModel->setTable(name);

    //Установка названия колонок в таблице
    for(int i = 0, j = 0; i < deviceModel->columnCount(); i++, j++)
        deviceModel->setHeaderData(i,Qt::Horizontal,headers[j]);

    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    deviceModel->setSort(0,Qt::AscendingOrder);


    // Делаем выборку данных из таблицы
    deviceModel->select();
}

void MainWindow::SetupUI()
{
    ui->tvHost->setModel(mainModel);                                    // Устанавливаем модель на TableView
    ui->tvHost->setColumnHidden(0, true);                               // Скрываем колонку с id записей
    ui->tvHost->setSelectionBehavior(QAbstractItemView::SelectRows);    // Разрешаем выделение строк
    ui->tvHost->resizeColumnsToContents();                              // Устанавливаем размер колонок по содержимому
    ui->tvHost->setItemDelegate(new QSqlRelationalDelegate(ui->tvHost));
    ui->tvHost->setEditTriggers(QAbstractItemView::NoEditTriggers);     //Запрет редактрования
    ui->tvHost->horizontalHeader()->setStretchLastSection(true);

    mainModel->select(); // Делаем выборку данных из таблицы

    ui->tvDevices->setModel(deviceModel);                               // Устанавливаем модель на TableView
    ui->tvDevices->setColumnHidden(0, true);                            // Скрываем колонку с id записей
    ui->tvDevices->setSelectionBehavior(QAbstractItemView::SelectRows); // Разрешаем выделение строк
    ui->tvDevices->resizeColumnsToContents();                           // Устанавливаем размер колонок по содержимому
    ui->tvDevices->setItemDelegate(new QSqlRelationalDelegate(ui->tvDevices));
    ui->tvDevices->setEditTriggers(QAbstractItemView::NoEditTriggers);  //Запрет редактрования
    ui->tvDevices->horizontalHeader()->setStretchLastSection(true);

    deviceModel->select();
}
