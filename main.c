#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "bulletdef.h"
#include "prototypes.h"
#include "debug.h"
#include "globals.c" /*x,y,maxx,maxy*/
#include "bullets.c" /*bullet related functions*/
#include "gameloop.c"
#include "physics.c"
#include "player.c"
#include "enemies.c"

int main(void)
{
  initscr();
  raw();
  noecho();
  halfdelay(1);
  keypad(stdscr,true);
  getmaxyx(stdscr,maxy,maxx);
  y=maxy/2;
  x=maxx/4;
  curs_set(0);
  gameloop();
  endwin();
  return 0;
}

