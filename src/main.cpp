#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "usdmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    USDManager usdManager;
    
    engine.rootContext()->setContextProperty("usdManager", &usdManager);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}