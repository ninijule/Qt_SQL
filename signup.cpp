#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    QPixmap LogoThales2("C:/Users/Julian/Documents/Qt_SQL/logo.jpg");
    ui->LogoThalesRegister->setPixmap(LogoThales2.scaled(300,150, Qt::KeepAspectRatio));
    ui->LogoThalesRegister->setAlignment(Qt::AlignCenter);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_registerButton_clicked()
{

}

