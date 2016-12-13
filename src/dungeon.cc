//
// Created by Sebastian Coraccio on 12/5/2016.
//

#include <stdlib.h>

#include "room.h"
#include "empty_room.h"
#include "start_room.h"
#include "dungeon.h"

// Default constructor
Dungeon::Dungeon() {
  CreateGrid();
}

// Creates a dungeon grid of size X by Y
Dungeon::Dungeon(int w, int h) {
  width = w;
  height = h;

  CreateGrid();
}

// Allocates the dungeon grid
// TODO: Allocate grid with a single block of memory
// Doing so will be more efficient, and easier to assign x and y values to rooms
void Dungeon::CreateGrid() {

  dungeon_grid = new Room *[width * height];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      dungeon_grid[Index(i, j)] = new EmptyRoom(i, j);

    }
  }
}

// Deallocate the dungeon grid
Dungeon::~Dungeon() {
  DestroyGrid();
}

// Deallocate the dungeon grid
void Dungeon::DestroyGrid() {

  delete[] dungeon_grid;

}

// Get the width of the dungeon grid
int Dungeon::GetWidth() { return width; }

// Get the height of the dungeon grid
int Dungeon::GetHeight() { return height; }

// Returns a reference to a room in the dungeon at the position
// Positions in the grid are zero indexed


Room *Dungeon::GetRoom(int x_pos, int y_pos) {
  CheckPosition(x_pos, y_pos);
  return dungeon_grid[Index(x_pos, y_pos)];
}

// Create a random dungeon with a random start room
void Dungeon::GenerateRandomLayout() {
  srand(time(NULL));
  int start_x = rand() % width;
  int start_y = rand() % height;
  GenerateRandomLayout(start_x, start_y);
}

// Create a random dungeon with defined start room
void Dungeon::GenerateRandomLayout(int start_x, int start_y) {
  CheckPosition(start_x, start_y);
  dungeon_grid[Index(start_x, start_y)] = new StartRoom(start_x, start_y);
  //Generate(start_x, start_y);
}

// TODO: Dungeon generation algorithm
void Dungeon::Generate(int start_x, int start_y) {
}

void Dungeon::CheckPosition(int x_pos, int y_pos) {
  if (x_pos >= height || x_pos < 0) {
    std::cerr << "Given X value must be 0 or greater " <<
              "and less than the grid's width.\n";
    exit(1);
  }
  if (y_pos >= width || y_pos < 0) {
    std::cerr << "Given Y value must be 0 or greater " <<
              "and less than the grid's height.\n";
    exit(-1);
  }

}

std::string Dungeon::toString() {

  std::string dungeon = "";

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      dungeon += dungeon_grid[Index(i, j)]->toChar();
      // Spacing on x axis for readability of output
      dungeon += " ";
    }
    dungeon += "\n";
  }
  return dungeon;
}

int Dungeon::Index(int x_pos, int y_pos){ return x_pos + height * y_pos; }
