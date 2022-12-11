cmake_minimum_required(VERSION 3.23)
project(Battleship)

set(CMAKE_CXX_STANDARD 23)

add_executable(Battleship UserInterface.cpp Singleplayer.cpp Battleship.h Multiplayer.cpp UniversalFunctions.cpp GameLogs.cpp)
