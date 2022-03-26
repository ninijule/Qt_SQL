#ifndef DB_CONNEXION_H
#define DB_CONNEXION_H
#include <QtSql>
#include <QSqlDatabase>
#include "qdebug.h"
#include "QMessageBox"
#include "QSqlQuery"
#include "user.h"
#include "string.h"

class db_connexion
{
public:
    static db_connexion& ReturnSelf();
    bool Connexion();
    bool CheckLogin(QString email, QString password);
    bool CreateUser(User user);


private:

    db_connexion();
    QSqlDatabase db;
    QString hostname = "192.168.1.230";
    QString port = "3306";
    QString username = "julian";
    QString password = "";
    QString databaseName = "test";
};



#endif // DB_CONNEXION_H

