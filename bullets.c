void* initbullet(void)                           /*returns the address of the first element in the linked list of width BULLET_MAX*/
{
  bullet_t *bullet;
  void *firstbullet;
  int i;
  
  
  bullet = malloc(sizeof(bullet_t));
  firstbullet=bullet;
  
  for(i=0;i<maxx;i++)
    {
      bullet->next = malloc(sizeof(bullet_t));
      bullet->fired=false;
      bullet->last=false;
      bullet=bullet->next;
      DEBUG_PRINT("%d\n", i);
    }
  bullet->last=true;
  return firstbullet;
}


void* nextusablebullet(bullet_t *bullet)      /*gives address of the next usable bullet*/
{
  for(;bullet->fired;bullet=nextbullet(bullet));
  return bullet;
}

void* nextbullet(bullet_t *bullet)           /*a tad un-needed but it might make things easier to understand... maybe... i hope...*/
{
  bullet = bullet->next;
  return bullet;
}

void* nextfiredbullet(bullet_t *bullet)                       /*may need some tweaking*/
{
  bullet=nextbullet(bullet);
  for(;!bullet->fired;bullet=nextbullet(bullet));
  return bullet;
}
  
void freebullets(bullet_t *bullet)            /*deallocate all of the bullets, i do not know iif this works, nor do i know how to test it...*/
{
  bullet_t *first;
  first = bullet;
  while(first->next!=NULL)
    {
      while(!(bullet->next->last))
	{
	  bullet=nextbullet(bullet);
	}
      free(bullet->next);
      bullet->last=true;
      bullet->next=NULL;
      bullet=first;
    }
  free(bullet);
}

void firebullet(bullet_t *bullet)
{
  bullet = nextusablebullet(bullet);
  bullet->fired = true;
  bullet->x = x+1;           
  bullet->y = y;
  mvprintw(bullet->y,bullet->x,"-");
}


