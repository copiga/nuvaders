void collisiondetect(bullet_t *bullet, enemy_ll *enemy)
{
  bullet_t *bulletbase = bullet;
  /*go through all active enemies, for each enemy go through all fired
    bullets, if bullet x and y == enemy x and y then bullet.fired=false and
    enemy not active, then score++*/
  for(;enemy!=NULL;enemy=nextenemy(enemy))
    {
      if(enemy==NULL)
	break;
      for(bullet=bulletbase;bullet!=NULL;bullet=nextbullet(bullet))
	{
	  if(bullet==NULL)
	    break;
	  if(enemy->onscreen&&bullet->fired)
	    if((bullet->x==enemy->x)&&(bullet->y==enemy->y))
	      {
		mvprintw(bullet->y,bullet->x," ");
		bullet->fired=false;
		enemy->onscreen=false;
		score++;
	      }
	}
    }
}
