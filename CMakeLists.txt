cmake_minimum_required(VERSION 3.16)
project(ShotAssetManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
find_package(PXR REQUIRED)

add_executable(ShotAssetManager
    src/main.cpp
    src/USDManager.h
    src/USDManager.cpp
    ui/qml.qrc
)

add_library(USDManager STATIC USDManager.cpp USDManager.h)

target_include_directories(USDManager PRIVATE ${PXR_INCLUDE_DIRS})
target_link_libraries(USDManager PRIVATE ${PXR_LIBRARIES} Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)

target_include_directories(ShotAssetManager PRIVATE ${PXR_INCLUDE_DIRS})
target_link_libraries(ShotAssetManager PRIVATE USDManager Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)

qt_add_resources(ShotAssetManager "resources"
    PREFIX "/"
    FILES main.qml
)

install(TARGETS ShotAssetManager RUNTIME DESTINATION bin)