#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QObject>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

class LanguageManager : public QObject
{
    Q_OBJECT

public:
    explicit LanguageManager(QGuiApplication *app,
                             QQmlApplicationEngine *engine);

    Q_INVOKABLE void setLanguage(const QString &language);

signals:
    void languageChanged();

private:
    QGuiApplication *app;
    QQmlApplicationEngine *engine;
    QTranslator translator;
};

#endif
