#define BULLET_MAX 200

typedef struct bullet_t
{
  int x;
  int y;
  bool fired;
  bool last;
  struct bullet_t *next;
}
  bullet_t;

void* initbullet(void)                           /*returns the address of the first element in the linked list of width BULLET_MAX*/
{
  bullet_t *bullet;
  void *firstbullet;
  int i;
  
  
  bullet = malloc(sizeof(bullet_t));
  firstbullet=bullet;
  
  for(i=0;i<BULLET_MAX;i++)
    {
      bullet->next = malloc(sizeof(bullet_t));
      bullet->fired=false;
      bullet->last=false;
      bullet=bullet->next;
      printf("%d\n", i);
    }
  bullet->last=true;
  return firstbullet;
}


void* nextusablebullet(bullet_t *bullet)
{
  while(!(bullet->last))
    for(;bullet->fired;bullet=bullet->next);
  return bullet;
}

void* nextbullet(bullet_t *bullet)
{
  bullet = bullet->next;
  return bullet;
}
  
void inertia(bullet_t *bullet)
{
  while(!(bullet->last))
    {
      bullet->x++;
      bullet=nextbullet(bullet);
    }
  bullet->x++;
}

void freebullets(bullet_t *bullet)
{
  bullet_t *first;
  first = bullet;
  while(first->next!=NULL)
    {
      while(!(bullet->next->last))
	{
	  bullet=bullet->next;
	}
      free(bullet->next);
      bullet->last=true;
      bullet->next=NULL;
      bullet=first;
    }
  free(bullet);
}
