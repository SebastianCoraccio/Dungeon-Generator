//
// Created by Sebastian on 12/13/2016.
//

#ifndef DGNGEN_START_ROOM_H_H
#define DGNGEN_START_ROOM_H_H

#include "room.h"

class StartRoom : public Room {
  public:
  std::string char_representation_ = "S";

  StartRoom();

  StartRoom(int x_pos, int y_pos);

  Room **Branch();

  // Output information about the room
  std::string toString();

  // Output single character that represents the room type
  std::string toChar();

  private:
  Room* north_room_ = nullptr;
  Room* east_room_;
  Room* west_room_;
  Room* south_room_;

};

#endif //DGNGEN_START_ROOM_H_H
