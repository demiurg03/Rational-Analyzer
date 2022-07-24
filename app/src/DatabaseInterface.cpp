#include "DatabaseInterface.hpp"

DatabaseInterface::DatabaseInterface(Database *db)
    : QObject(nullptr), _db(db) {}

std::optional<Product> DatabaseInterface::getProductById(const int id) {

  auto result = getProductByPredicate(
      [id](const Product &product) { return product.m_id == id; }, true);

  if (result.empty()) {
    return std::nullopt;
  }

  return result.front();
}

QVector<Product> DatabaseInterface::getProductByPredicate(
    std::function<bool(const Product &)> fn, bool stopFirst) {
  auto query = _db->createQuery();

  const auto result = query.exec("SELECT * FROM Product;");

  if (!result) {
    qCritical() << query.lastError();
    throw;
  }

  QVector<Product> productList;

  while (query.next()) {
    Product product;

    product.m_name = query.value("Name").toString();
    product.m_id = query.value("ID").toInt();
    product.m_calories = query.value("Calories").toInt();

    if (fn(product)) {
      productList.append(product);

      if (stopFirst) {
        break;
      }
    }
  }

  return productList;
}

void DatabaseInterface::appendNewProduct(const Product &product) {
  auto query = _db->createQuery();

  query.prepare(
      R"(INSERT INTO Product(Name, Calories) VALUES(:name,:calories);)");

  query.bindValue(":name", product.m_name);
  query.bindValue(":calories", product.m_calories);

  if (!query.exec()) {
    qWarning() << tr("error add product") << query.lastError();
  }

  emit updateDatabase();
}

void DatabaseInterface::removeProduct(const int id) {

  auto query = _db->createQuery();

  query.prepare(R"(DELETE FROM Product WHERE ID=:id;)");

  query.bindValue(":id", id);

  if (!query.exec()) {
    qWarning() << tr("error add product") << query.lastError();
  }

  emit updateDatabase();
}

bool DatabaseInterface::existDay(QDate dayDate) {
  auto query = _db->createQuery();

  query.prepare(R"(SELECT * FROM Day WHERE date_day=:day;)");

  const auto stringData = dayDate.toString();

  query.bindValue(":day", stringData);

  if (!query.exec()) {
    qWarning() << tr("error exist day") << query.lastError();
  }

  return query.next();
}

void DatabaseInterface::addDay(QDate dayDate) {

  auto query = _db->createQuery();

  query.prepare(
      R"(INSERT INTO Day(ProductListId, date_day) VALUES(:name,:calories);)");

  const auto stringData = dayDate.toString();

  query.bindValue(":name", rand());
  query.bindValue(":calories", stringData);

  if (!query.exec()) {
    qWarning() << tr("error add product") << query.lastError();
  }
}

void DatabaseInterface::addProductToDay(const QDate dayDate, const int id){




}
