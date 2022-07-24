#pragma once

#include <qqml.h>

#include "DatabaseInterface.hpp"


struct DayInfo {
    Q_GADGET

    Q_PROPERTY(int id MEMBER m_id)
    Q_PROPERTY(int calories MEMBER m_calories)
    Q_PROPERTY(QDate date MEMBER m_date)
    Q_PROPERTY(QVector<int> proid MEMBER m_proid)

public:
    int m_id;
    int m_calories;
    QVector<int>m_proid;

    QDate m_date;
};

Q_DECLARE_METATYPE(DayInfo);



class BackEnd : public QObject {
    Q_OBJECT
    // Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY
    // userNameChanged)
    QML_ELEMENT

public:
    explicit BackEnd();

    ~BackEnd();

    Q_INVOKABLE
    void addProduct(const QString name, const int calories);

    Q_INVOKABLE QVariantList getAllProduct();

    Q_INVOKABLE
    void removeProduct(const int id);

    Q_INVOKABLE
    DayInfo getDayInfo(){

        return {};
    }


    Q_INVOKABLE
    void addProductToDay(const int id){
        _databaseInterface->addProductToDay(QDate::currentDate(), id);

    }


private slots:
    void onUpdateDatabase();

signals:
    void updateDatabase();

private:
    QScopedPointer<Database> _database;
    QScopedPointer<DatabaseInterface> _databaseInterface;

    void installDay();

};
