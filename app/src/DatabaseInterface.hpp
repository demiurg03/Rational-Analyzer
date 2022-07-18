#pragma once

#include "Database.hpp"
#include <QObject>

class DatabaseInterface : public QObject {
  Q_OBJECT
public:
  explicit DatabaseInterface(Database *db);

  std::optional<Product> getProductById(const int id);

  QVector<Product>
  getProductByPredicate(std::function<bool(const Product &)> fn,
                        bool stopFirst = false);

  void appendNewProduct(const Product &product);

private:
  Database *_db;
};
