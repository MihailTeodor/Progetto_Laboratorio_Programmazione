cmake_minimum_required(VERSION 3.3)
project(Progetto_Laboratorio_Programmazione)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_subdirectory(test)


set(SOURCE_FILES Subject.h Observer.h FileLoader.h FileLoader.cpp ProgressBar.h BitProgressBar.h)

add_executable(Progetto_Laboratorio_Programmazione main.cpp )

add_library(core ${SOURCE_FILES})




target_link_libraries (Progetto_Laboratorio_Programmazione core )




