#include "db_connexion.h"
#include "Utils.h"

Utils utilities;

db_connexion::db_connexion()
{

}


bool db_connexion::Connexion(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostname);
    db.setPassword(port);
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName(databaseName);
    if(db.open()){
        qDebug() << "Connected to database";
        return true;

    }else{
        qDebug() << "errors:" << db.lastError();
        return false;
    }
    return false;
}

bool db_connexion::CheckLogin(QString $email, QString $password){
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE email = :email and password = :password");
    query.bindValue(":email",$email);
    query.bindValue(":password", $password);
    query.exec();

    if (query.next()) {
             QString result = query.value(1).toString();
             qDebug() << result;
             return true;
         }
    return false;
}


bool db_connexion::CreateUser(User user){
    QString $email = user.getEmail();
    QString $password = user.getPassword();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE email = :email");
    query.bindValue(":email", $email);
    query.exec();

    if (query.next()) {
             qDebug("user already exist");
             utilities.sendMessageBox("Erreur cette adresse mail est déjà utilisée.", "Veuillez en sélectionner une autre.");
             return false;
         }else{

        QSqlQuery query;
        query.prepare("INSERT INTO users (email, password) VALUES (?,?) ");
        query.addBindValue($email);
        query.addBindValue($password);
        query.exec();
        return true;
    }

}

