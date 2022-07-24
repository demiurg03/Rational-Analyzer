#pragma once

#include <QObject>
#include <QDate>

#include "Database.hpp"


class DatabaseInterface : public QObject {
  Q_OBJECT
public:
  explicit DatabaseInterface(Database *db);

  std::optional<Product> getProductById(const int id);

  QVector<Product>
  getProductByPredicate(std::function<bool(const Product &)> fn,
                        bool stopFirst = false);

  void appendNewProduct(const Product &product);

  void removeProduct(const int id);

  bool existDay(QDate dayDate);

  void addDay(QDate dayDate);

  void addProductToDay(const QDate dayDate, const int id);


signals:
  void updateDatabase();

private:
  Database *_db;
};
