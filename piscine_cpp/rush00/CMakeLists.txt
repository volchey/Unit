cmake_minimum_required(VERSION 3.9)
project(rush00)

set(CMAKE_CXX_STANDARD 98)

add_executable(rush00
        main.cpp
        src/Game.hpp
        src/Game.cpp
        src/Entity.hpp
        src/Entity.cpp
        src/Player.hpp
        src/Player.cpp
        src/Asteroid.hpp
        src/Asteroid.cpp
        src/Field.cpp
        src/Field.hpp
        src/Rocket.cpp
        src/Rocket.hpp)