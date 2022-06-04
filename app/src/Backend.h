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

Q_DECLARE_METATYPE(Product);

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
     QVariantList getProductForName(const QString &name){



        const auto result =  getProductPr([&name](const Product &ptr)->bool{
            return ptr.m_name.contains(name);
        });


        QVariantList list;


        for(const auto &it : result){
            QVariant tmp = QVariant::fromValue(it);

            list.append(tmp);
        }



        return list;
    }





    QList<Product> getProductPr(std::function<bool(const Product&)> fn){

        QList<Product> list;

        for(const auto &it : productMap){
            if( fn(it)){
                list.append(it);
            }
        }

        return list;
    }

signals:



private:

    QSqlDatabase m_dbase;
    QMap<std::size_t, Product> productMap;

    void m_createDB();

    void cacheDatabase();




};
