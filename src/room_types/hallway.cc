//
// A hallway is a type of room with one entrance and one exit. The exit is
// across from the entrance.
//

#include "hallway.h"
#include "../config.h"

// Creates a new Hallway room. The only exit is the the room across from the
// entrance
// Parent chance is the parents chance to branch. It is decremented by some
// amount defined in the Config class.
Hallway::Hallway(int x_pos, int y_pos, Direction entrance,
                 Direction exit, double parent_chance) {
  x_position_ = x_pos;
  y_position_ = y_pos;

  has_door_[entrance] = true;

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
  out += ") Has doors:{\n";

  if(has_door_[NORTH])
    out += "North\n";
  if(has_door_[EAST])
    out += "East\n";
  if(has_door_[WEST])
    out += "West\n";
  if(has_door_[SOUTH])
    out += "South\n";

  out += "}";

  return out;
}

// Output single character that represents the room type
// Despite being named 'to Char' it returns a string
std::string Hallway::toChar() { return char_representation_; }
