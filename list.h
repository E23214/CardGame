//File for structs
#ifndef struct_h
#define struct_h

typedef struct card_s{
  char suit[9];
  int value;
  struct card_s *pt;
  struct card_s *ptt;
} card;

typedef struct player_s{
  int money;
  char s;
  card c[4];
} player;

typedef struct stats_s{
  int games;
  int won[2];
  int score[31];
}stats;
 
#endif