//
// A junction is a room type that has an entrance, and 0-3 exits. The number
// of exits is randomly decided when the room is created.
//

#ifndef DGNGEN_JUNCTION_H
#define DGNGEN_JUNCTION_H

#include "room.h"

class Junction : public Room {

  public:
  Junction();


  Junction(int x_pos, int y_pos, Direction entrance, double parent_chance);

  // Randomly decides if a branch will occur, depending on the branch
  // chance for the given direction
  // Returns true if a branch should occur
  bool Branch(Direction);

  // Output information about the room
  std::string toString();

  // Output single character that represents the room type
  std::string toChar();

  std::string char_representation_ = "J";
};


#endif //DGNGEN_JUNCTION_H
