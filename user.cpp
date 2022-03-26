#include "user.h"

User::User()
{

}


User::User(QString email, QString password)
{
    this->email = email;
    this->password = password;
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
