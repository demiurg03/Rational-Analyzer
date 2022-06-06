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

#include "Product.hpp"

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

    Q_INVOKABLE
     QVariantList getProductForName(const QString &name);





   QVariantList getProductPredicateVariant(std::function<bool(const Product&)> fn);

signals:



private:

    QSqlDatabase m_dbase;
    QMap<std::size_t, Product> productMap;

    void m_createDB();

    void cacheDatabase();




};
