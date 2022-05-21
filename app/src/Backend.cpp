#include "Backend.h"


BackEnd::BackEnd(QObject *parent)
    : QObject(parent)
{


    m_dbase = QSqlDatabase::addDatabase("QSQLITE");


    m_dbase.setDatabaseName("rationalAnalyzer.sqlite");
    if (!m_dbase.open()) {
        qCritical() << tr("db error open");
        qApp->exit();
    }

    if (m_dbase.tables().empty()){
        m_createDB();
    }


    qRegisterMetaType<Product>();


}

BackEnd::~BackEnd(){

}



void BackEnd::addProduct(QString name, const int calories){
    QSqlQuery query( m_dbase );

    qDebug() << tr("add product") << name << calories;


    query.prepare(R"(INSERT INTO "Product"(Name, Calories) VALUES(:name,:calories);)");

    query.bindValue(":name", name);
    query.bindValue(":calories", calories);

    if(!query.exec()){
        qWarning()<< tr("error add product") << name << calories << query.lastError();
    }




}

Product BackEnd::getProduct(const int id){


    QSqlQuery query( m_dbase );



    query.prepare(R"(  SELECT * FROM "Product" WHERE ID = :id  )");
    query.bindValue(":id",id);


    Product product;
    if ( query.exec( ) ) {

        query.next();

        product.m_name = query.value("Name").toString();
        product.m_id = query.value("ID").toInt();
        product.m_calories = query.value("Calories").toInt();


    }else{
        qWarning()<< tr("error get product") << id << query.lastError();

    }

    qDebug() << "found product" << product.m_id << product.m_name << product.m_calories;

    return product;
}

void BackEnd::m_createDB(){

    QSqlQuery query( m_dbase );

    if ( !query.exec( R"( CREATE TABLE "Product" ("ID"	INTEGER NOT NULL UNIQUE, "Name"	TEXT, "Calories" INTEGER, PRIMARY KEY("ID" AUTOINCREMENT));)" ) ) {

        qCritical() << tr("db error create Product");
        qApp->exit();

    }

    if ( !query.exec( R"( CREATE TABLE "Day" ( "ID" INTEGER NOT NULL, "Date"	TEXT, "ProductListId"	INTEGER, PRIMARY KEY("ID")); )" ) ) {


        qCritical() << tr("db error create Day");
        qApp->exit();

    }

    if ( !query.exec( R"( CREATE TABLE "ProductList" ("ID"	INTEGER NOT NULL, "ListID"	INTEGER NOT NULL, "ProductID"	INTEGER NOT NULL,"Count"	INTEGER NOT NULL DEFAULT 1); )" ) ) {


        qCritical() << tr("db error create ProductList");
        qApp->exit();

    }



}



