# Shot Asset Manager

## Overview
Shot Asset Manager is a Qt-based desktop tool for managing animation shot data and assets, leveraging OpenUSD for asset structuring. It provides an API for efficient data access and integrates with Qt's QML framework for a responsive user interface.

## Features
- Load and parse OpenUSD (.usd, .usda, .usdc) files.
- Inspect and list animation shots and assets.
- Retrieve asset metadata and structure.
- Built with **Qt6.5+** and **OpenUSD (PXR)**.

## Prerequisites
Ensure the following dependencies are installed before building the project:
- **Qt 6.5+** (Core, Gui, QML, Quick)
- **OpenUSD (PXR)**
- **CMake 3.16+**
- **C++17 or later**
- **Ninja (optional, recommended for faster builds)**

## Code structure
```
ShotAssetManager/
│── CMakeLists.txt          # CMake build configuration
│── CMakePresets.json       # CMake presets for easy builds
│── README.md               # Documentation
│── qml.qrc                 # Qt resource file (includes main.qml)
│
├── proto/
│   ├── asset_manager.proto  # gRPC service definition
│
├── src/
│   ├── main.cpp             # Entry point of the application
│   ├── USDManager.h/.cpp    # Manages OpenUSD operations and connects to gRPC
│   ├── AssetManagerServer.cpp  # Implements the gRPC server
│   ├── AssetManagerClient.cpp  # Implements the gRPC client
│
├── qml/
│   ├── main.qml             # QML-based user interface

## Building the Project
### Using CMake Presets (Recommended)
```sh
cmake --preset=default
cmake --build --preset=default
