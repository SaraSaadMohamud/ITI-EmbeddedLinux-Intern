#include "LanguageManager.h"

#include <QCoreApplication>
#include <QDebug>

LanguageManager::LanguageManager(QObject *parent)
    : QObject(parent)
{
}

void LanguageManager::setLanguage(const QString &language)
{
    qDebug() << "Changing language to:" << language;

    // Remove the previous translation
    QCoreApplication::removeTranslator(&translator);

    // Arabic
    if (language == "Arabic")
    {
        if (translator.load(
                ":/qt/qml/Session3_Task/i18n/Session3_Task_ar.qm"))
        {
            qDebug() << "Arabic translation loaded successfully";

            QCoreApplication::installTranslator(&translator);
        }
        else
        {
            qDebug() << "ERROR: Could not load Arabic translation";
            return;
        }
    }

    // French
    else if (language == "French")
    {
        if (translator.load(
                ":/qt/qml/Session3_Task/i18n/Session3_Task_fr.qm"))
        {
            qDebug() << "French translation loaded successfully";

            QCoreApplication::installTranslator(&translator);
        }
        else
        {
            qDebug() << "ERROR: Could not load French translation";
            return;
        }
    }

    // English
    else if (language == "English")
    {
        qDebug() << "English selected";
    }

    // Unknown language
    else
    {
        qDebug() << "Unknown language:" << language;
        return;
    }

    // Notify QML pages
    emit languageChanged();
}