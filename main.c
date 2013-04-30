#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "debug.h"
#include "globals.c" /*x,y,maxx,maxy*/
#include "bullets.c" /*bullet related functions*/
#include "gameloop.c"

int main(void)
{
  bullet_t *bullet;
  bullet = initbullet();
  printf("%p", (void*)bullet);
  freebullets(bullet);
  return 0;
}

