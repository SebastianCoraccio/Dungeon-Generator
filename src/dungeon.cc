//
// Created by Sebastian Coraccio on 12/5/2016.
//

#include <stdlib.h>

#include "room.h"
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
  dungeon_grid = new Room *[height];
  for (int i = 0; i < height; ++i) {
    dungeon_grid[i] = new Room[width];
  }

  // Add x and y locations
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      dungeon_grid[i][j].x_location_ = i;
      dungeon_grid[i][j].y_location_ = j;
    }
  }


}

// Deallocate the dungeon grid
Dungeon::~Dungeon() {
  DestroyGrid();
}

// Deallocate the dungeon grid
void Dungeon::DestroyGrid() {

  for (int i = 0; i < height; ++i) {
    delete[] dungeon_grid[i];
  }
  delete[] dungeon_grid;
}

// Get the width of the dungeon grid
int Dungeon::GetWidth() { return width; }

// Get the height of the dungeon grid
int Dungeon::GetHeight() { return height; }

// Returns a reference to a room in the dungeon at the position
Room *Dungeon::GetRoom(int xpos, int ypos) {
  return &dungeon_grid[xpos][ypos];
}

// Create a random dungeon with a random start room
void Dungeon::GenerateRandomLayout() {
  srand(time(NULL));
  int start_x = rand() % width;
  int start_y = rand() % height;
  Generate(start_x, start_y);
}

// Create a random dungeon with defined start room
void Dungeon::GenerateRandomLayout(int start_x, int start_y) {
  Generate(start_x, start_y);
}

void Dungeon::Generate(int start_x, int start_y) {

  // Create the start room
  Room *start_room = &dungeon_grid[start_x][start_y];
  start_room->room_type_ = (Room::Start);
  start_room->SetRoomChances(0.95, 0.95, 0.95, 0.95);

  CreateBranches(start_room);
}

// Create the adjacent rooms, according to room door chances
void Dungeon::CreateBranches(Room *room) {
  srand(time(NULL));

  int room_x = room->x_location_;
  int room_y = room->y_location_;

  // If any of the adjacent rooms are off the grid then set their chance to 0
  if (room_x == 0) room->north_door_chance_ = 0.0;
  if (room_x == width) room->south_door_chance_ = 0.0;
  if (room_y == 0) room->west_door_chance_ = 0.0;
  if (room_y == height) room->east_door_chance_ = 0.0;


  // ----- Northern Branch -----
  if ((rand() % 100) < (room->north_door_chance_ * 100)) {
    if (dungeon_grid[room_x - 1][room_y].room_type_ == Room::Empty) {
      room->northern_room_ = &dungeon_grid[room_x - 1][room_y];
      dungeon_grid[room_x - 1][room_y].room_type_ = Room::Regular;

      room->northern_room_->SetRoomChances(room->north_door_chance_ - .1,
                                           room->east_door_chance_ - .5,
                                           room->west_door_chance_ - .5,
                                           -1);
      CreateBranches(room->northern_room_);
    }

  }


  // ----- Eastern Branch -----
  if ((rand() % 100) < (room->east_door_chance_ * 100)) {
    if (dungeon_grid[room_x][room_y + 1].room_type_ == Room::Empty) {
      room->eastern_room_ = &dungeon_grid[room_x][room_y + 1];
      dungeon_grid[room_x][room_y + 1].room_type_ = Room::Regular;

      room->eastern_room_->SetRoomChances(room->north_door_chance_ - .5,
                                          room->east_door_chance_ - .1,
                                          -1,
                                          room->south_door_chance_ - .5);
      CreateBranches(room->eastern_room_);
    }

  }


  // ----- Western Branch -----
  if ((rand() % 100) < (room->west_door_chance_ * 100)) {
    if (dungeon_grid[room_x][room_y - 1].room_type_ == Room::Empty) {
      room->western_room_ = &dungeon_grid[room_x][room_y - 1];
      dungeon_grid[room_x][room_y - 1].room_type_ = Room::Regular;

      room->western_room_->SetRoomChances(room->north_door_chance_ - .5,
                                          -1,
                                          room->west_door_chance_ - .1,
                                          room->south_door_chance_ - .5);
      CreateBranches(room->western_room_);
    }

  }


  // ----- Southern Branch -----
  if ((rand() % 100) < (room->south_door_chance_ * 100)) {
    if (dungeon_grid[room_x + 1][room_y].room_type_ == Room::Empty) {
      room->southern_room_ = &dungeon_grid[room_x - 1][room_y];
      dungeon_grid[room_x + 1][room_y].room_type_ = Room::Regular;

      room->southern_room_->SetRoomChances(-1,
                                           room->east_door_chance_ - .5,
                                           room->west_door_chance_ - .5,
                                           room->south_door_chance_ - .1);
      CreateBranches(room->southern_room_);
    }

  }
}

std::string Dungeon::toString() {

  std::string dungeon = "";

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      dungeon += dungeon_grid[i][j].toString() += " ";
    }
    dungeon += "\n";
  }
  return dungeon;
}
