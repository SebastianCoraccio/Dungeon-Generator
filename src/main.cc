#include <iostream>
#include "dungeon.h"

const int kGridXSize = 3;
const int kGridYSize = 4;

int RoomTest();
int DungeonTest();

int main() {
  std::cout << "Welcome to dungeon Generator.\n";

  //RoomTest();

  DungeonTest();
}

int RoomTest(){
  std::cout << "Running Room Test\n";

  Room room = Room(20,1,1,1);
  room.room_type_ = (Room::Start);
  std::string equalRoom = (room.room_type_ == Room::Start) ? "They are "
          "equal" : "They are not equal";
  std::cout << equalRoom << std::endl;

  return 1;
}

int DungeonTest(){

  Dungeon dun1 = Dungeon(kGridXSize, kGridYSize);

  dun1.GetRoom(3,2)->room_type_ = Room::Treasure;

  //dun1.GenerateRandomLayout(0,0);
  std::cout << dun1.toString();

  return 1;
}
