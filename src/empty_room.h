//
// Created by Sebastian on 12/9/2016.
//



#ifndef DGNGEN_EMPTY_ROOM_H_H
#define DGNGEN_EMPTY_ROOM_H_H

#include "room.h"

class EmptyRoom : public Room {
  public:
  std::string char_representation_ = ".";

  EmptyRoom();
  EmptyRoom(int x_pos, int y_pos);

   Room **Branch();

  // Output information about the room
   std::string toString();

  // Output single character that represents the room type
   std::string toChar();

};

#endif //DGNGEN_EMPTY_ROOM_H_H
