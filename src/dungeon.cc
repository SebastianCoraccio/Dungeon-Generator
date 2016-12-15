//
// Created by Sebastian Coraccio on 12/5/2016.
//

#include <stdlib.h>
#include <time.h>

#include "room_types/room.h"
#include "room_types/empty_room.h"
#include "room_types/start_room.h"
#include "room_types/hallway.h"
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

// Allocates the dungeon grid into a single chunk of memory.
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
  int start_x = rand() % height;
  int start_y = rand() % width;
//  std::cout << start_x << ", " << start_y << std::endl;
  GenerateRandomLayout(start_x, start_y);
}

// Create a random dungeon with defined start room
void Dungeon::GenerateRandomLayout(int start_x, int start_y) {
  CheckPosition(start_x, start_y);
  dungeon_grid[Index(start_x, start_y)] = new StartRoom(start_x, start_y);
  Generate(start_x, start_y);
}

// TODO: Dungeon generation algorithm
void Dungeon::Generate(int start_x, int start_y) {

  Room *room = dungeon_grid[Index(start_x, start_y)];

  // First take room and connect to the adjacent rooms
  int north_x_index = start_x - 1;
  int east_y_index = start_y + 1;
  int west_y_index = start_y - 1;
  int south_x_index = start_x + 1;

  if (north_x_index > 0 && room->Branch(Room::NORTH)) {
    dungeon_grid[Index(north_x_index, start_y)] = new Hallway(north_x_index,
                                                              start_y,
                                                              Room::NORTH,
                                                              room->direction_chances_[Room::NORTH]);
    Generate(north_x_index, start_y);
  }

  if (east_y_index < width && room->Branch(Room::EAST)) {
    dungeon_grid[Index(start_x, east_y_index)] = new Hallway(start_x,
                                                             east_y_index,
                                                             Room::EAST,
                                                             room->direction_chances_[Room::EAST]);
    Generate(start_x, east_y_index);
  }

  if (west_y_index > 0 && room->Branch(Room::WEST)) {
    dungeon_grid[Index(start_x, west_y_index)] = new Hallway(start_x,
                                                             east_y_index,
                                                             Room::WEST,
                                                             room->direction_chances_[Room::WEST]);
    Generate(start_x, west_y_index);
  }

  if (south_x_index < height && room->Branch(Room::SOUTH)) {
    dungeon_grid[Index(south_x_index, start_y)] = new Hallway(south_x_index,
                                                              start_y,
                                                              Room::SOUTH,
                                                              room->direction_chances_[Room::SOUTH]);
    Generate(south_x_index, start_y);
  }

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

int Dungeon::Index(int x_pos, int y_pos) { return x_pos + height * y_pos; }
