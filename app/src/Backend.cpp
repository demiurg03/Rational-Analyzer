#include "Backend.h"




BackEnd::BackEnd(QObject *parent)
    : QObject(parent)
{



    _database.open();

    _databaseInterface = new DatabaseInterface(&_database);





}

BackEnd::~BackEnd(){

}





