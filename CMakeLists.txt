cmake_minimum_required(VERSION 3.23)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

#file(GLOB RESOURCE_FILES sprites/*)
#foreach(RESOURCE_FILE ${RESOURCE_FILES})
#    set(RESOURCE_FILES ${RESOURCE_FILE})
#endforeach()

file(GLOB RESOURCE_FILES sprites/*)

# Iterate over each file and add it as a resource
foreach(RESOURCE_FILE ${RESOURCE_FILES})
    get_filename_component(FILE_NAME ${RESOURCE_FILE} NAME)
    configure_file(${RESOURCE_FILE} ${CMAKE_BINARY_DIR}/sprites/${FILE_NAME} COPYONLY)
endforeach()

add_executable(SpaceInvaders main.cpp src/Window.cpp headers/Window.h src/Game.cpp headers/Game.h src/Object.cpp headers/Object.h src/Sprite.cpp headers/Sprite.h src/Gun.cpp headers/Gun.h headers/Constants.h src/Time.cpp headers/Time.h src/Bullet.cpp headers/Bullet.h src/Invader.cpp headers/Invader.h src/InvaderController.cpp headers/InvaderController.h headers/Updatable.h src/Updatable.cpp)
target_link_libraries(SpaceInvaders sfml-graphics sfml-audio)
