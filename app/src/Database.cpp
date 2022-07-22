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

  const auto sqlLines = readAllLineFromFile(":/createTable.sql");

  for(const auto &line : sqlLines){

      if (!query.exec(line)) {

        qCritical() <<  query.lastError();
        throw;
      }
  }


}

//###
