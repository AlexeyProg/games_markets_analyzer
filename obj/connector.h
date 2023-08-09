#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QProcess>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = nullptr);
    //QProcess *pr;
    void readjson();
    void runScript(QProcess *pr,QString request);
signals:

};

#endif // CONNECTOR_H
