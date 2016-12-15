//
// Created by Sebastian Coraccio on 12/4/2016.
//
// A Room Class created for building dungeons
//

#ifndef DGNGEN_ROOM_H
#define DGNGEN_ROOM_H

#include <iostream>

class Room {

  public:

  enum Direction {
    NORTH,
    EAST,
    WEST,
    SOUTH
  };

  // Randomly decides if a branch will occur, depending on the generation
  // chance for the given direction
  // Returns true if a branch should occur
  virtual bool Branch(Direction) = 0;

  // Output information about the room
  virtual std::string toString() = 0;

  // Output single character that represents the room type
  virtual std::string toChar() = 0;

  std::string char_representation_;
  // x position in a dungeon grid
  int x_position_ = -1;
  // y position in a dungeon grid
  int y_position_ = -1;

  double direction_chances_[4];
};


#endif //DGNGEN_ROOM_H
