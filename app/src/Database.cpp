#include "Database.hpp"

Database::Database() { qRegisterMetaType<Product>(); }

void Database::open(const QString &driver) {
  _db = QSqlDatabase::addDatabase(driver);

  _db.setDatabaseName("rationalAnalyzer.db");

  if (!_db.open()) {
    qCritical() << tr("db error open");
    throw;
  }

  if (_db.tables().empty()) {
    _createTable();
  }
}

QSqlQuery Database::createQuery() {
  QSqlQuery query(_db);

  return query;
}

void Database::_createTable() {
  QSqlQuery query(_db);

  const auto sql = readAllFromFile(":/createTable.sql");

  if (!query.exec(sql)) {

    qCritical() << tr("db error create Product") << query.lastError();
    throw;
  }
}

//###
QString readAllFromFile(const QString &fileName) {
  QFile file(fileName);

  file.open(QFile::ReadOnly);

  return file.readAll();
}
