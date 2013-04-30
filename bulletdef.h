typedef struct bullet_t
{
  int x;
  int y;
  bool fired;
  bool last;
  struct bullet_t *next;
}
  bullet_t;
