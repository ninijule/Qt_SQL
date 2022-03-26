#ifndef USER_H
#define USER_H
#include "QString"

class User
{
public:
    User();
    User(QString email, QString password);
    ~User();
    QString getEmail();
    QString getPassword();

private:
    QString email;
    QString password;
};

#endif // USER_H
