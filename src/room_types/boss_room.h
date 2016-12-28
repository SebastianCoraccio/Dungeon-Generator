//
// Boss rooms are located at the room furthest from the start room.
// They do not branch, and act as a way to end the dungeon
//

#ifndef DGNGEN_BOSS_ROOM_H
#define DGNGEN_BOSS_ROOM_H

#include "room.h"

class BossRoom : public Room {
  public:

  BossRoom(int x_pos, int y_pos);

  // Randomly decides if a branch will occur, depending on the generation
  // chance for the given direction
  // Returns true if a branch should occur
  bool Branch(Direction);

  // Output information about the room
  std::string toString();

  // Output single character that represents the room type
  // Despite being named 'to Char' it returns a string
  std::string toChar();

  std::string char_representation_ = "B";

};

#endif //DGNGEN_BOSS_ROOM_H
