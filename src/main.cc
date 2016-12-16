#include <iostream>
#include "dungeon.h"

const int kGridWidth = 15;
const int kGridHeight = 15;

int DungeonTest();

int main() {
  unsigned seed = time(0);
  std::cout << "Seed: " << seed << std::endl;
  srand(seed);
  DungeonTest();
}

int DungeonTest() {

  Dungeon dun1 = Dungeon(kGridWidth, kGridHeight);

  dun1.GenerateRandomLayout(7, 7);

  std::cout << dun1.toString();

  return 1;
}
