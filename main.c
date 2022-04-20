#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#include "list.h" //File for Struct declarations
#include "function.h" //File to initialize different functions and more specific description of fucntions & location of function
#include "cardFun.h"//File for card related functions
#include "game.h" // File for game related functions
#include "print.h"//File for functions related to rpinting cards

int main(void){
  srand(time(NULL)); // set the rand seed equal to time at the start
  int i;// i is repeatedly used to count so initialized here
  int numPlayers = 2;// artifact from when the plan was to have more than 1 player
  player play[numPlayers];//code only works for two players, but we were planning of more. Didnt exactly pan out
  char gs = 'c';// gs stands for Game State. Modified by players "knocking" when they are good with their hands
  int g = 0; //just a random variable to hold whether you want a pre set deck or not.
  int turn = 0;// tracks the number of rounds passed in order to decide who is dealing that round
  int pot;
  stats game;
  game = initStats(game);
  // max hand value value, number of winners
  card *deckH = NULL;// head pointer for the deck
  card *deckT = NULL;// tail pointer for the deck
  card *discardC = NULL; // head pointer for the discard pile
  FILE* read;
  

  read = fopen("deck.txt", "r");
  //while(match(play) == 0){

  
  do {
    game.rounds++;
    i=(0 + turn)%numPlayers;
    play[1].s = 'i';
    play[0].s = 'i';// .s is to check if a player has folded or not. Placed at the begining of this loop to reset folded players between rounds
    pot = 0;
    gs = 'c';
    printf("Do you want to play with a preset deck, or a shuffled deck?(1/2)");
    scanf("%d",&g);
    if(g == 1){
      rewind(read);// rewinds redundantly on the first itteration, but at the same time works
      readDeck(read, &deckH, &deckT);
    }
    if(g == 2){
      rewind(read);
      readDeck(read, &deckH, &deckT);
      shuffle(&deckH);
    }
    deal(&deckH, play);
    for(int c = 0; c < numPlayers; c++){
      printHand(play[c]);
    }while(games(play) == 0 && gs == 'c' && match(play, numPlayers)==0){

      i=(0 + turn)%numPlayers;//i keeps track of whose turn it is. Turn alternates the turn, incrementing each loop of the match function
      pot = bet(play, i, pot);
      printf("Pot: %d\n", pot);
      do{
        if(games(play) == 0){
          printf("Player %d your turn\n", i+1);
          draw(&play[i], &deckH ,&discardC);
          discard(&discardC, &play[i]);
          printHand(play[i]);
          printf("Hand Value: %d\n", handValue(play[i]));
          printf("Are you happy with your hand? Or do you want to keep going?(k/c)");
          scanf("%*c");
          scanf("%c", &gs);
        }
        i++;
      }while(i < numPlayers && gs == 'c');
      if(gs != 'c'){
        for(i = 0; i < numPlayers-1; i++){
          printHand(play[i]);
          printf("Player %d draw and discard your final cards\n", i+1);
          draw(&play[i], &deckH ,&discardC);
          discard(&discardC, &play[i]);
        }
      }
    }
    printHand(play[0]);
    printf("Player %d hand value: %d\n", 1, handValue(play[0]));
    printHand(play[1]);
    printf("Player %d hand value: %d\n", 2, handValue(play[1]));
    dividePot(numPlayers, play, pot, &game);
    turn++;// this varaible increments to change whose turn it is
    g = 2;
  } while(match(play, numPlayers) == 0);// should check if players still have money in their bank
  printf("Player %d won!\n", match(play, numPlayers));
  printf("Stats:\nNumber of games: %d\nPlayer 1's winning percentage:%%%.1f \t Player 2's winning percentage: %%%.1f", game.rounds,100*float(game.won[0])/(float(game.won[0]+game.won[1])),100*float(game.won[1])/(float(game.won[0]+game.won[1])));
  for(i = 0; i < 31; i++){
    printf("Percent of games won at %2d score: %%%.1f\n", i , 100*((float(game.score[i])/(float(game.rounds)))));
  }
  fclose(read);
  return 0;
}

