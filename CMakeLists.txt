cmake_minimum_required(VERSION 3.10)
project(StarfieldNavigator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(StarfieldNavigator
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Asteroid.cpp
    src/Resource.cpp
    src/Starfield.cpp
)

target_link_libraries(StarfieldNavigator sfml-graphics sfml-window sfml-system)