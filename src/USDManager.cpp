#include "USDManager.h"
#include <pxr/usd/usdGeom/imageable.h>
#include <QDebug>

USDManager::USDManager(QObject *parent) : QObject(parent) {}

bool USDManager::loadUSD(const QString &filepath)
{
    stage = UsdStage::Open(filepath.toStdString());
    return static_cast<bool>(stage);
}

QStringList USDManager::listAssets()
{
    QStringList assetList;
    if (!stage)
        return assetList;

    for (const auto &prim : stage->Traverse()) {
        assetList.append(QString::fromStdString(prim.GetPath().GetString()));
    }
    return assetList;
}

QString USDManager::getAssetDetails(const QString &assetPath)
{
    if (!stage)
        return "Stage not loaded";
    
    UsdPrim prim = stage->GetPrimAtPath(SdfPath(assetPath.toStdString()));
    if (!prim)
        return "Asset not found";
    
    return QString("Asset: %1\nType: %2")
        .arg(assetPath)
        .arg(QString::fromStdString(prim.GetTypeName()));
}