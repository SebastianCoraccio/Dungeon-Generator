//
// An abstract Room class. Rooms are used to build dungeons.
//

#ifndef DGNGEN_ROOM_H
#define DGNGEN_ROOM_H

#include <iostream>

class Room {

  public:

  // Enum used for room direction. A Room has 4 doors, each facing the below
  // directions
  enum Direction {
    NORTH = 0,
    EAST = 1,
    WEST = 2,
    SOUTH = 3
  };

  // Randomly decides if a branch will occur, depending on the generation
  // chance for the given direction
  // Returns true if a branch should occur
  virtual bool Branch(Direction) = 0;

  // Output information about the room
  virtual std::string toString() = 0;

  // Output single character that represents the room type
  // Despite being named 'to Char' it returns a string
  virtual std::string toChar() = 0;

  std::string char_representation_;

  // TODO: Decide if this is needed. Unnecessary coupling?
  // x position in a dungeon grid
  int x_position_ = -1;
  // y position in a dungeon grid
  int y_position_ = -1;

  // The chance a room will spawn in the given direction
  // Index corresponds to enum Direction's numeric value
  double direction_chances_[4];

  // Not all adjacent rooms have entrances to each other.
  // Direction will have a doorway if direction index is true
  // Index corresponds to enum Direction's numeric value
  bool has_door_[4];
};


#endif //DGNGEN_ROOM_H
