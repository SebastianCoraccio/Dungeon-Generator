//
// Created by Sebas on 12/9/2016.
//

#include "empty_room.h"

EmptyRoom::EmptyRoom() {};

EmptyRoom::EmptyRoom(int x_pos, int y_pos) {
  x_position_ = x_pos;
  y_position_ = y_pos;

}

Room **EmptyRoom::Branch() {
  return nullptr;
}

// Output information about the room
std::string EmptyRoom::toString() {
  std::string out = "EmptyRoom";
  out += "(x: " + std::to_string(x_position_);
  out += ", y: " + std::to_string(y_position_);
  out += ") {}";
  return out;
}

// Output single character that represents the room type
std::string EmptyRoom::toChar() { return char_representation_; }
