#include <iostream>
#include "dungeon.h"

const int kGridXSize = 10;
const int kGridYSize = 12;

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

  Dungeon dun1 = Dungeon(11,11);

  dun1.GenerateRandomLayout(5, 5);
  std::cout << dun1.toString();

  return 1;
}
