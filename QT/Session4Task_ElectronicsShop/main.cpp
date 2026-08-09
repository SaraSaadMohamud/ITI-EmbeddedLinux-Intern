#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "LanguageManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
   LanguageManager languageManager(&app,&engine);

   engine.rootContext()->setContextProperty(
        "languageManager",
        &languageManager
        );

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("Session4Task_ElectronicsShop", "Main");

    return QGuiApplication::exec();
}
