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
      inertia(bullet);/*makes bullets keep moving*/
      bulletedgedetect(bullet);/*stops bullets from leaving screen*/
      playeredgedetect();/*keeps player on screen*/
    }
  freebullets(bullet);
}


