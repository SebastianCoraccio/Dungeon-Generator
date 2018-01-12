//
// A long hallway is a set of two rooms which act like one long hallway.
// It is used to represent rooms that are sized 1x2 or 2x1, as opposed to the
// usual 1x1.
//

#ifndef DGNGEN_LONG_HALLWAY_H
#define DGNGEN_LONG_HALLWAY_H

#include "room.h"

class LongHallway : public Room {

  public:

  // Creates a new Long hallway room. The only exit is the the room across from the
  // entrance
  // Parent chance is the parents chance to branch. It is decremented by some
  // amount defined in the Config class.
  LongHallway(int x_pos, int y_pos, Direction entrance,
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

  std::string char_representation_ = "L";

};


#endif //DGNGEN_LONG_HALLWAY_H
