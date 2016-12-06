//
// Created by Sebastian Coraccio on 12/4/2016.
//
// A Room Class created for building dungeons
//

#include "room.h"

// Create a new room with default values
Room::Room() {

}

// Creates a room with defined adjacent room generation chances.
Room::Room(double north_chance,
           double east_chance,
           double west_chance,
           double south_chance) {

  Room::SetRoomChances(north_chance, east_chance, west_chance, south_chance);
}

// Returns a letter corresponding to the room type
std::string Room::toString() {

  // std::cout << x_location_ << " " << y_location_ << std::endl;

  switch (room_type_) {
    case Regular:
      return "R";
    case Start:
      return "S";
    case Exit:
      return "E";
    case Boss:
      return "B";
    case Treasure:
      return "T";
    default:
      return ".";
  }

}

// Set the room chances for each direction in one go
// if chance > 0 then no change will be made
void Room::SetRoomChances(double north_chance,
                          double east_chance,
                          double west_chance,
                          double south_chance) {

  if (north_chance > 0) north_door_chance_ = north_chance;
  else north_door_chance_ = 0;
  if (east_chance > 0) east_door_chance_ = east_chance;
  else east_door_chance_ = 0;
  if (west_chance > 0) west_door_chance_ = west_chance;
  else west_door_chance_ = 0;
  if (south_chance > 0) south_door_chance_ = south_chance;
  else west_door_chance_ = 0;

}
