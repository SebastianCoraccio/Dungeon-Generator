//
// Created by Sebastian on 12/13/2016.
//

#include "start_room.h"

std::string char_representation = "S";

StartRoom::StartRoom() {}

StartRoom::StartRoom(int x_pos, int y_pos){
  x_position_ = x_pos;
  y_position_ = y_pos;
}

Room **StartRoom::Branch(){};

// Output information about the room
std::string StartRoom::toString(){
  std::string out = "StartRoom";
  out += "(x: " + std::to_string(x_position_);
  out += ", y: " + std::to_string(y_position_);

  // Adjacent room information is only included temporarily for easier debugging
  // TODO: Remove when no longer needed
  if(north_room_ != nullptr)
    out += ")\n{north: " + north_room_->toChar();
  else
    out += "}\n{north: NULL";

  if(east_room_ != nullptr)
    out += "\neast: " + east_room_->toChar();
  else
    out += "\neast: NULL";

  if(west_room_ != nullptr)
    out += "\nwest: " + west_room_->toChar();
  else
    out += "\nwest: NULL";

  if(south_room_ != nullptr)
    out += "\nsouth: " + south_room_->toChar();
  else
    out += "\nsouth: NULL";

  out += "} ";

  return out;
}

// Output single character that represents the room type
std::string StartRoom::toChar() { return char_representation_; }
