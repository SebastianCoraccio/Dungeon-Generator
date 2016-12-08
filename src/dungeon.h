//
// Created by Sebastian Coraccio on 12/4/2016.
//
#ifndef DGNGEN_DUNGEON_H
#define DGNGEN_DUNGEON_H

#include <iostream>
#include "room.h"

class Dungeon
{
  private:
  int width = 1;
  int height = 1;

  Room** dungeon_grid;


  void CreateGrid();

  void DestroyGrid();

  void Generate(int start_x, int start_y);

  void CheckPosition(int x_pos, int y_pos);

  public:

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

  // Create the adjacent rooms, according to room door chances
  void CreateBranches(Room*);

  // Get the width of the dungeon grid
  int GetWidth();

  // Get the height of the dungeon grid
  int GetHeight();

  // Returns a reference to a room in the dungeon at the position
  Room* GetRoom(int xpos, int ypos);

  std::string toString();
};

#endif //DGNGEN_DUNGEON_H
