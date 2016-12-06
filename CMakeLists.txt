cmake_minimum_required(VERSION 3.6)
project(dgnGen)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cc src/dungeon.h src/room.h src/room.cc src/dungeon.cc)
add_executable(dgnGen ${SOURCE_FILES})