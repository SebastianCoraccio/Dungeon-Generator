//
// A hallway is a type of room with one entrance and one exit. The exit is
// across from the entrance.
//

#ifndef DGNGEN_HALLWAY_H
#define DGNGEN_HALLWAY_H

#include "room.h"

class Hallway : public Room {

  public:
  Hallway();

  // Creates a new Hallway. The entrance is relative to the room that the
  // original branch is from. The only exit is the the room across from the
  // entrance
  // Parent chance is the parents chance to branch
  Hallway(int x_pos, int y_pos, Direction exit, double parent_chance);

  // Randomly decides if a branch will occur, depending on the generation
  // chance for the given direction
  // Returns true if a branch should occur
  bool Branch(Direction);

  // Output information about the room
  std::string toString();

  // Output single character that represents the room type
  std::string toChar();

  std::string char_representation_ = "H";
};

#endif //DGNGEN_HALLWAY_H
