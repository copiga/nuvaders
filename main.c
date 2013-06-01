#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>

#include "bulletdef.h"
#include "enemydef.h"
#include "prototypes.h"
#include "debug.h"
#include "globals.c" /*x,y,maxx,maxy*/
#include "bullets.c" /*bullet related functions*/
#include "gameloop.c"
#include "physics.c"
#include "player.c"
#include "enemies.c"
#include "collisiondetect.c"
#include "enemyfire.c"

void cleanexit(int signal)
{
  endwin();
  exit(0);
}


int main(void)
{
    int score;
    
    signal(SIGINT, cleanexit);
  
    initscr();
    raw();
    noecho();
    halfdelay(1);    //    nodelay(stdscr,true);//  halfdelay(1);
    keypad(stdscr,true);
    getmaxyx(stdscr,maxy,maxx);
    y=maxy/2;
    x=maxx/4;
    score=0;
    curs_set(0);
    score=gameloop();
    endwin();
    scoreadd(score);
    return 0;
}

void scoreadd(int score)
{
  char name[50];
  FILE *scorefile;
  puts("please enter your name");
  scanf(" %s", name);
  scorefile = fopen("nuvaders scores", "a");
  fprintf(scorefile, "%s\t\t%d\t%d\n", name, score, lives);
  fclose(scorefile);
}
