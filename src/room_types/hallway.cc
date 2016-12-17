#include "hallway.h"
#include "../config.h"

Hallway::Hallway() {}

// Creates a new Hallway. The entrance is relative to the room that the
// original branch is from. The only exit is the the room across from the
// entrance
Hallway::Hallway(int x_pos, int y_pos, Direction exit, double parent_chance) {
  x_position_ = x_pos;
  y_position_ = y_pos;

  direction_chances_[exit] = parent_chance - Config::kHallwayChanceDecay;

}

// Randomly decides if a branch will occur, depending on the generation
// chance for the given direction
// Returns true if a branch should occur
bool Hallway::Branch(Direction direction) {
  return(rand() % 100) < (direction_chances_[direction] * 100.0);
}

// Output information about the room
std::string Hallway::toString() {
  std::string out = "Hallway";
  out += "(x: " + std::to_string(x_position_);
  out += ", y: " + std::to_string(y_position_);
  out += ") ";

  return out;
}

// Output single character that represents the room type
std::string Hallway::toChar() { return char_representation_; }
