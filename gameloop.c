void gameloop(void)
{
  int input;
  static bullet_t *bullet;

  bullet=initbullet();
  const void *bulletbase = bullet;/*am i sure i understand pointers?*/
  mvprintw(y,x,">");/*shall we see player in the beginning now?*/
  while((input=getch())!='q')
    {
      getmaxyx(stdscr,maxy,maxx);
      switch(input)
	{
	case KEY_UP:
	  playerup();
	  break;
	case KEY_DOWN:
	  playerdown();
	  break;
	case KEY_LEFT:
	  playerleft();
	  break;
	case KEY_RIGHT:
	  playerright();
	  break;
	case ' ':
	  firebullet(bullet);
	  break;
	}
      inertia(bullet);/*has a weird bug...*/
      bulletedgedetect(bullet);
      playeredgedetect();
    }
  freebullets(bullet);
}


