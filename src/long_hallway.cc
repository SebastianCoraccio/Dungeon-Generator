//
// A long hallway is a set of two rooms which act like one long hallway.
// It is used to represent rooms that are sized 1x2 or 2x1, as opposed to the
// usual 1x1.
//

#include "long_hallway.h"
#include "../include/config.h"

// Creates a new Long hallway room. The only exit is the the room across from the
// entrance
// Parent chance is the parents chance to branch. It is decremented by some
// amount defined in the Config class.
LongHallway::LongHallway(int x_pos, int y_pos, Direction entrance,
                 Direction exit, double parent_chance) {
  x_position_ = x_pos;
  y_position_ = y_pos;

  has_door_[NORTH] = false;
  has_door_[EAST] = false;
  has_door_[WEST] = false;
  has_door_[SOUTH] = false;

  has_door_[entrance] = true;

  direction_chances_[exit] = parent_chance - Config::kHallwayChanceDecay;

}

// Randomly decides if a branch will occur, depending on the generation
// chance for the given direction
// Returns true if a branch should occur
bool LongHallway::Branch(Direction direction) {
  return (rand() % 100) < (direction_chances_[direction] * 100.0);
}

// Output information about the room
std::string LongHallway::toString() {
  std::string out = "LongHallway";
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
// Despite being named 'to Char' it returns a string
std::string LongHallway::toChar() { return char_representation_; }
