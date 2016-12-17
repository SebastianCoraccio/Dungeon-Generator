#include "junction.h"
#include "../config.h"

Junction::Junction() {}

Junction::Junction(int x_pos, int y_pos, Direction entrance, double
parent_chance) {

  x_position_ = x_pos;
  y_position_ = y_pos;

  // Decide how many branches are possible (0-3)
  if((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::NORTH] = parent_chance - Config::kJunctionChanceDecay;
  if((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::EAST] = parent_chance - Config::kJunctionChanceDecay;
  if((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::EAST] = parent_chance - Config::kJunctionChanceDecay;
  if((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::SOUTH] = parent_chance - Config::kJunctionChanceDecay;

  // The entrance direction chance should be set back to 0
  direction_chances_[entrance] = 0;

}

// Randomly decides if a branch will occur, depending on the generation
// chance for the given direction
// Returns true if a branch should occur
bool Junction::Branch(Direction direction) {
  return (rand() % 100) < (direction_chances_[direction] * 100.0);
}

// Output information about the room
std::string Junction::toString() {
  std::string out = "Junction";
  out += "(x: " + std::to_string(x_position_);
  out += ", y: " + std::to_string(y_position_);
  out += ") ";

  return out;
}

// Output single character that represents the room type
std::string Junction::toChar() { return char_representation_; }