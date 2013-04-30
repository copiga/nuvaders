#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bullets.c"


int main(void)
{
  bullet_t *bullet;
  bullet = initbullet();
  printf("%p", (void*)bullet);
  freebullets(bullet);
  
  return 0;
}

