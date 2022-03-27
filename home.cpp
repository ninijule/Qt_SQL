#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap LogoThales("C:/Users/Julian/Documents/Qt_SQL/logo.jpg");
    ui->LogoThales->setPixmap(LogoThales.scaled(300,150, Qt::KeepAspectRatio));
    ui->LogoThales->setAlignment(Qt::AlignCenter);


}

Home::~Home()
{
    delete ui;
}
