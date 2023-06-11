cmake_minimum_required(VERSION 3.10)
project(miniprojet)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets CONFIG REQUIRED)

include_directories(.)

add_executable(miniprojet
        src/main.cpp
        src/MainWindow.cpp
        src/MainWindow.h
        src/MyScene.cpp
        src/MyScene.h
        src/MyView.h
        src/Rejouer.h
        src/Rejouer.cpp
        src/Lancement.cpp
        src/test.cpp
        src/Utils.h)

target_link_libraries(miniprojet Qt6::Widgets)
