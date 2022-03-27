#include "mainwindow.h"
#include "Utils.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "QPixmap"
#include "signup.h"
#include "db_connexion.h"
#include "user.h"
#include "home.h"


Utils util;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap LogoThales("C:/Users/Julian/Documents/Qt_SQL/logo.jpg");
    ui->LogoThales->setPixmap(LogoThales.scaled(300,150, Qt::KeepAspectRatio));
    ui->LogoThales->setAlignment(Qt::AlignCenter);
    db_connexion::ReturnSelf().Connexion();



}

MainWindow::~MainWindow()
{
    delete ui;
}

db_connexion& db_connexion::ReturnSelf() {
    static db_connexion s_myClass;
    return s_myClass;
}


void MainWindow::on_LoginButton_clicked()
{
    QString emailInput = ui->emailLineEdit->text();
    QString passwordInput = ui->passwordLineEdit->text();
    bool userLogged = false;

    if(!emailInput.isEmpty() && !emailInput.isNull()){

        if(util.is_email_valid(emailInput.toStdString())){

            if(!passwordInput.isEmpty() && !passwordInput.isNull()){
                User user(emailInput, passwordInput);
                userLogged = db_connexion::ReturnSelf().CheckLogin(user.getEmail(), user.getPassword());
                if(userLogged){
                    qDebug("connected");
                    this->close();
                    home = new Home(this);
                    home->show();
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
    connect(signup, SIGNAL(enableMainWindow()), this, SLOT(enableMainWindow()));

}

void MainWindow::enableMainWindow()
{
     this->setEnabled(true);
}



void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{


}

