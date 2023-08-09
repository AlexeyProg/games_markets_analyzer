#include "connector.h"

Connector::Connector(QObject *parent)
    : QObject{parent}
{

}

void Connector::runScript(QProcess *pr, QString request)
{
    QString scriptPath =  "/Users/sokol/Desktop/qt_projects/shop_market/python_src/main_req.py";
    QString venv = "/Users/sokol/Desktop/qt_projects/shop_market/venv/bin/python3";
    QStringList arguments;

    arguments << request;


    pr->start(venv, QStringList() << scriptPath << arguments);

    if (pr->waitForStarted() && pr->waitForFinished()) {
        QByteArray output = pr->readAllStandardOutput();
        qDebug() << "Python output:" << output;
    } else {
        qDebug() << "Failed to start or finish Python process!";
        qDebug() << "Error:" << pr->errorString();
    }
    readjson();

}

void Connector::readjson()
{
    QString filePath = "/Users/sokol/Desktop/qt_projects/shop_market/data.json"; // Укажите полный путь к JSON файлу

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file!";
        return ;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON:" << parseError.errorString();
        return ;
    }

    if (jsonDoc.isObject()) {
        QJsonObject jsonObj = jsonDoc.object();
        // Теперь вы можете получить данные из объекта jsonObj и вывести их
        qDebug() << "Value of 'key':" << jsonObj["SteamBuy"].toString();
//        qDebug() << "Value of 'key':" << jsonObj["zakazaka"].toString();
//        qDebug() << "Value of 'key':" << jsonObj["SteamPay"].toString();
    }
}
