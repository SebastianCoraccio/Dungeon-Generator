//
// A start room is the beginning room of a dungeon. It has equal chances of
// branching in each direction, assuming the adjacent room is within the
// boundaries of the dungeon grid.
//

#ifndef DGNGEN_START_ROOM_H_H
#define DGNGEN_START_ROOM_H_H

#include "room.h"

class StartRoom : public Room {
  public:

  StartRoom(int x_pos, int y_pos);

  // Randomly decides if a branch will occur, depending on the generation
  // chance for the given direction
  // Returns true if a branch should occur
  bool Branch(Direction);

  // Output information about the room
  std::string toString();

  // Output single character that represents the room type
  // Despite being named 'to Char' it returns a string
  std::string toChar();

  std::string char_representation_ = "S";

};

#endif //DGNGEN_START_ROOM_H_H
