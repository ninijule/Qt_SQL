#include "user.h"
#include "QCryptographicHash"

User::User()
{

}


User::User(QString email, QString password)
{
    this->email = email;
    this->password = QString(QCryptographicHash::hash((password.toUtf8()),QCryptographicHash::Sha256).toHex());;
}

QString User::getEmail(){
return this->email;
}

QString User::getPassword(){
return this->password;
}

User::~User()
{

}
