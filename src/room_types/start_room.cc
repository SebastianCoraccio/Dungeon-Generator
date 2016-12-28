//
// A start room is the beginning room of a dungeon. It has equal chances of
// branching in each direction, assuming the adjacent room is within the
// boundaries of the dungeon grid.
//

#include "start_room.h"
#include "../config.h"
#include <ctime>

StartRoom::StartRoom(int x_pos, int y_pos) {
  x_position_ = x_pos;
  y_position_ = y_pos;

  direction_chances_[NORTH] = Config::kStartBranchChance;
  direction_chances_[EAST] = Config::kStartBranchChance;
  direction_chances_[WEST] = Config::kStartBranchChance;
  direction_chances_[SOUTH] = Config::kStartBranchChance;

  has_door_[NORTH] = false;
  has_door_[EAST] = false;
  has_door_[WEST] = false;
  has_door_[SOUTH] = false;

  // There should be at least one branch off the start room
  direction_chances_[rand() % 4] = 1;

}

// Randomly decides if a branch will occur, depending on the generation
// chance for the given direction
// Returns true if a branch should occur
bool StartRoom::Branch(Direction direction) {
  return (rand() % 100) < (direction_chances_[direction] * 100);
};

// Output information about the room
std::string StartRoom::toString() {
  std::string out = "StartRoom";
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
std::string StartRoom::toChar() { return char_representation_; }
