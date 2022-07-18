#pragma once
#include <QSqlDatabase>
#include <QFile>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

QString readAllFromFile(const QString &fileName);

class Database : public QObject{
    Q_OBJECT


public:

    Database();


    void open(const QString &driver = "QSQLITE");


private:
    QSqlDatabase _db;


    void _createTable();


};
