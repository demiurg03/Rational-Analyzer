#pragma once

#include <QObject>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QSqlError>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>


#include <qqml.h>

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



class BackEnd : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    QML_ELEMENT

public:
    explicit BackEnd(QObject *parent = nullptr);

    ~BackEnd();

    Q_INVOKABLE
    void addProduct(QString name, const int calories);

    Q_INVOKABLE
    Product getProduct(const int id);


signals:



private:

    QSqlDatabase m_dbase;

    void m_createDB();

};
