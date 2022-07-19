#pragma once

#include <QDate>
#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <qqml.h>

#include "DatabaseInterface.hpp"

template <typename T> QVariantList convertToVariantList(T begin, T end) {

  QVariantList result;

  std::for_each(begin, end, [&result](auto &elm) {
    result.append(QVariant::fromValue(elm));
  });

  return result;
}

class BackEnd : public QObject {
  Q_OBJECT
  // Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY
  // userNameChanged)
  QML_ELEMENT

public:
  explicit BackEnd(QObject *parent = nullptr);

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
