#include <iostream>
#include "dungeon.h"

const int kGridWidth = 20;
const int kGridHeight = 20;

int DungeonTest();

int main() {

  DungeonTest();
}

int DungeonTest() {

  Dungeon dun1 = Dungeon(kGridWidth, kGridHeight);

  dun1.GenerateRandomLayout(9, 9);

  std::cout << dun1.toString();

  return 1;
}
