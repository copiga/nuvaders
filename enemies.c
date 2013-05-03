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

