# Dungeon Generator

## Building

To build the project run the command

```make```

Object files are stored in the build directory.

The Dungeon Generator executable, `dgnGen` is stored in the bin directory

## Running


### Debug Mode

Run the command

`dgnGen debug`

This will print the dungeon to the terminal and accept (x,y) coordinates in a loop. The entered room will have its `toString()`method called. This will output the 


#### Sample Run

```dgnGen debug```

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