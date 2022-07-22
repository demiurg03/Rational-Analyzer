#pragma once

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QVariant>

template <typename T> QVariantList convertToVariantList(T begin, T end) {

  QVariantList result;

  std::for_each(begin, end, [&result](auto &elm) {
    result.append(QVariant::fromValue(elm));
  });

  return result;
}

QString readAllFromFile(const QString &fileName);

QStringList readAllLineFromFile(const QString &fileName);
