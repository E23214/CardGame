//Code by Elliot Hagyard and Edward Navarro 
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
  int numPlayers = 2;// artifact from when the plan was to have more than 1 player.
  player play[numPlayers];//code only works for two players, but we were planning of more. Didnt exactly pan out
  play[0].money =100;//So, replit doesnt allow for int money = 100; in the struct, so these two lines are here for that reason
  play[1].money = 100;
  char gs = 'c';// gs stands for Game State. Modified by players "knocking" when they are good with their hands
  int g = 0; //just a random variable to hold whether you want a pre set deck or not.
  int turn = 0;// tracks the number of games passed in order to decide who is dealing that round
  int pot;
  stats game;
  game = initStats(game); //initsStats returns an initialized version of game with every value in the arrays equal to zero
  card *deckH = NULL;// head pointer for the deck
  card *deckT = NULL;// tail pointer for the deck
  card *discardC = NULL; // head pointer for the discard pile
  FILE* read;
  

  read = fopen("../deck.txt", "r");
  //while(match(play) == 0){

  
  do {
    game.games++;
    printf("Game %d\n", game.games);
    play[1].s = 'i';
    play[0].s = 'i';// .s is to check if a player has folded or not. Placed at the begining of this loop to reset folded players between games
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
      printf("Player %d's hand\n", c+1);
      printf("____________\n");
      printHand(play[c]);
      printf("____________\n");
    }
   

    while(games(play) == 0 && gs == 'c' && match(play, numPlayers)==0){

      i=(0 + turn)%numPlayers;//i keeps track of whose turn it is. Turn alternates the turn, incrementing each loop of the match function
      pot = bet(play, i, pot);
      do{
        if(games(play) == 0){
          printf("Player %d your turn\n", i+1);
          draw(&play[i], &deckH ,&discardC);
          discard(&discardC, &play[i]);
          printHand(play[i]);
          printf("____________\n");
          printf("Hand Value: %d\n", handValue(play[i]));
          if(match(play, numPlayers) == 0){//doesnt ask players to knock if one has gone all in 
            printf("Are you happy with your hand? (Knock) Or do you want to keep going?(k/c)\n");
            scanf("%*c");
            scanf("%c", &gs);
          }
        }
        i++;
      }while(i < numPlayers && gs == 'c');
      if(gs != 'c'){
          i = i%2;
          printHand(play[i]);
          printf("Player %d draw and discard your final cards\n", i+1);
          draw(&play[i], &deckH ,&discardC);
          discard(&discardC, &play[i]);
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
 printf("Stats:\nNumber of games: %d\nPlayer 1's winning percentage:%.1f%%\nPlayer 2's winning percentage: %.1f%%\n", game.games,100*(float)(game.won[0])/((float)(game.won[0]+game.won[1])),100*(float)(game.won[1])/((float)(game.won[0]+game.won[1])));
  for(i = 0; i < 31; i++){
    if (game.score[i] != 0) {
      printf("Percent of games won at a score of %2d: %.1f%%\n", i , 100*(((float)(game.score[i])/((float)(game.games)))));
    }
  }
  fclose(read);
  return 0;
}

