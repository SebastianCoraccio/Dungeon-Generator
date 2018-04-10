//
// A junction is a room type that has an entrance, and 0-3 exits. The number
// of exits is randomly decided when the room is created.
//

#include "junction.h"
#include "../include/config.h"

// Creates a junction. How many exits the room has is decided during
// construction.
// Parent chance is the parents chance to branch. It is decremented by some
// amount defined in the Config class.
Junction::Junction(int x_pos, int y_pos, Direction entrance, double
parent_chance) {

  x_position_ = x_pos;
  y_position_ = y_pos;

  has_door_[NORTH] = false;
  has_door_[EAST] = false;
  has_door_[WEST] = false;
  has_door_[SOUTH] = false;

  has_door_[entrance] = true;

  // Decide how many branches are possible (0-3)
  if ((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::NORTH] =
            parent_chance - Config::kJunctionChanceDecay;
  if ((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::EAST] =
            parent_chance - Config::kJunctionChanceDecay;
  if ((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::EAST] =
            parent_chance - Config::kJunctionChanceDecay;
  if ((rand() % 100) < (Config::kJunctionExitChance * 100.0))
    direction_chances_[Room::SOUTH] =
            parent_chance - Config::kJunctionChanceDecay;

  // The entrance direction chance should be set back to 0
  direction_chances_[entrance] = 0;

}

// Randomly decides if a branch will occur, depending on the generation
// chance for the given direction
// Returns true if a branch should occur
bool Junction::Branch(Direction direction) {
  return (rand() % 100) < (direction_chances_[direction] * 100.0);
}

// Output single character that represents the room type
// Despite being named 'to Char' it returns a string
std::string Junction::toString() {
  std::string out = "Junction";
  out += "(x: " + std::to_string(x_position_);
  out += ", y: " + std::to_string(y_position_);
  out += ") Has doors:{\n";

  if (has_door_[NORTH])
    out += "  North\n";
  if (has_door_[EAST])
    out += "  East\n";
  if (has_door_[WEST])
    out += "  West\n";
  if (has_door_[SOUTH])
    out += "  South\n";

  out += "}";

  return out;
}

// Output single character that represents the room type
// Despite being named 'to Char' it returns a string
std::string Junction::toChar() { return char_representation_; }