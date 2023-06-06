cmake_minimum_required(VERSION 3.23)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(SpaceInvaders main.cpp src/Window.cpp headers/Window.h src/Game.cpp headers/Game.h)
target_link_libraries(SpaceInvaders sfml-graphics sfml-audio)
