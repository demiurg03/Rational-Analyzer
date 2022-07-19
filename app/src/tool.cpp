#include "tool.hpp"

QString readAllFromFile(const QString &fileName) {
  QFile file(fileName);

  file.open(QFile::ReadOnly);

  return file.readAll();
}
