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

## Building the Project
### Using CMake Presets (Recommended)
```sh
cmake --preset=default
cmake --build --preset=default
