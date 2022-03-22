#ifndef DATABASE_CONNEXION_H
#define DATABASE_CONNEXION_H

#include <QtSql>
#include <QSqlDatabase>
#include "qdebug.h"
#include "QMessageBox"
#include "QSqlQuery"

class DatabaseConnexion{

public:
    bool database_connexion();
    bool check_login(QString email, QString password);


private:
    QSqlDatabase db;
    QString hostname = "192.168.1.230";
    QString port = "3306";
    QString username = "julian";
    QString password = "";
    QString databaseName = "test";
};






#endif // DATABASE_CONNEXION_H
