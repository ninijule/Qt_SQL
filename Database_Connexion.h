#ifndef DATABASE_CONNEXION_H
#define DATABASE_CONNEXION_H

#include <QtSql>
#include <QSqlDatabase>
#include "qdebug.h"
#include "QMessageBox"
#include "QSqlQuery"

class DatabaseConnexion{

private:
    QSqlDatabase db;
    QString hostname = "192.168.1.230";
    QString port = "3306";
    QString username = "julian";
    QString password = "";
    QString databaseName = "test";

public:
    bool database_connexion(){
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

    QString CheckLogin(QString $email, QString $password){
        QSqlQuery query;
        query.prepare("SELECT * FROM users WHERE email = :email and password = :password");
        query.bindValue(":email",$email);
        query.bindValue(":password", $password);
        query.exec();


        while (query.next()) {
                 QString result = query.value(0).toString();
                 qDebug() << result;
             }
        return "";

    }
};






#endif // DATABASE_CONNEXION_H
