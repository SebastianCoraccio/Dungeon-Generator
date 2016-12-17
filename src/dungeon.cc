#include <stdlib.h>

#include "room_types/room.h"
#include "room_types/empty_room.h"
#include "room_types/start_room.h"
#include "room_types/hallway.h"
#include "room_types/junction.h"
#include "dungeon.h"
#include "config.h"

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

// Returns a reference to a room in the dungeon at the position
// Positions in the grid are zero indexed
Room *Dungeon::GetRoom(int x_pos, int y_pos) {
  CheckPosition(x_pos, y_pos);
  return dungeon_grid[Index(x_pos, y_pos)];
}

// Create a random dungeon with a random start room
void Dungeon::GenerateRandomLayout() {

  int start_x = rand() % height;
  int start_y = rand() % width;

  GenerateRandomLayout(start_x, start_y);
}

// Create a random dungeon with defined start room
void Dungeon::GenerateRandomLayout(int start_x, int start_y) {
  CheckPosition(start_x, start_y);
  dungeon_grid[Index(start_x, start_y)] = new StartRoom(start_x, start_y);
  Generate(start_x, start_y);
}

//
void Dungeon::Generate(int start_x, int start_y) {

  Room *room = dungeon_grid[Index(start_x, start_y)];

  // Find index of adjacent rooms
  int north_x_index = start_x - 1;
  int east_y_index = start_y + 1;
  int west_y_index = start_y - 1;
  int south_x_index = start_x + 1;

  // North Branch
  if (north_x_index > 0 && room->Branch(Room::NORTH)) {
    CreateBranch(north_x_index, start_y,
                 room->direction_chances_[Room::NORTH], Room::SOUTH, Room::NORTH);
    Generate(north_x_index, start_y);
  }

  // East Branch
  if (east_y_index < width && room->Branch(Room::EAST)) {
    CreateBranch(start_x, east_y_index,
                 room->direction_chances_[Room::EAST], Room::WEST, Room::EAST);
    Generate(start_x, east_y_index);
  }

  // West Branch
  if (west_y_index > 0 && room->Branch(Room::WEST)) {
    CreateBranch(start_x, west_y_index,
                 room->direction_chances_[Room::WEST], Room::EAST, Room::WEST);
    Generate(start_x, west_y_index);
  }

  // South Branch
  if (south_x_index < height && room->Branch(Room::SOUTH)) {
    CreateBranch(south_x_index, start_y,
                 room->direction_chances_[Room::SOUTH], Room::NORTH, Room::SOUTH);
    Generate(south_x_index, start_y);
  }

}

// Creates the branch room. Whether it is a junction of a hallway is decided randomly.
void Dungeon::CreateBranch(int x_location, int y_location,
                           double branch_chance, Room::Direction entrance, Room::Direction exit){

  if((rand() % 100) < (Config::kCreateJunction * 100.0))
    dungeon_grid[Index(x_location, y_location)] = new Junction(x_location, y_location,
                                                               entrance, branch_chance);
  else
    dungeon_grid[Index(x_location, y_location)] = new Hallway(x_location, y_location,
                                                              exit, branch_chance);
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
      // Spaces on x axis for readability of output
      dungeon += " ";
    }
    dungeon += "\n";
  }
  return dungeon;
}

int Dungeon::Index(int x_pos, int y_pos) { return x_pos + height * y_pos; }
