//
// Boss rooms are located at the room furthest from the start room.
// They do not branch, and act as a way to end the dungeon
//

#include "boss_room.h"

BossRoom::BossRoom(int x_pos, int y_pos) {
  x_position_ = x_pos;
  y_position_ = y_pos;

  has_door_[NORTH] = false;
  has_door_[EAST] = false;
  has_door_[WEST] = false;
  has_door_[SOUTH] = false;
}

// Randomly decides if a branch will occur, depending on the generation
// chance for the given direction
// Returns true if a branch should occur
bool BossRoom::Branch(Direction direction) {
  return false;
};

// Output information about the room
std::string BossRoom::toString() {
  std::string out = "BossRoom";
  out += "(x: " + std::to_string(x_position_);
  out += ", y: " + std::to_string(y_position_);
  out += ") Has doors:{\n";

  if (has_door_[NORTH])
    out += "North\n";
  if (has_door_[EAST])
    out += "East\n";
  if (has_door_[WEST])
    out += "West\n";
  if (has_door_[SOUTH])
    out += "South\n";

  out += "}";

  return out;
}

// Output single character that represents the room type
std::string BossRoom::toChar() { return char_representation_; }
