#include "mainwindow.h"
#include "Database_Connexion.h"
#include "Utils.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "QPixmap"
#include <typeinfo>



Utils util;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DatabaseConnexion conn;
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
    QString passwordInput = ui->passwordLineEdit->text();

    if(!emailInput.isEmpty() && !emailInput.isNull()){

        if(util.is_email_valid(emailInput.toStdString())){
            qDebug("Adresse mail valide");

            if(!passwordInput.isEmpty() && !passwordInput.isNull()){
                //conn.check_login(emailInput, passwordInput);
            }
            else{
                util.sendMessageBox(parentWidget(),"Champ mot de passe incorrecte", "Veuillez renseigner le mot de passe");
            }

        }else{
            util.sendMessageBox(parentWidget(), "Champs invalide Email", "Veuillez vérifier que l'adresse mail est valide.");
            return;
        }

    }else{
        util.sendMessageBox(parentWidget(), "Champs vide Email", "Veuillez vérifier que l'adresse mail n'est pas vide.");
        return;
    }



}


void MainWindow::on_RegisterButton_clicked()
{

}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{


}

