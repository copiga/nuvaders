void enemyfire(enemy_ll *enemy)
{
  do
    {
      if(enemy->onscreen)
	if((!enemy->fired)&&(rand()%3==0))
	  {
	    enemy->fired=true;
	    enemy->fire.bulletx=enemy->x-1;
	    enemy->fire.bullety=enemy->y;
	    mvprintw(enemy->fire.bullety, enemy->fire.bulletx, "~");
	  }
    }
  while((enemy=nextenemy(enemy))!=NULL);
}

void enemyfireinertia(enemy_ll *enemy) /*makes enemy shots keep moving forwards*/
{
  do
    {
      if(enemy->fired)
	{
	  mvprintw(enemy->fire.bullety,enemy->fire.bulletx," ");
	  enemy->fire.bulletx--;
	  mvprintw(enemy->fire.bullety, enemy->fire.bulletx, "~");
	}
    }
  while((enemy=nextenemy(enemy))!=NULL);
  
}


