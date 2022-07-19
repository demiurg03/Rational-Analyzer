#pragma once

#include <qqml.h>

#include "DatabaseInterface.hpp"


class BackEnd : public QObject {
  Q_OBJECT
  // Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY
  // userNameChanged)
  QML_ELEMENT

public:
  explicit BackEnd();

  ~BackEnd();

  Q_INVOKABLE
  void addProduct(const QString name, const int calories);

  Q_INVOKABLE QVariantList getAllProduct();



private slots:
  void onUpdateDatabase();

signals:
  void updateDatabase();

private:
  Database _database;
  DatabaseInterface *_databaseInterface;
};
