void inertia(bullet_t *bullet)         
{
  while(!(bullet->last))
    {
      mvprintw(bullet->y,bullet->x," ");
      if(bullet->fired)
	bullet->x++;                              /*may be wrong, x is accross right?*/
      bullet=nextbullet(bullet);
      mvprintw(bullet->y,bullet->x,"-");
    }
  
}
