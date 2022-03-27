#include "db_connexion.h"
#include "home.h"
#include "ui_home.h"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "qdebug.h"


Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap LogoThales("C:/Users/Julian/Documents/Qt_SQL/logo.jpg");
    ui->LogoThales->setPixmap(LogoThales.scaled(300,150, Qt::KeepAspectRatio));
    ui->LogoThales->setAlignment(Qt::AlignCenter);
    tableWidget();
}

Home::~Home()
{
    delete ui;
}

void Home::tableWidget(){

        QSqlTableModel *mModel;
        mModel = new QSqlTableModel(this);
        mModel->setTable("airplane");
        mModel->select();
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->setGeometry(100,150, 600, 400);
        ui->tableView->setModel(mModel);

}
