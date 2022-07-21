#include "Backend.h"

BackEnd::BackEnd() : QObject(nullptr) {

  _database.reset(new Database);

  _database->open();

  _databaseInterface.reset(new DatabaseInterface(_database.get()));

  connect(_databaseInterface.get(), &DatabaseInterface::updateDatabase, this,
          &BackEnd::onUpdateDatabase);
}

BackEnd::~BackEnd() {
  _databaseInterface.reset();
  _database.reset();
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
