#ifndef DATABASE_CONNEXION_H
#define DATABASE_CONNEXION_H

#include <QtSql>
#include <QSqlDatabase>
#include "qdebug.h"
#include "QMessageBox"
#include "QSqlQuery"
#include "user.h"

class DatabaseConnexion{

public:
    Database_connexion();
    bool Connexion();
    bool CheckLogin(QString email, QString password);
    bool CreateUser(User user);
    ~Database_connexion();

private:
    QSqlDatabase db;
    QString hostname = "192.168.1.230";
    QString port = "3306";
    QString username = "julian";
    QString password = "";
    QString databaseName = "test";
};


#endif // DATABASE_CONNEXION_H
