#define ENEMY_MAX 200

typedef enum enemytype_e
  {
    hash,
    at,
    mirroryou
  }
  enemytype_e;

typedef struct enemy_ll
{
  enemytype_e type;
  char sprite;
  int x;
  int y;
  bool last;
  bool onscreen;
  struct enemy_ll *next;
}
  enemy_ll;

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
  for(;enemy->onscreen;enemy=nextenemy);
  return enemy;
}

void freeenemies(enemy_ll *enemy)            /*deallocate all of the bullets, i do not know iif this works, nor do i know how to test it...*/
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
