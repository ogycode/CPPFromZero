#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnBrowseOpen, SIGNAL(clicked(bool)), this, SLOT(btnBrowseOpenClick()));
    connect(ui->btnBrowseRead, SIGNAL(clicked(bool)),this, SLOT(btnBrowseSaveClick()));

    connect(ui->btnWrite, SIGNAL(clicked(bool)),this,SLOT(btnSaveClick()));
    connect(ui->btnRead, SIGNAL(clicked(bool)),this,SLOT(btnReadClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод, который устанавливает путь к файлу с помощью диалога выбора файла
//т.е. выбераем файл с которго будут считыватся данные
void MainWindow::btnBrowseOpenClick()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open Xml"), ".", tr("Xml files (*.xml)"));
   if(fileName != "")
       ui->lePathOpen->setText(fileName);
}

//Метод который устанавливает путь к файлу в который будут записаны параметры
//с помощью диалога выбора файла
void MainWindow::btnBrowseSaveClick()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Xml"), ".", tr("Xml files (*.xml)"));
    if(filename != "")
        ui->lePathSave->setText(filename);
}

//Метод, который записывает парметры в файл Xml
void MainWindow::btnSaveClick()
{
    if(ui->lePathSave->text() == "")
        return;

    //Открываем файл для записи
    QFile file(ui->lePathSave->text());
    file.open(QFile::WriteOnly | QFile::Text);

    QXmlStreamWriter sw(&file);                 //Создаем обьект для записи Xml
    sw.setAutoFormatting(true);                 //Устанавливаем автоформатирование

    sw.writeStartDocument();                    //Запускаем запись в домкумент
    sw.writeStartElement("resource");           //Записываем первый элемент с указанием его имени (открываем тег resource)

    sw.writeStartElement("cbExample");          //Записываем в него значения чек бокса и поля для ввода (открываем тег cbExample)
    sw.writeAttribute("boolean",(ui->cbExample->isChecked() == true ? "true" : "false"));
    sw.writeCharacters(ui->leExample->text());  //Записываем текс в тег

    /*
     * Как это будет выглядеть в файле
     *  <tag boolean="true">TEXT</tag>
    */

    sw.writeEndElement();                       //Закрываем тег cbExample

    /*
     * Сдесь можно вписываеть сотни других тегов
     * как внутри resource так и создать следующий
     * "главный тег" или просто вписывать теги как cbExample
     * без главных тегов
    */

    sw.writeEndElement();                       //Закрываем тег resource
    sw.writeEndDocument();                      //Закрываем документ

    file.close();                               //Закрываем файл
}

//
void MainWindow::btnReadClick()
{
    if(ui->lePathOpen->text() == "")
        return;

    //Открывем файл для записи
    QFile file(ui->lePathOpen->text());

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "File Error", "File is not open!", QMessageBox::Ok);
        return;
    }

    QXmlStreamReader sr;                    //Создаем обьект для чтения Xml
    sr.setDevice(&file);

    sr.readNext();                          //Считываем первый элемент

    while(!sr.atEnd())                      //В цикле пока не достигнем конца документа
    {
        if(sr.isStartElement())             //Проверяем является ли элемент началом тега
        {
            //Так с каждым тегом, нужно проверять его по имени
            //Если есть совпадение то обрабатываем
            //Так с каждым тегом которые записываем в файл, т.к.
            //записан один тег cbExample то и проверка одна
            if(sr.name() == "cbExample")
            {
                //Етим циклом просматриваем все атрибуты тега
                for(QXmlStreamAttribute atr : sr.attributes())
                {
                    if(atr.name() == "boolean")
                    {
                        QString attrValue = atr.value().toString();
                        ui->cbExample->setChecked((QString::compare(attrValue , "true") == 0) ? true : false);
                    }
                }

                ui->leExample->setText(sr.readElementText());   //Читаем из тега текс и записываем в поле
            } // else if(sr.name() == "blabla")                 //следующий элемент
        }

        sr.readNext();                      //Считываем следующий элемент
    }

    file.close();                           //Закрываем файл
}
