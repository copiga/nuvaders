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
