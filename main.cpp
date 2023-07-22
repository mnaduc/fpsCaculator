#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include "fpscaculator.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //--------------
    FPSCaculator FPSCaculator;
    engine.rootContext()->setContextProperty("FPSCaculator", &FPSCaculator);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    //--------------
    QQuickWindow* window = qobject_cast<QQuickWindow*>( engine.rootObjects().at(0));
    QObject::connect(window, &QQuickWindow::beforeRendering, &FPSCaculator, &FPSCaculator::recalculate, Qt::DirectConnection);

    return app.exec();
}
