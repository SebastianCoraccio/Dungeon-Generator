//
// A hallway is a type of room with one entrance and one exit. The exit is
// across from the entrance.
//

#ifndef DGNGEN_HALLWAY_H
#define DGNGEN_HALLWAY_H

#include "room.h"

class Hallway : public Room {

  public:

  // Creates a new Hallway room. The only exit is the the room across from the
  // entrance
  // Parent chance is the parents chance to branch. It is decremented by some
  // amount defined in the Config class.
  Hallway(int x_pos, int y_pos, Direction entrance,
          Direction exit, double parent_chance);

  // Randomly decides if a branch will occur, depending on the generation
  // chance for the given direction
  // Returns true if a branch should occur
  bool Branch(Direction);

  // Output information about the room
  std::string toString();

  // Output single character that represents the room type
  // Despite being named 'to Char' it returns a string
  std::string toChar();

  std::string char_representation_ = "H";
};

#endif //DGNGEN_HALLWAY_H
