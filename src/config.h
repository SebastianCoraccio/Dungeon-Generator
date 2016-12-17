#ifndef DGNGEN_CONFIG_H
#define DGNGEN_CONFIG_H

class Config {

  public:

  // The width and height of the dungeon grid
  constexpr static int kGridWidth = 50;
  constexpr static int kGridHeight = 50;

  // A start room will have this branch chance on all four directions
  constexpr static double kStartBranchChance = 0.85;

  // When a new room is branched, the new rooms chance to branch is reduced by
  // this amount
  constexpr static double kHallwayChanceDecay = 0.05;
  constexpr static double kJunctionChanceDecay = 0.05;

  // When a junction is created it has 0-3 room exits. Each direction has a
  // random chance to have a non-zero chance to branch
  constexpr static double kJunctionExitChance = 0.85;

  // When a room branches there is a chance that rather than creating a hallway
  // a junction will be created
  constexpr static double kCreateJunction = 0.16;



};

#endif //DGNGEN_CONFIG_H
