//
// A dungeon is a grid of rooms. It is created with a width and height.
// The dungeon can either be manually created room by room, or randomly generated.
//

#include <stdlib.h>


#include "config.h"
#include "dungeon.h"
#include "room_types/start_room.h"
#include "room_types/hallway.h"
#include "room_types/junction.h"

// Creates a dungeon grid of size w by h
Dungeon::Dungeon(int w, int h) {
  width = w;
  height = h;

  CreateGrid();
}

// Allocates the dungeon grid into a single chunk of memory.
void Dungeon::CreateGrid() {
  dungeon_grid_ = new Room *[width * height];
}

// Deallocate the dungeon grid
Dungeon::~Dungeon() {
  DestroyGrid();
}

// Deallocate the dungeon grid
void Dungeon::DestroyGrid() {
  delete[] dungeon_grid_;
}

// Returns a reference to a room in the dungeon at the position
// Positions in the grid are zero indexed
Room *Dungeon::GetRoom(int x_pos, int y_pos) {
  CheckPosition(x_pos, y_pos);
  return dungeon_grid_[Index(x_pos, y_pos)];
}

// Create a random dungeon with a random start room
void Dungeon::GenerateLayout() {

  int start_x = rand() % height;
  int start_y = rand() % width;

  GenerateLayout(start_x, start_y);
}

// Create a random dungeon with defined start room
void Dungeon::GenerateLayout(int start_x, int start_y) {
  CheckPosition(start_x, start_y);
  dungeon_grid_[Index(start_x, start_y)] = new StartRoom(start_x, start_y);

  // Begin branching at start room location
  DoBranching(start_x, start_y);
}

// Recursively create rooms branching from the given room.
// Stops when a room does not branch due to chance, or the grid is completely
// filled with rooms.
void Dungeon::DoBranching(int room_x, int room_y) {

  Room *room = dungeon_grid_[Index(room_x, room_y)];

  // Find index of adjacent rooms
  int north_x_index = room_x - 1;
  int east_y_index = room_y + 1;
  int west_y_index = room_y - 1;
  int south_x_index = room_x + 1;

  // North Branch
  if (north_x_index > 0 && room->Branch(Room::NORTH)) {
    // Only create a room in the adjacent spot if no room currently exists
    if (dungeon_grid_[Index(north_x_index, room_y)] == nullptr) {
      CreateRoom(north_x_index, room_y,
                 room->direction_chances_[Room::NORTH], Room::SOUTH, Room::NORTH);
      DoBranching(north_x_index, room_y);
    }
  }

  // East Branch
  if (east_y_index < width && room->Branch(Room::EAST)) {
    // Only create a room in the adjacent spot if no room currently exists
    if (dungeon_grid_[Index(room_x, east_y_index)] == nullptr) {
      CreateRoom(room_x, east_y_index,
                 room->direction_chances_[Room::EAST], Room::WEST, Room::EAST);
      DoBranching(room_x, east_y_index);
    }
  }

  // West Branch
  if (west_y_index > 0 && room->Branch(Room::WEST)) {
    // Only create a room in the adjacent spot if no room currently exists
    if (dungeon_grid_[Index(room_x, west_y_index)] == nullptr) {
      CreateRoom(room_x, west_y_index,
                 room->direction_chances_[Room::WEST], Room::EAST, Room::WEST);
      DoBranching(room_x, west_y_index);
    }
  }

  // South Branch
  if (south_x_index < height && room->Branch(Room::SOUTH)) {
    // Only create a room in the adjacent spot if no room currently exists
    if (dungeon_grid_[Index(south_x_index, room_y)] == nullptr) {
      CreateRoom(south_x_index, room_y,
                 room->direction_chances_[Room::SOUTH], Room::NORTH, Room::SOUTH);
      DoBranching(south_x_index, room_y);
    }
  }

}

// Creates the branch room. Whether it is a junction of a hallway is decided randomly.
void Dungeon::CreateRoom(int x_location, int y_location,
                         double branch_chance, Room::Direction entrance, Room::Direction exit) {

  if ((rand() % 100) < (Config::kCreateJunction * 100.0))
    dungeon_grid_[Index(x_location, y_location)] = new Junction(x_location, y_location,
                                                                entrance, branch_chance);
  else
    dungeon_grid_[Index(x_location, y_location)] = new Hallway(x_location, y_location,
                                                               exit, branch_chance);
}

// Checks that the x and y position are within the dungeon grid
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

// Outputs the dungeon layout using each rooms single character representation
std::string Dungeon::toString() {

  std::string dungeon = "";
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      if (dungeon_grid_[Index(i, j)] == nullptr)
        dungeon += ".";
      else
        dungeon += dungeon_grid_[Index(i, j)]->toChar();

      // Spaces on x axis for readability of output
      dungeon += " ";
    }
    dungeon += "\n";
  }
  return dungeon;
}

int Dungeon::Index(int x_pos, int y_pos) { return x_pos + height * y_pos; }
