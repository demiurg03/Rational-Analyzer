#include "Backend.h"

BackEnd::BackEnd() : QObject(nullptr) {

  _database = new Database;

  _database->open();

  _databaseInterface = new DatabaseInterface(_database);

  connect(_databaseInterface, &DatabaseInterface::updateDatabase, this,
          &BackEnd::onUpdateDatabase);
}

BackEnd::~BackEnd() {
  delete _databaseInterface;
  delete _database;
}

void BackEnd::addProduct(const QString name, const int calories) {
  Product product;
  product.m_calories = calories;
  product.m_name = name;
  _databaseInterface->appendNewProduct(product);
}

QVariantList BackEnd::getAllProduct() {

  auto productList =
      _databaseInterface->getProductByPredicate([](auto &) { return true; });

  return convertToVariantList(productList.begin(), productList.end());
}

void BackEnd::removeProduct(const int id) {
  _databaseInterface->removeProduct(id);
}

void BackEnd::onUpdateDatabase() { emit updateDatabase(); }
