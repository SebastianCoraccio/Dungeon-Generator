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
  int width_ = 1;
  int height_ = 1;

  //Location of the exit room, and its depth relative to the start room
  int boss_x_pos_ = 0;
  int boss_y_pos_ = 0;
  int boss_depth_ = 0;
  Room::Direction boss_entrance_direction_;

  // Allocates the dungeon grid into a single chunk of memory.
  void CreateGrid();

  // Deallocate the dungeon grid
  void DestroyGrid();

  // Recursively create rooms branching from the given room.
  // Stops when a room does not branch due to chance, or the grid is completely
  // filled with rooms.
  void DoBranching(int room_x, int room_y, int depth);

  // Creates the branch room. Whether it is a junction of a hallway is decided randomly.
  void CreateRoom(int x_location, int y_location,
                  double branch_chance, Room::Direction entrance,
                  Room::Direction exit, int depth);

  // Creates a long hallway if possible (2x1 or 1x2 depending on exit)
  // Returns true if a long hallway was created
  bool CreateLongHallway(int x_location, int y_location,
                         double branch_chance, Room::Direction entrance,
                         Room::Direction exit, int depth);

  // Checks that the x and y position are within the dungeon grid
  void CheckPosition(int x_pos, int y_pos);

  int Index(int x_pos, int y_pos);

  public:
  Room **dungeon_grid_;

  // Creates a dungeon grid of size width by height
  Dungeon(int width, int height);

  // Dungeon Destructor
  ~Dungeon();

  // Get the dungeons width
  int GetWidth();

  // Get the dungeons height
  int GetHeight();

  // Create a random dungeon with a random start room
  void GenerateLayout();

  // Create a random dungeon with defined start room
  void GenerateLayout(int start_x, int start_y);

  // Returns a reference to a room in the dungeon at the position
  Room *GetRoom(int x_pos, int y_pos);

  // Outputs the dungeon layout using each rooms single character representation
  std::string toString();
};

#endif //DGNGEN_DUNGEON_H
