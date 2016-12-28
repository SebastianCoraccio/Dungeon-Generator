cmake_minimum_required(VERSION 3.6)
project(dgnGen)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cc src/dungeon.h src/room_types/room.h src/dungeon.cc src/room_types/start_room.cc src/room_types/hallway.h src/room_types/hallway.cc src/room_types/junction.cc src/room_types/junction.h src/config.h src/room_types/boss_room.cc src/room_types/boss_room.h src/dungeon_drawer.cc src/dungeon_drawer.h)
add_executable(dgnGen ${SOURCE_FILES})