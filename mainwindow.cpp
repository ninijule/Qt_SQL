#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug("Database Connection");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.1.230");
    db.setUserName("julian");
    db.setPassword("");
    db.setDatabaseName("test");
    if(db.open()){
        qDebug("bonjour");
        QMessageBox::information(this, "Connection", "Database connectzed");
    }else{
        qDebug() << "errors:" << db.lastError();
    }

}

