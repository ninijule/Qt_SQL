#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "QString"


class Airplane
{
public:
    Airplane();
    Airplane(QString name, int seats, QString reactors);
    ~Airplane();
    QString getName();
    int getSeat();
    QString getReactor();

private:
QString name;
int seats;
QString reactors;

};


#endif // AIRPLANE_H
