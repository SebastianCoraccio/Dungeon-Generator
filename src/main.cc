#include <iostream>
#include "dungeon.h"
#include "config.h"


int DungeonTest();

int main() {
  unsigned seed = time(0);
  std::cout << "Seed: " << seed << std::endl;
  srand(seed);
  DungeonTest();
}

int DungeonTest() {

  Dungeon dun1 = Dungeon(Config::kGridWidth, Config::kGridHeight);

  for(int i = 0; i < 50; i++ )
    dun1.GenerateLayout();

  dun1.GenerateLayout(Config::kGridWidth / 2, Config::kGridHeight / 2);

  std::cout << dun1.toString();

  return 1;
}
