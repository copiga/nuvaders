void inertia(bullet_t *bullet)         
{
  static int i=0;
  mvprintw(10,0,"%d", i);
  i++;
  
    for(;!bullet->last;bullet=bullet->next)
    {
      if(bullet->fired)
	{
	  mvprintw(bullet->y,bullet->x," ");
	  bullet->x+=1;        
	  mvprintw(bullet->y,bullet->x,"-");
	  bullet=nextbullet(bullet);
	}     
    }
}

void bulletedgedetect(bullet_t *bullet)
{
  while(!(bullet->last))
    {
      if(bullet->x>maxx)
	bullet->fired=false;
      bullet=nextbullet(bullet);
    }
}
