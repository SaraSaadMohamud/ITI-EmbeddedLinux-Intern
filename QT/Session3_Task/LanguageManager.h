#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QObject>
#include <QTranslator>

class LanguageManager : public QObject
{
    Q_OBJECT

public:
    explicit LanguageManager(QObject *parent = nullptr);

    Q_INVOKABLE void setLanguage(const QString &language);

signals:
    void languageChanged();

private:
    QTranslator translator;
};

#endif // LANGUAGEMANAGER_H

