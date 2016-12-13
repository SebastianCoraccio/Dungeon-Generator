#include <iostream>
#include "dungeon.h"

const int kGridWidth = 3;
const int kGridHeight = 4;

int DungeonTest();

int main() {

  DungeonTest();
}

int DungeonTest() {

  Dungeon dun1 = Dungeon(kGridWidth, kGridHeight);
  dun1.GenerateRandomLayout(3,2);
  std::cout << dun1.toString();

  return 1;
}
