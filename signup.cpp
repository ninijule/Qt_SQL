#include "signup.h"
#include "ui_signup.h"
#include "Utils.h"
#include "user.h"
#include "db_connexion.h"
#include "mainwindow.h"

Utils utils;

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
    QString email = ui->emailRegisterLineEdit->text();
    QString password = ui->passwordRegisterLineEdit->text();
    QString passwordConfirmation = ui->passwordConfirmationRegisterLineEdit->text();
    if(utils.is_email_valid(email.toStdString())){
        qDebug("Email valide");
        if(password == passwordConfirmation){
            User user(email, password);
            bool createdUser = db_connexion::ReturnSelf().CreateUser(user);
            if(createdUser){
                this->close();
                enableFrameMainWindow();
                utils.sendMessageBox("Utilisateur crée avec succès!", "");
            }
        }
        else{
            utils.sendMessageBox("Champs mot de passe invalide", "Les deux mot de passes ne correspondent pas.");
            return;
        }
    }
    else{
        utils.sendMessageBox("Champs invalide Email", "Veuillez vérifier que l'adresse mail est valide.");
        return;
    }

}

void SignUp::enableFrameMainWindow()
{
      emit enableMainWindow();
}

void SignUp::closeEvent(QCloseEvent *event)
{
    qDebug("Closed Event");
    enableFrameMainWindow();
}

