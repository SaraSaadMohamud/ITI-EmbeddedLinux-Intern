#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    /* Manage QT Application, Generte Event loop for you app*/
    QGuiApplication app(argc, argv);
    /* Creat an object from QML Engin which is the QML runtime envronment*/
    QQmlApplicationEngine engine;

    /* Lamda Function use to handle the exception[object creation fialure] if there are any error in your object kill the aml event loop*/
    QObject::connect(
        &engine, /* Signal Sender */

        &QQmlApplicationEngine::objectCreationFailed, /* Signal*/

        &app, /*Signal Reciever */

        []() { QCoreApplication::exit(-1); }, /* Kill Entery Point of the GUI App: Event Loop*/
        Qt::QueuedConnection);

    /* Loading QML Coding File to engin object*/
    engine.loadFromModule("Session1Task_HelloWorldApp", "Main");

    /* Starting Event Loop*/
    return QGuiApplication::exec();
}
