#pragma once
#include <QSqlDatabase>
#include <QFile>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

QString readAllFromFile(const QString &fileName);


struct Product{
    Q_GADGET




    Q_PROPERTY(int id MEMBER m_id)
    Q_PROPERTY(int calories MEMBER m_calories)
    Q_PROPERTY(QString name MEMBER m_name)

public:



    int m_id;
    int m_calories;

    QString m_name;

};

Q_DECLARE_METATYPE(Product);





class Database : public QObject{
    Q_OBJECT


public:

    Database();


    void open(const QString &driver = "QSQLITE");


    QSqlQuery createQuery();
private:
    QSqlDatabase _db;


    void _createTable();


};
