//
// Created by Sebastian Coraccio on 12/4/2016.
//
// A Room Class created for building dungeons
//
// TODO: Make adjacent rooms and chances public or think of a good reason
// TODO: to keep getters and setters

#ifndef DGNGEN_ROOM_H
#define DGNGEN_ROOM_H

#include <iostream>

class Room {

  public:
  // Create a new room with default values
  Room();

  // Creates a room with defined adjacent room generation chances.
  Room(double north_chance, double east_chance, double west_chance, double south_chance);

  // x location in a dungeon grid
  int x_location_ = -1;

  // y location in a dungeon grid
  int y_location_ = -1;

  enum RoomType {
    Regular,
    Start,
    Exit,
    Boss,
    Treasure,
    Empty
  };

  // All rooms default to regular, and change during dungeon generation
  enum RoomType room_type_ = Empty;

  // Rooms that connect to this room. Will be null if no room connects.
  Room *northern_room_ = nullptr;
  Room *eastern_room_ = nullptr;
  Room *western_room_ = nullptr;
  Room *southern_room_ = nullptr;

  // Chances that a room will spawn in that room exit. 0 by default.
  double north_door_chance_ = 0;
  double east_door_chance_ = 0;
  double west_door_chance_ = 0;
  double south_door_chance_ = 0;

  std::string toString();

  // Set the room chances for each direction in one go
  void SetRoomChances(double north_chance,
                      double east_chance,
                      double west_chance,
                      double south_chance);

};


#endif //DGNGEN_ROOM_H
