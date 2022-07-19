#pragma once

#include <QFile>
#include <QVariant>


template <typename T> QVariantList convertToVariantList(T begin, T end) {

  QVariantList result;

  std::for_each(begin, end, [&result](auto &elm) {
    result.append(QVariant::fromValue(elm));
  });

  return result;
}


QString readAllFromFile(const QString &fileName);
