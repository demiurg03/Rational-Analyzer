#pragma once

#include <QObject>
#include <QDate>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <qqml.h>

#include "Database.hpp"

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

class BackEnd : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    QML_ELEMENT

public:
    explicit BackEnd(QObject *parent = nullptr);

    ~BackEnd();





signals:



private:


Database _database;



};
