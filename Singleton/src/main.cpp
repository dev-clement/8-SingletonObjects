#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mysingleton.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MySingleton *singleton = new MySingleton(&app);
    qmlRegisterSingletonInstance<MySingleton>("com.franco.custom", 0, 1, "MySingleton", singleton);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Singleton", "Main");

    return app.exec();
}
