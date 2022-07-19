#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Backend.h"

void loadTranslation() {

  static QTranslator translator;

  if (translator.load(QLocale(), QLatin1String("rationalAnalyzer"),
                      QLatin1String("_"), QLatin1String(":/i18n"))) {
    QGuiApplication::installTranslator(&translator);

  } else {
    qDebug() << "error load translator";
  }
}

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);

  loadTranslation();

  QQmlApplicationEngine engine;

  QScopedPointer<BackEnd> backend(new BackEnd());

  engine.rootContext()->setContextProperty("Backend", backend.data());

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
