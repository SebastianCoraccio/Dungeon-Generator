#include <iostream>
#include "dungeon.h"
#include "config.h"

bool DO_DEBUGGING = false;

int DungeonTest();

int main(int argc, char *argv[]) {

  if (argc == 2) {
    if(argv[1])
      DO_DEBUGGING = true;
  }

  unsigned seed = time(0);
  std::cout << "Seed: " << seed << std::endl;
  srand(seed);
  DungeonTest();
}

int DungeonTest() {

  Dungeon dun1 = Dungeon(Config::kGridWidth, Config::kGridHeight);

  dun1.GenerateLayout(Config::kGridWidth / 2, Config::kGridHeight / 2);

  std::cout << dun1.toString();

  int x_pos = 1;
  int y_pos = 1;

  while (DO_DEBUGGING) {
    std::cout << "\nEnter x position:";
    std::cin >> x_pos;

    if(x_pos == -1)
      return 1;

    std::cout << "Enter y position:";
    std::cin >> y_pos;

    std::cout << std::endl << dun1.toString();
    std::cout << std::endl << dun1.GetRoom(x_pos, y_pos)->toString();
  }

  return 1;
}
