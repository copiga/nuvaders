void gameloop(void)
{
  int input;
  bullet_t *bullet;
  bullet=initbullet();
  
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
      inertia(bullet);
      
    }
  freebullets(bullet);
  
}


