#include <iostream>
#include "dungeon.h"
#include "dungeon_drawer.h"
#include "config.h"

bool DO_DEBUGGING = false;

int DungeonTest();
unsigned int hash(unsigned int x);

int main(int argc, char *argv[]) {

  if (argc >= 2) 
    DO_DEBUGGING = true;

  unsigned seed = time(0);
  seed = hash(seed);
  std::cout << "Seed: " << seed << std::endl;
  srand(seed);
  for(int i = 0; i < 10000; i++){
    rand();
  }

  Dungeon dun = Dungeon(Config::kGridWidth, Config::kGridHeight);

  dun.GenerateLayout(Config::kGridHeight / 2, Config::kGridWidth / 2);

  DungeonDrawer dd = DungeonDrawer(&dun);
  dd.PrintToFile();
  
  std::cout << std::endl << dun.toString();

  int x_pos = 1;
  int y_pos = 1;

  while (DO_DEBUGGING) {
    std::cout << "\nEnter x position: ";
    std::cin >> x_pos;

    if (x_pos == -1)
      return 1;

    if (x_pos >= Config::kGridHeight || x_pos < 0) {
      std::cerr << "Given X value must be 0 or greater " <<
                "and less than the grid's width.\n";
      continue;
    }
    
    std::cout << "Enter y position: ";
    std::cin >> y_pos;

    if (y_pos >= Config::kGridWidth || y_pos < 0) {
      std::cerr << "Given Y value must be 0 or greater " <<
                "and less than the grid's height.\n";
      continue;
    }

    std::cout << std::endl << dun.toString();
    
    Room* r = dun.GetRoom(x_pos, y_pos);
    if(r != nullptr)
      std::cout << std::endl << dun.GetRoom(x_pos, y_pos)->toString();
    else
      std::cout << std::endl << "No room at (" << x_pos << ", " << y_pos << ")" << std::endl;
      
  }

}

unsigned int hash(unsigned int x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = (x >> 16) ^ x;
  return x;
}