#include "LanguageManager.h"

LanguageManager::LanguageManager(
    QGuiApplication *app, QQmlApplicationEngine *engine)
    : QObject(nullptr),app(app),engine(engine)
{}

void LanguageManager::setLanguage(const QString &language)
{
    // Remove previous translator
    app->removeTranslator(&translator);

    QString fileName;

    if (language == "ar") {

        fileName =
            ":/qt/qml/Session4Task_ElectronicsShop/i18n/"
            "Session4_Task_ElectronicsShop_ar.qm";

    }
    else if (language == "fr") {

        fileName =
            ":/qt/qml/Session4Task_ElectronicsShop/i18n/"
            "Session4_Task_ElectronicsShop_fr.qm";

    }
    else if (language == "de") {

        fileName =
            ":/qt/qml/Session4Task_ElectronicsShop/i18n/"
            "Session4_Task_ElectronicsShop_de.qm";

    }
    else {

        // English
        engine->retranslate();

        emit languageChanged();

        qDebug() << "Language changed to English";

        return;
    }

    if (translator.load(fileName)) {

        app->installTranslator(&translator);

        // Refresh all qsTr() strings in QML
        engine->retranslate();

        qDebug() << "Language changed to:" << language;

        emit languageChanged();

    }
    else {

        qDebug()
        << "Failed to load translation:"
        << fileName;
    }
}
