#include "Database_Connexion.h"
#include <QtSql>
#include <QSqlDatabase>
#include "qdebug.h"
#include "QMessageBox"
#include "QSqlQuery"

    bool DatabaseConnexion::database_connexion(){
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

    bool CheckLogin(QString $email, QString $password){
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

