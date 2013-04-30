#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "debug.h"
#include "globals.c" /*x,y,maxx,maxy*/
#include "bullets.c" /*bullet related functions*/
#include "gameloop.c"
#include "physics.c"

int main(void)
{
  initscr();
  raw();
  noecho();
  halfdelay(1);
  keypad(stdscr,true);
  getmaxyx(stdscr,y,x);
  gameloop();
  endwin();
  return 0;
}

