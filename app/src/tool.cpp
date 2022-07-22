#include "tool.hpp"

QString readAllFromFile(const QString &fileName) {
  QFile file(fileName);

  const auto fileIsOpen = file.open(QFile::ReadOnly);

  if (!fileIsOpen) {
    qCritical() << "erro open file: " << fileName << file.error();
    throw;
  }

  return file.readAll();
}

QStringList readAllLineFromFile(const QString &fileName) {
  QFile file(fileName);

  const auto fileIsOpen = file.open(QFile::ReadOnly);

  if (!fileIsOpen) {
    qCritical() << "erro open file: " << fileName << file.error();
    throw;
  }

  QStringList list;
  QTextStream stream(&file);
  while (!stream.atEnd()) {
    auto line = stream.readLine();

    if (line.isEmpty()) {
      continue;
    }

    list << line;
  }

  return list;
}
