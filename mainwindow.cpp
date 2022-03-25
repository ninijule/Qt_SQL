#include "mainwindow.h"
#include "Database_Connexion.h"
#include "Utils.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "QPixmap"
#include "signup.h"


Utils util;
DatabaseConnexion conn;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conn.database_connexion();
    QPixmap LogoThales("C:/Users/Julian/Documents/Qt_SQL/logo.jpg");
    ui->LogoThales->setPixmap(LogoThales.scaled(300,150, Qt::KeepAspectRatio));
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
    bool userLogged = false;

    if(!emailInput.isEmpty() && !emailInput.isNull()){

        if(util.is_email_valid(emailInput.toStdString())){
            qDebug("Adresse mail valide");

            if(!passwordInput.isEmpty() && !passwordInput.isNull()){
                userLogged = conn.CheckLogin(emailInput, passwordInput);
                if(userLogged){

                }else{
                    util.sendMessageBox("Erreur mauvaise combinaison Email / Mot de passe", "Aucun utilisateur trouvé avec ces informations");
                    ui->passwordLineEdit->setText("");
                }
            }
            else{
                util.sendMessageBox("Champ mot de passe incorrecte", "Veuillez renseigner le mot de passe");
            }

        }else{
            util.sendMessageBox("Champs invalide Email", "Veuillez vérifier que l'adresse mail est valide.");
            return;
        }

    }else{
        util.sendMessageBox("Champs vide Email", "Veuillez vérifier que l'adresse mail n'est pas vide.");
        return;
    }



}


void MainWindow::on_RegisterButton_clicked()
{

    MainWindow::setEnabled(false);
    signup = new SignUp(this);
    signup->show();

}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{


}

