#ifndef function_h
#define function_h

void readDeck(FILE* inp, card** h, card** t);// reads the deck from a file and creates a linked list.In cardFun.h
int randgen(void);//uses the code from  lab as a way to generate a rand int. In cardFun.h
void swap(card **pt, int i, int j);// uses lab code to swap two values in a pointed list In cardFun.h
void shuffle(card **h);// combines the above two functions to shuffle deck. In cardFun.h
void deal(card** h, player p[]);// Deals 3 card to each player. In cardFun.h
void discard(card** h, player* p);//Need to change this so it start with the top card from the deck instead of with nothing. In cardFun.h
void draw(player* p, card** d, card** g);//lets user pick from discard or the top of the deck. d is discard, g is deckH. In cardFun.h

int bet(player p[], int t, int pot);// FIXME need to change it so it only has one round of raising. Player p is the player array and int t is to input whos turn it is. In game.h
int handValue(player p);//returns value of hand. In game.h
int match(player p[], int numP);//chekcs if both players have money. In game.h
int games(player p[]);//This currently doesnt work at all, but shoudlnt be hard. In game.h
void dividePot(int numPlayers, player play[], int pot, stats* ga);// divides the pot among the winning players. In game.h
stats initStats(stats g);// initializes the arrays in the stats variable to zero to properly track score. In game.h


void printCard(card c);//prints a single card in ascii. In print.h
void printHand(player p);// just has a for loop using print card to iterate through players hand. Using the printCard function. The two are seperate as printcard occasionaly has independent functioanlity. In print.h


#endif