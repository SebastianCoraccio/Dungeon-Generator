//
// This class has 1 dungeon as a member, and can output the layout of the
// dungeon to a pgm file. Whether or not the room has doors is taken into
// account when outputting the room
//

#include <iostream>
#include <fstream>
#include "dungeon.h"
#include "dungeon_drawer.h"
#include "room.h"

// Used to chance the size of the output file
int kScale = 30;

// Creates a dungeon drawer, and a new dungeon of width by height
DungeonDrawer::DungeonDrawer(int width, int height) {
  dungeon_ = new Dungeon(width, height);
}

// Creates a new dungeon drawer using an existing dungeon
DungeonDrawer::DungeonDrawer(Dungeon* dun) {
  dungeon_ = dun;
} 

// The whole row is convert to pgm format at once because the pgm
// format is line by line, so a whole row is several lines in a row
// x_pos is the row number
std::string DungeonDrawer::ConvertRow(int x_pos) {

  std::string room_to_string = "";

  for (int h = 0; h < kScale; h++) {
    for (int i = 0; i < dungeon_->GetWidth(); i++) {
      for (int j = 0; j < kScale; j++) {
        // If the room is null then it will not get colored in
        if (dungeon_->GetRoom(x_pos, i) == nullptr) {
          room_to_string += std::to_string(240);
        } else {
          // Checks if the current pixel to be output is on the border of a room
          if (h < kScale * .1 || h > kScale * .9 ||
              j < kScale * .1 || j > kScale * .9) {
            // North Doorways
            if (h < kScale * .1 && j > kScale * .3 && j < kScale * .7 &&
                dungeon_->GetRoom(x_pos, i)->has_door_[Room::NORTH]) {
              room_to_string += std::to_string(200);
            }
            // South Doorways
            else if (h > kScale * .9 && j > kScale * .3 && j < kScale * .7 &&
                     dungeon_->GetRoom(x_pos, i)->has_door_[Room::SOUTH]) {
              room_to_string += std::to_string(200);
            }
            // East Doorways
            else if (j > kScale * .1 && h > kScale * .3 && h < kScale * .7 &&
                     dungeon_->GetRoom(x_pos, i)->has_door_[Room::EAST]) {
              room_to_string += std::to_string(200);
            }
            // West Doorways
            else if (j < kScale * .9 && h > kScale * .3 && h < kScale * .7 &&
                     dungeon_->GetRoom(x_pos, i)->has_door_[Room::WEST]) {
              room_to_string += std::to_string(200);
            } else {
              // If the current pixel to be output is not a doorway then it is
              // given black to represent a solid wall
              room_to_string += std::to_string(0);
            }
          } else {
            // This is the inside of a room, so it is marked with a gray color
            // in the output file
            room_to_string += std::to_string(200);
          }
        }

        room_to_string += "\n";
      }
    }
  }
  return room_to_string;
}

// Outputs a representation of the dungeon to a .pgm file
void DungeonDrawer::PrintToFile() {
  std::ofstream outfile;
  outfile.open("bin/dungeon.pgm", std::ofstream::out | std::ofstream::trunc);
  if(outfile.is_open()){ 
    outfile << "P2\n" << dungeon_->GetWidth() * kScale << " "
            << dungeon_->GetHeight() * kScale << "\n" << "255\n";

    for (int i = 0; i < dungeon_->GetHeight(); i++)
      outfile << ConvertRow(i);

    outfile.close();  
  } else {
    std::cerr << "Could not open file" << std::endl;
  }

}
