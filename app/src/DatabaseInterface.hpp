#pragma once

#include <QObject>
#include "Database.hpp"





class DatabaseInterface : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseInterface(Database *db);



    std::optional<Product> getProductById(const int id);


    QVector<Product> getProductByPredicate( std::function<bool(const Product&)> fn, bool stopFirst = false );


private:
    Database *_db;
};

