//
// A dungeon is a grid of rooms. It is created with a width and height.
// The dungeon can either be manually created room by room, or randomly generated.
//

#ifndef DGNGEN_DUNGEON_H
#define DGNGEN_DUNGEON_H

#include <iostream>
#include "room_types/room.h"

class Dungeon {
  private:
  int width = 1;
  int height = 1;

  void CreateGrid();

  void DestroyGrid();

  void Generate(int start_x, int start_y);

  void CreateBranch(int x_location, int y_location,
                    double branch_chance, Room::Direction entrance, Room::Direction exit);

  void CheckPosition(int x_pos, int y_pos);

  int Index(int x_pos, int y_pos);

  public:
  Room **dungeon_grid;
  // Default constructor
  Dungeon();

  // Creates a dungeon grid of size width by height
  Dungeon(int width, int height);

  // Deallocate the dungeon grid
  ~Dungeon();

  // Create a random dungeon with a random start room
  void GenerateRandomLayout();

  // Create a random dungeon with defined start room
  void GenerateRandomLayout(int start_x, int start_y);

  // Returns a reference to a room in the dungeon at the position
  Room *GetRoom(int xpos, int ypos);

  std::string toString();
};

#endif //DGNGEN_DUNGEON_H
