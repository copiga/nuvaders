void playerup(void)
{
  mvprintw(y,x," ");
  y--;
  mvprintw(y,x,">");
}

void playerdown(void)
{
  mvprintw(y,x," ");
  y++;
  mvprintw(y,x,">");
}

