void gameloop(void)
{
  int input;
  
  while((input=getch())!=27)
    {
      getmaxyx(stdscr,y,x);
      mvprintw(12,12,"%d,%d", y,x);
    }
}

