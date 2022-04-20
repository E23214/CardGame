//This file is for functions related to manipulating cards. Fucntions Draw, discard, swap, randgen, shuffle, readDeck, and deal are here 
#ifndef cardFun_h
#define cardFun_h

#include "game.h"
#include "print.h"
#include "list.h"
#include "function.h"

void draw(player* p, card** d, card** g){//this function should 
  card* temp;
  int f;
  if(*g == NULL){ // initializes the discard pile as the top card from the deck if no discard pile currently exists
    *g=*d; 
    temp = *d;
    *d = NULL;
    *d = temp->pt;
   
  }
  if(*d == NULL){// 
    printf("You will recieve the top card from the discard pile.");
    printCard(**g);
    p->c[3] = (**g);
    temp = *g;
    free(*g);
    *g= temp->ptt;
  }
  printf("Your current hand is:\n");
  printHand(*p);
  printf("__________________\n Discard:\n");
  
  printCard(**g);
  printf("__________________\n Top of Deck:\n"); //The visual for the back of the card. Not in printCard since its only used here.
  printf(" _____________\n");
  printf("|  _________  |\n");
  printf("| | / / / / | |\n");
  printf("| |/////////| |\n");
  printf("| |/////////| |\n");
  printf("| |/////////| |\n");
  printf("| |/////////| |\n");
  printf("| |/_/_/_/_/| |\n");
  printf("|_____________|\n");
  printf("Would you like to draw from the top of the discard pile or draw from the deck?(1/2)");
  scanf("%d", &f);
  if(f == 2){
    p->c[3] = (**d);
    temp = *d;
    free(*d);
    *d= temp->pt;
  }
  if(f == 1){
    p->c[3] = (**g);
    temp = *g;
    free(*g);
    *g= temp->ptt;
  }
}

void discard(card** h, player* p){ // discards a card and replaces the spot with the 4th card in the players hand
  int g;
  card* temp = (card*)malloc(sizeof(card));
  printf("Pick a card to discard(1/2/3/4)\n");
  printHand(*p); //print hand so player doesnt forget
  scanf("%d",&g);
  /*if((*h) == NULL){ This commented out section would create the head of the discard pile from the first discarded card. Is redundant now since the draw function will create. Worth keeping for testing
    (*h)= (card*)malloc(sizeof(card));
    **h = p->c[g-1];
    p->c[g-1] = p->c[3];
    (*h)->pt = NULL;
    (*h)->ptt = NULL;
  }
  else{*/
    *temp = p->c[g-1];
    p->c[g-1] = p->c[3];
    (*h)->pt = temp;
    temp->ptt = (*h);
    *h= (*h)->pt;
  //}
  p->c[3].value = 0;
  strcpy(p->c[3].suit," ");
}
//The next three functions are for the generating of random cards
void swap(card **pt, int i, int j){// taken from the lab
    card *pt1 = *pt, *pt2 = *pt;
    char x[9];
    while(i>0){
        pt1=pt1->pt; // advance to the ith element
        i--;
    }
    while(j>0){
        pt2 = pt2->pt;  // advance to the jth element
        j--;
    }
    strcpy(x,pt1->suit);
    strcpy(pt1->suit, pt2->suit);
    strcpy(pt2->suit, x);
    i = pt1->value; // swap contents
    pt1->value = pt2->value;
    pt2->value = i;
}
int randgen(void){ //this is taken from the lab
    double frac;
    frac = (double)rand()/((double)RAND_MAX+1); 
    return floor(52*frac); 
}    
void shuffle(card **h){
  int i=0;
  while(i<104){
    i++;
    swap(h, randgen(), i%52);// swaps a random card with the "i"th card in the deck twice
  }
}
void readDeck(FILE* inp, card** h, card** t) {
  card* temp = NULL;
  *h = NULL;
  *t = NULL;
  while(!feof(inp)){
    temp = (card*)malloc(sizeof(card));
    fscanf(inp, "%d", &temp->value);
    fscanf(inp, "%s", temp->suit);
    fscanf(inp, "%*c");
    
   
    if (*h == NULL) {
      temp->pt = NULL;
      temp->ptt = NULL;
      *h = temp;
      *t = temp;
    }
    else {
      if((*h)->pt == NULL){
        (*h)->pt = temp;
        temp->ptt = (*h);
      }
       (*t)->pt= temp;
       temp->ptt = *t;
       *t = temp;
      (*t)->pt = NULL;

    }
    
  }

}
void deal(card** h, player p[]) {
  for(int i = 0; i < 6; i++){
    p[i%2].c[i%3] = (**h);
    (*h) = (*h)->pt;
  }
}
#endif
