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


    void appendNewProduct(const Product &product){
        auto query = _db->createQuery();




        query.prepare(R"(INSERT INTO "Product"(Name, Calories) VALUES(:name,:calories);)");

        query.bindValue(":name", product.m_name);
        query.bindValue(":calories", product.m_calories);

        if(!query.exec()){
            qWarning()<< tr("error add product") << query.lastError();
        }
    }


private:
    Database *_db;
};

