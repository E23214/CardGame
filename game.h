//File for functions related to the state of the game
#ifndef game_h
#define game_h
#include "cardFun.h"
#include "print.h"
#include "list.h"
#include "function.h"

void dividePot(int numPlayers, player play[], int pot, stats* ga) {
  int i;
  int max = 0;
  int winners = 0;
  int playMax[numPlayers];
  for (i = 0; i < numPlayers; i++) {
    playMax[i] = 0;
  }
  for(i = 0; i < numPlayers; i++){//find max
    if(handValue(play[i]) >= max && play[i].s == 'i'){
      max = handValue(play[i]);
    }
  }
  for (i = 0; i < numPlayers; i++) {//add winner indexes to playMax
   if(max == handValue(play[i]) && play[i].s == 'i'){
    playMax[i] = 1;
    winners++;
   }
  }
  for (i = 0; i < numPlayers; i++) {//divies up the pot
    if (playMax[i] != 0) {
      play[i].money += (pot / winners);
      printf("Player %d's money: %d\n", i+1, play[i].money);
      printf("Player %d's money: %d\n", ((i+1)%2)+1, play[(i+1)%2].money);
      ga->won[i]+=1;// updates who won a round
    }
  }
  ga->score[max]+=1;//updates the score of the hand that won the round
}

int handValue(player p) {
  int i;
  int suit[4] = {0,0,0,0}; //0 = spades, 1 = hearts, 2 = diamonds, 3 = clubs
  int value = 0;

  if (p.c[0].value == p.c[1].value && p.c[1].value == p.c[2].value) {
    value = 30;
  }
  else {
    for (i = 0; i < 3; ++i) {
      if (strcmp(p.c[i].suit, "Spades") == 0){
        if(p.c[i].value < 10 && p.c[i].value > 1){
          suit[0]+= p.c[i].value;
        }
        else if(p.c[i].value >= 10){
          suit[0]+= 10;
        }
        else{
          suit[0]+=11;
        }
      }
      if (strcmp(p.c[i].suit, "Diamonds") == 0){
        if(p.c[i].value < 10 && p.c[i].value > 1){
          suit[2]+= p.c[i].value;
        }
        else if(p.c[i].value >= 10){
          suit[2]+= 10;
        }
        else{
          suit[2]+=11;
        }
      }
      if (strcmp(p.c[i].suit, "Hearts") == 0){
        if(p.c[i].value < 10 && p.c[i].value > 1){
          suit[1]+= p.c[i].value;
        }
        else if(p.c[i].value >= 10){
          suit[1]+= 10;
        }
        else if(p.c[i].value == 1){
          suit[1]+=11;
        }
      }
     if (strcmp(p.c[i].suit, "Clubs") == 0){
        if(p.c[i].value < 10 && p.c[i].value > 1){
          suit[3]+= p.c[i].value;
        }
        else if(p.c[i].value >= 10){
          suit[3]+= 10;
        }
        else{
          suit[3]+=11;
        }
      }
    }
  }
    for(i = 0; i < 4; ++i) {
      if (suit[i] > value) {
        value = suit[i];
      }
    }
  return value;
}
int games(player p[]){
  int i;
  for(i = 0; i < 2; i++){
    if(p[i].s == 'f'){
      return i+1;
    }
    if(handValue(p[i]) == 31){
      return i + 1;
    }
  }
  return 0;
}
int match(player p[], int numP){//checks if players still have money. NumP relic holdover from our desire to add multiple players
  for(int i=0; i < numP; i++){
    if(p[i].money == 0){
      return (((i+1)%2)+1);
    }
  }
return 0;
}
int bet(player p[], int t, int pot){
  int bet[2] = {0,0};
  char rc; // checks what the player wants to do. raise, call, fold, or go all in if previous bet is over the money in their account
  int i = t;
  printf("Player %d would you like to bet or fold (b/f):\n", i+1);
  scanf("%*c");
  scanf("%c", &rc);
  if (rc == 'f') {
    p[i].s = 'f';
    printf("Player %d has folded\n", i + 1);
  }
  else {
    printf("Player %d enter your (non-zero) bet:\n", i+1);
    scanf("%d", &bet[i]);
    while(bet[i] == 0){
      printf("Okay, very funny. Enter a non-zero bet:\n");
      scanf("%d", &bet[i]);
    }
    while(p[i].money < 0){
      p[i].money = p[i].money + bet[i];
      printf("You have $%d, you can't bet over that amount", p[i].money);
      printf("\n How much do you want to bet?");
      scanf("%d", &bet[i]);
    }
      i+=1;
      i=i%2;
      if(bet[((i+1)%2)] >= p[i].money){
        printf("All in or fold? (a/f)");
        scanf("%*c");
        scanf("%c", &rc);
      }
      else{
        printf("Player %d raise, call, or fold? (r/c/f): \n", i + 1);
        scanf("%*c");
        scanf("%c", &rc);
        if(rc == 'r') {
           printf("Player %d enter your new bet (greater than %d):\n", i+1, bet[(i+1)%2]);
            scanf("%d", &bet[i]);
          while(p[i].money < bet[i] || bet[i] <= bet[(i+1)%2]){ // protecting player from betting over their money or not raising
            if(p[i].money < bet[i]){
              printf("You have $%d, you can't bet over that amount", p[i].money);
              printf("\n How much do you want to raise by?");
             scanf("%d", &bet[i]);
            }
            if(bet[i] <= bet[(i+1)%2]){
              printf("Okay, very funny. Enter a greater bet:\n");
              scanf("%d", &bet[i]);
            }
          }
        }
      }
      if(rc == 'c'){
        bet[i] = bet[(i+1)%2];
      }
      if (rc == 'f') {
        p[i].s = 'f';
      }
      if(rc == 'a'){
        bet[i] = p[i].money;
      }
 
    while(bet[1] != bet[0] && rc != 'a' && p[i].s != 'f'){  
      i+=1;
      i=i%2;
      printf("Player %d call, or fold? (c/f): \n", i + 1);
      scanf("%*c");
      scanf("%c", &rc);
      if(rc == 'c'){
        if(i == 1){
          bet[i] = bet[i-1];
        }
        if(i == 0){
          bet[i] = bet[i + 1];
        }
        
      }
      if (rc == 'f') {
        p[i].s = 'f';
      }
    }
    p[1].money = p[1].money - bet[1];
    p[0].money = p[0].money - bet[0];
    pot += (bet[1] + bet[0]);
    printf("Pot:%d\n", pot);//here to check for bugs and useful for the player to have
  }
  return pot;
}
stats initStats(stats g){// initailizes the stats to zero and returns the variable
  for(int i =0; i <31; i++){
    g.score[i] = 0;
  }
  g.won[0] = 0;
  g.won[1] = 1;

  g.games = 0;

  return g;
}
#endif