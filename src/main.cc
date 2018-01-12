#include <iostream>
#include "dungeon.h"
#include "dungeon_drawer.h"
#include "config.h"

bool DO_DEBUGGING = false;

int DungeonTest();
unsigned int hash(unsigned int x);

int main(int argc, char *argv[]) {

  if (argc == 2) {
    if (argv[1])
      DO_DEBUGGING = true;
  }

  unsigned seed = time(0);
  seed = hash(seed);
  std::cout << "Seed: " << seed << std::endl;
  srand(seed);
  for(int i = 0; i < 10000; i++){
    rand();
  }
  //DungeonTest();

  DungeonDrawer dd = DungeonDrawer(12,10);
  dd.dungeon_->GenerateLayout(10/2, 12/2);
  std::cout << dd.dungeon_->toString();
  dd.PrintToFile();

  int x_pos = 1;
  int y_pos = 1;

  while (DO_DEBUGGING) {
    std::cout << "\nEnter x position:";
    std::cin >> x_pos;

    if (x_pos == -1)
      return 1;

    std::cout << "Enter y position:";
    std::cin >> y_pos;

    std::cout << std::endl << dd.dungeon_->toString();
    std::cout << std::endl << dd.dungeon_->GetRoom(x_pos, y_pos)->toString();
  }

}

int DungeonTest() {

  Dungeon dun1 = Dungeon(Config::kGridWidth, Config::kGridHeight);

  dun1.GenerateLayout(Config::kGridHeight / 2, Config::kGridWidth / 2);

  std::cout << dun1.toString();

  int x_pos = 1;
  int y_pos = 1;

  while (DO_DEBUGGING) {
    std::cout << "\nEnter x position:";
    std::cin >> x_pos;

    if (x_pos == -1)
      return 1;

    std::cout << "Enter y position:";
    std::cin >> y_pos;

    std::cout << std::endl << dun1.toString();
    std::cout << std::endl << dun1.GetRoom(x_pos, y_pos)->toString();
  }

  return 1;
}

unsigned int hash(unsigned int x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = (x >> 16) ^ x;
  return x;
}