#pragma once

#include <QDate>
#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <qqml.h>

#include "DatabaseInterface.hpp"

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

signals:

private:
  Database _database;
  DatabaseInterface *_databaseInterface;
};
