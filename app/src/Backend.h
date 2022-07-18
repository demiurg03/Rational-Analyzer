#pragma once

#include <QObject>
#include <QDate>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <qqml.h>

#include "DatabaseInterface.hpp"


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
DatabaseInterface *_databaseInterface;


};
