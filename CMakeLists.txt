cmake_minimum_required(VERSION 4.3)
project(StudyGerman)


add_executable(StudyGerman main.c)

configure_file(
        ${CMAKE_SOURCE_DIR}/data.idk
        ${CMAKE_BINARY_DIR}/data.idk
        COPYONLY
)