cmake_minimum_required(VERSION 3.27)
project(mqtt_project)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(helloworld PRIVATE Qt6::Core)
