#include "mainwindow.h"
#include "Database_Connexion.h"
#include "Utils.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "qdebug.h"
#include "QPixmap"

#include <iostream>
#include <string>
#include <regex>


DatabaseConnexion conn;
Utils util;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conn.database_connexion();
    QPixmap LogoThales("C:/Users/Julian/Documents/Qt_SQL/logo.jpg");
    int w = ui->LogoThales->width();
    int h = ui->LogoThales->height();
    ui->LogoThales->setPixmap(LogoThales.scaled(w,h, Qt::KeepAspectRatio));
    ui->LogoThales->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginButton_clicked()
{
    QString emailInput = ui->emailLineEdit->text();
    if(!emailInput.isEmpty() && !emailInput.isNull() && util.is_email_valid(emailInput.toStdString())){
        qDebug("Valid Address mail");
    }else{
        QMessageBox::warning(this, "Champs invalide", "Veuillez vérifier que votre adresse mail est valide.");
    }

}


void MainWindow::on_RegisterButton_clicked()
{

}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{


}

