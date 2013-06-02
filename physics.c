void inertia(bullet_t *bullet)         
{
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

void enemyedgedetect(enemy_ll *enemy)
{
  for(;!enemy->last;enemy=nextenemy(enemy))
    if(enemy->onscreen)
      if((enemy->x<0)||(enemy->x>maxx)||(enemy->y<0)||(enemy->y>maxy))
	{
	  mvprintw(enemy->y,enemy->x," ");
	  enemy->onscreen=false;
	}
}

void enemybulletedgedetect(enemy_ll *enemy)
{
  mvprintw(4,4,"x");
  static int debug;
  if(!(debug>0))
    debug=1;
  for(;!enemy->last;enemy=nextenemy(enemy))
    if(enemy->fired)
      if((enemy->fire.bulletx<0)||(enemy->fire.bulletx>maxx))
	{
	  debug=debug+1;
	  mvprintw(3,3,"%d", debug);
	  enemy->fired=false;
	}
}
