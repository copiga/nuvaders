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

void playerright(void)
{
  mvprintw(y,x," ");
  x++;
  mvprintw(y,x,">");
}

void playerleft(void)
{
  mvprintw(y,x," ");
  x--;
  mvprintw(y,x,">");
}
