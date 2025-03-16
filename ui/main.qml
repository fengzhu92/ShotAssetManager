import QtQuick 6.5
import QtQuick.Controls 6.5

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Shot & Asset Manager"

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: fileInput
            placeholderText: "Enter USD file path"
        }

        Button {
            text: "Load USD"
            onClicked: usdManager.loadUSD(fileInput.text)
        }

        ListView {
            id: assetListView
            width: 600
            height: 300
            model: usdManager.listAssets()
            delegate: Text {
                text: modelData
            }
        }

        Button {
            text: "Get Details"
            onClicked: {
                if (assetListView.currentIndex >= 0) {
                    let asset = assetListView.model[assetListView.currentIndex]
                    console.log(usdManager.getAssetDetails(asset))
                }
            }
        }
    }
}
