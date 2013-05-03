void inertia(bullet_t *bullet)         
{
  static int i=0;
  i++;
  
  for(;!bullet->last;bullet=nextbullet(bullet))
    {
      if(bullet->fired)
	{
	  mvprintw(bullet->y,bullet->x," ");
	  bullet->x+=1;        
	  mvprintw(bullet->y,bullet->x,"-");
	}     
    }
}

void bulletedgedetect(bullet_t *bullet)
{
  while(!(bullet->last))
    {
      if(bullet->x > maxx)
	bullet->fired=false;
      bullet=nextbullet(bullet);
    }
}

void playeredgedetect(void)
{
  if(y>maxy-1)
    {
      playerup();
    }
  if(x>maxx-1)
    {
      playerleft();
    }
  if(x<0)
    {
      playerright();
    }
  if(y<0)
    {
      playerdown();
    }
}
