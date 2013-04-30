void inertia(bullet_t *bullet)                /*TODO: move this into its own file, it isnt just for bullets*/
{
  while(!(bullet->last))
    {
      if(bullet->fired)
	bullet->x++;                              /*may be wrong, x is accross right?*/
      bullet=nextbullet(bullet);
    }
  bullet->x++;
}
