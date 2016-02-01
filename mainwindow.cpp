#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // DriverName
    db.setDatabaseName("./testDatabase.db");

    if(!db.open()) // db open
    {
        ui->label->setText("Failed to open Database");
        QMessageBox::information(NULL,"ERROR","DB don't Open");
    }
    else
        ui->label->setText("Connected");


    QSqlQuery query;
    query.prepare("CREATE TABLE PERSON (id INTEGER PRIMARY KEY,mac TEXT, username TEXT, cookie TEXT, url TEXT)");


    if(!query.exec()) {
        QMessageBox::information(NULL,"ERROR","DB don't Open0");
        return ;
    }

    query.prepare("insert into person values(101, 'FF:FF:FF:FF:FF:FF', 'Young','cookie','url')");

    if(!query.exec()) {
        QMessageBox::information(NULL,"ERROR","DB don't Open1");
        return ;
    }

    query.prepare("SELECT * FROM PERSON");
    if(!query.exec()) {
        QMessageBox::information(NULL,"ERROR","DB don't Open2");
        return ;
    }
    while(query.next()) {
        qDebug("id = %d" ,query.value(0).toInt());

    }


}
MainWindow::~MainWindow()
{
    delete ui;
}
