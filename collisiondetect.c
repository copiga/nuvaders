void collisiondetect(bullet_t *bullet, enemy_ll *enemy)
{
  bullet_t *bulletbase = bullet;
  enemy_ll *enemybase = enemy;
  /*go through all active enemies, for each enemy go through all fired
    bullets, if bullet x and y == enemy x and y then bullet.fired=false and
    enemy not active, then score++*/
  for(;enemy!=NULL;enemy=nextenemy(enemy))
    {
      if(enemy==NULL||!enemy->onscreen)
	continue;
      for(bullet=bulletbase;bullet!=NULL&&bullet->fired;bullet=nextbullet(bullet))
	{
	  if(bullet==NULL)
	    continue;
	  if((bullet->x==enemy->x))
	    if((bullet->y==enemy->y))
		{
		  mvprintw(bullet->y,bullet->x," ");
		  bullet->fired=false;
		  enemy->onscreen=false;
		  score++;
		}
	  if(bullet->x==enemy->fire.bulletx)
	    if(bullet->y==enemy->fire.bullety)
	      {
		mvprintw(bullet->y,bullet->x," ");
		bullet->fired=false;
		enemy->fired=false;
		score+=2;
	      }
	  
	}
      if(enemy->fire.bulletx==x)
	if(enemy->fire.bullety==y)
	  lives--;
    }
}
