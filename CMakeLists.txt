cmake_minimum_required(VERSION 3.27)

project(mqtt_project)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(submodule)

file(GLOB SOURCES *.cpp *.hpp)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets Gui)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(
        ${PROJECT_NAME} 
    PRIVATE 
        Qt6::Core
        Qt6::Mqtt
        Qt::Network
        Qt::Widgets
        Qt::Gui
)
