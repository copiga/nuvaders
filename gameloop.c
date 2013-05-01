void gameloop(void)
{
  int input;
  static bullet_t *bullet;

  bullet=initbullet();
  const void *bulletbase = bullet;  
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
	case ' ':
	  firebullet(bullet);
	  break;
	}
      inertia(bullet);/*has a weird bug...*/
      bulletedgedetect(bullet);
    }
  freebullets(bullet);
}


