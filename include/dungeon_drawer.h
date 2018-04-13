//
// This class has 1 dungeon as a member, and can output the layout of the
// dungeon to a pgm file. Whether or not the room has doors is taken into
// account when outputting the room
//

#ifndef DGNGEN_DUNGEON_DRAWER_H
#define DGNGEN_DUNGEON_DRAWER_H

#include "dungeon.h"

class DungeonDrawer {

  public:
  // Creates a dungeon drawer, and a new dungeon of width by height
  DungeonDrawer(int width, int height);

  // Creates a new dungeon drawer using an existing dungeon
  DungeonDrawer(Dungeon* dun);

  // dungeon that will be represented in the output file
  Dungeon *dungeon_;

  // Outputs a representation of the dungeon to a .pgm file
  void PrintToFile();

  private:

  // The whole row is convert to pgm format at once because the pgm
  // format is line by line, so a whole row is several lines in a row
  // x_pos is the row number
  std::string ConvertRow(int x_pos);

};


#endif //DGNGEN_DUNGEON_DRAWER_H
