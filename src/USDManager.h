#ifndef USDMANAGER_H
#define USDMANAGER_H

#include <QObject>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <string>

using namespace pxr;

class USDManager : public QObject
{
    Q_OBJECT
public:
    explicit USDManager(QObject *parent = nullptr);
    Q_INVOKABLE bool loadUSD(const QString &filepath);
    Q_INVOKABLE QStringList listAssets();
    Q_INVOKABLE QString getAssetDetails(const QString &assetPath);

private:
    UsdStageRefPtr stage;
};

#endif // USDMANAGER_H