typedef enum enemytype_e
  {
    hash,
    at,
    mirroryou
  }
  enemytype_e;

struct enemyfireinfo
{
    int bulletx;
    int bullety;
}
  enemyfireinfo;

typedef struct enemy_ll
{
  enemytype_e type;
  char sprite;
  int x;
  int y;
  bool last;
  bool fired;
  struct enemyfireinfo fire;
  bool onscreen;
  struct enemy_ll *next;
}
  enemy_ll;
