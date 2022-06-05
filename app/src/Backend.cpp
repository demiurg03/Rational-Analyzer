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




    cacheDatabase();



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

    if (productMap.contains(id)){
        qWarning()<< tr("error get product") << id;
        qApp->exit();
    }


    return productMap.value( id );
}

void BackEnd::m_createDB(){

    QSqlQuery query( m_dbase );

    if ( !query.exec( R"( CREATE TABLE "Product" ("ID"	INTEGER NOT NULL UNIQUE, "Name"	TEXT, "Calories" INTEGER, PRIMARY KEY("ID" AUTOINCREMENT));)" ) ) {

        qCritical() << tr("db error create Product") << query.lastError();
        qApp->exit();

    }

    if ( !query.exec( R"( CREATE TABLE "Day" ( "ID" INTEGER NOT NULL, "Date"	TEXT, "ProductListId"	INTEGER, PRIMARY KEY("ID")); )" ) ) {


        qCritical() << tr("db error create Day") << query.lastError();
        qApp->exit();

    }

    if ( !query.exec( R"( CREATE TABLE "ProductList" ("ID"	INTEGER NOT NULL, "ListID"	INTEGER NOT NULL, "ProductID"	INTEGER NOT NULL,"Count"	INTEGER NOT NULL DEFAULT 1); )" ) ) {


        qCritical() << tr("db error create ProductList") << query.lastError();
        qApp->exit();

    }



}

void BackEnd::cacheDatabase()
{

    productMap.clear();

     QSqlQuery query( m_dbase );

    const auto result = query.exec("SELECT * FROM Product;");

    if( !result ){
        qCritical() << query.lastError();
        qApp->exit();
    }


     while ( query.next() ) {
        Product product;

        product.m_name = query.value("Name").toString();;
        product.m_id = query.value("ID").toInt();
        product.m_calories = query.value("Calories").toInt();


        productMap.insert(product.m_id, product);
     }



//     for(const auto &it : productMap){
//         qDebug() << it.m_id << it.m_name << it.m_calories;
//     }



}



