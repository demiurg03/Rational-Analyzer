#include "Backend.h"

BackEnd::BackEnd(QObject *parent) : QObject(parent) {

  _database.open();

  _databaseInterface = new DatabaseInterface(&_database);
}

BackEnd::~BackEnd() {}

void BackEnd::addProduct(const QString name, const int calories) {
  Product product;
  product.m_calories = calories;
  product.m_name = name;
  _databaseInterface->appendNewProduct(product);
}
