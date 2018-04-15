# Dungeon Generator

This project creates grid-based dungeon layouts using the `Dungeon` class. Each dungeon begins in a start room and then branches off into junctions, hallways, and long hallways. The room furthest from the start room is a boss room. The layout is configured with different customizable probabilities. Different room types branch and creation changes are defined in `config.h`. 

The dungeon class can be moved into a new project for other uses. The `main.cc` file simply provides a wrapper to demonstrate, interact, and test the `Dungeon` class.

Below are some sample representations of dungeons and instructions to run this application.

**Key**
```
S - Start room
J - Junction
H - Hallway
L - Long hallway (Two adjacent hallways, represents a long room)
B - Boss Room


 . . . . . . . . . . . . 
 . . . . H . . . . . . . 
 . . . . H . . . . . . . 
 . . . . H . . . . . . . 
 . H H H S H L L H H H . 
 . . . . H . . . . . . .
 . . . . H . . . . . . .
 . . . . J J H . . . . .
 . . . . . H . . . . . .
 . . . . . B . . . . . .
 . . . . . . . . . . . .

 . . . . . . . . . .
 . . H H . . . . . .
 . . J J H J . . . .
 . . H . . . . . . .
 . . J H . . . . B .
 . . H . . . . . L .
 . . H . . . . . L .
 . H S H H L L H J .
 . . H . . . . . J .
 . . J H H . . . H . 
 . . H . . . . . . .
 . . H . . . . . . .
 . . J L L H . . . .
 . . . . . . . . . .

```
## Building

To build the project run the command

```make```

Object files are stored in the build directory.

The Dungeon Generator executable, `dgnGen` is stored in the bin directory

To adjust the room creation chances see file `config.h`. Room creation and branching probabilties are defined there.

## Running

Run the command 

`dgnGen`

This will create a dungeon and print the grid representation. 

### Debug Mode

Run the command

`dgnGen debug`

This will print the dungeon to the terminal and accept (x,y) coordinates in a loop. If the entered coordinates have a room it will have its `toString()` method called. This will output the name of the room type along with which of its walls have doors.


#### Sample Run

`dgnGen debug`

```bash
Enter x position:6
Enter y position:14

   0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2
   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3
00 . . . . . . . H . . . . . . H . . . . . . . . .
01 . . . . . . . J J H H H J B H . . . . . . . . .
02 . . . . . . . L L . . . . . H . . . . . . . . .
03 . . . . . . . L L . . . . . J H H . . . . . . .
04 . . . . . . . H . . . . . . H . . . . . . . . .
05 . . . . . . . H . . . . H . H . . . . . . . . .
06 . . . . . . . J H L L H S H J L L . . . . . . .
07 . . . . . . . H . . . . J H H H H L L H . . . .
08 . . . . . . . H . . . . J H . . . . . . . . . .
09 . . . . . . . J H . . . H . . . . . . . . . . .
10 . . . . . . . H . . . . H . . . . . . . . . . .
11 . . . . . . . . . . . . . . . . . . . . . . . .

Junction(x: 6, y: 14) Has doors:{
  North
  East
  West
}
```

To exit debug mode enter `-1` when prompted for the x position (or ctrl+c).

**Note:** Dungeons with width or height higher than 100 will have visual errors with the indexes. They are written to only go up to 99. 

## Dungeon Drawer

A small utility class is included with the project that can be used to output the generated dungeon as a PNG. The class can generate its own dungeon or takes a reference to an already created one. 

### Samples


