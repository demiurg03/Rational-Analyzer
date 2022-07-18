#include "Backend.h"





BackEnd::BackEnd(QObject *parent)
    : QObject(parent)
{

    qRegisterMetaType<Product>();

    _database.open();

}

BackEnd::~BackEnd(){

}





