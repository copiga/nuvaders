#define ENEMY_MAX 200


void* initenemies(void)
{
  void *first;
  enemy_ll *enemy;
  int i;

  enemy=malloc(sizeof(enemy_ll));

  first = enemy;
  for(i=0;i<ENEMY_MAX;i++)
    {
      enemy->next=malloc(sizeof(enemy_ll));
      enemy->last = false;
      enemy->onscreen = false;
      enemy=enemy->next;
    }
  enemy->last=true;
  return first;
}

void* nextenemy(enemy_ll *enemy)
{
  return enemy->next;
}

void* nextusableenemy(enemy_ll *enemy)
{
  for(;enemy->onscreen;enemy=nextenemy(enemy));
  return enemy;
}

void freeenemies(enemy_ll *enemy)
{
  enemy_ll *first;
  first = enemy;
  while(first->next!=NULL)
    {
      while(!(enemy->next->last))
	{
	  enemy=nextenemy(enemy);
	}
      free(enemy->next);
      enemy->last=true;
      enemy->next=NULL;
      enemy=first;
    }
  free(enemy);
}

void spawnenemy(enemy_ll *enemy)
{
  if(rand()%2==0)                                           /*some likelyish condition would be good*/
    {
      enemy = nextusableenemy(enemy);
      enemy->type=hash;
      enemy->sprite='#';
      enemy->x=(rand()%(maxx/2));
      enemy->y=rand()%maxy;
      enemy->onscreen=true;
      mvprintw(enemy->y,enemy->x,"%c",enemy->sprite);
    }
}

