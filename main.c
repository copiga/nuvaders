#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bulletdef.h"
#include "prototypes.h"
#include "debug.h"
#include "globals.c" /*x,y,maxx,maxy*/
#include "bullets.c" /*bullet related functions*/
#include "gameloop.c"
#include "physics.c"
#include "player.c"

int main(void)
{
  initscr();
  raw();
  noecho();
  halfdelay(10);
  keypad(stdscr,true);
  getmaxyx(stdscr,maxy,maxx);
  y=maxy/2;
  x=maxx/4;
  gameloop();
  endwin();
  return 0;
}

