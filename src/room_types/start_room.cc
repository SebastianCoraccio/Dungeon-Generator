#include "start_room.h"
#include "../config.h"
#include <ctime>


StartRoom::StartRoom() {}

StartRoom::StartRoom(int x_pos, int y_pos){
  x_position_ = x_pos;
  y_position_ = y_pos;

  direction_chances_[NORTH] = Config::kStartBranchChance;
  direction_chances_[EAST] = Config::kStartBranchChance;
  direction_chances_[WEST] = Config::kStartBranchChance;
  direction_chances_[SOUTH] = Config::kStartBranchChance;

  // There should be at least one branch off the start room
  direction_chances_[rand() % 4] = 1;

}

// Randomly decides if a branch will occur, depending on the generation
// chance for the given direction
// Returns true if a branch should occur
bool StartRoom::Branch(Direction direction){
  return (rand() % 100) < (direction_chances_[direction] * 100 );
};

// Output information about the room
std::string StartRoom::toString(){
  std::string out = "StartRoom";
  out += "(x: " + std::to_string(x_position_);
  out += ", y: " + std::to_string(y_position_);
  out += ") ";

  return out;
}

// Output single character that represents the room type
std::string StartRoom::toChar() { return char_representation_; }
