cmake_minimum_required(VERSION 4.3)
project(StudyGerman)

set(CMAKE_CXX_STANDARD 20)

add_executable(StudyGerman main.cpp)

configure_file(
        ${CMAKE_SOURCE_DIR}/data.json
        ${CMAKE_BINARY_DIR}/data.json
        COPYONLY
)