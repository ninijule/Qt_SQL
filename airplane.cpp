#include "airplane.h"

Airplane::Airplane()
{

}


Airplane::Airplane(QString name, int seats, QString reactors)
{
this->name = name;
this->seats = seats;
this->reactors = reactors;
}

QString Airplane::getName(){
return this->name;
}

int Airplane::getSeat(){
return this->seats;
}

QString Airplane::getReactor(){
return this->name;
}

Airplane::~Airplane()
{

}
