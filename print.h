//Functions with ASCII art for printing cards. printDeck was created to test the initialization of the deck. printCard is the generalized version for any card. Print Hand is in here as well. just a for loop used to print the hand of a player.
#ifndef print_h
#define print_h
#include "list.h"
#include "function.h"



void printCard(card c) {
     switch(c.value){
      case 1:
        if(strcmp((c.suit), "Diamonds")==0){
          printf(" _____________\n");
          printf("|             |\n");
          printf("| A           |\n");
          printf("|             |\n");
          printf("|     /\\      |\n");
          printf("|     \\/      |\n");
          printf("|             |\n");
          printf("|           A |\n");
          printf("|_____________|\n");
        }
      if(strcmp((c.suit), "Spades")==0){ 
           printf(" _____________\n");
          printf("|             |\n");
          printf("| A           |\n");
          printf("|             |\n");
          printf("|     /\\      |\n");
          printf("|    (__)     |\n");
          printf("|             |\n");
          printf("|           A |\n");
          printf("|_____________|\n");
      }
       if(strcmp((c.suit), "Hearts")==0){
            printf(" _____________\n");
          printf("|             |\n");
          printf("| A           |\n");
          printf("|             |\n");
          printf("|     (\\/)    |\n");
          printf("|      \\/     |\n");
          printf("|             |\n");
          printf("|           A |\n");
          printf("|_____________|\n");
       }
       if(strcmp((c.suit), "Clubs")==0){
           printf(" _____________\n");
          printf("|             |\n");
          printf("| A           |\n");
          printf("|             |\n");
          printf("|      *      |\n");
          printf("|     *|*     |\n");
          printf("|             |\n");
          printf("|           A |\n");
          printf("|_____________|\n");
        }
      break;
      case 2:
        if(strcmp((c.suit), "Diamonds")==0){ 
          printf(" _____________\n");
          printf("|             |\n");
          printf("| 2           |\n");
          printf("|             |\n");
          printf("|   /\\ /\\     |\n");
          printf("|   \\/ \\/     |\n");
          printf("|             |\n");
          printf("|           2 |\n");
          printf("|_____________|\n");
        

        }
         if(strcmp((c.suit), "Spades")==0){ 
          printf(" _____________\n");
          printf("|             |\n");
          printf("| 2           |\n");
          printf("|             |\n");
          printf("|   /\\  /\\    |\n");
          printf("|  (__)(__)   |\n");
          printf("|             |\n");
          printf("|           2 |\n");
          printf("|_____________|\n");
         }
         if(strcmp((c.suit), "Clubs")==0){      
          printf(" _____________\n");
          printf("|             |\n");
          printf("| 2           |\n");
          printf("|             |\n");
          printf("|   *    *    |\n");
          printf("|  *|*  *|*   |\n");
          printf("|             |\n");
          printf("|           2 |\n");
          printf("|_____________|\n");
         }
         if(strcmp((c.suit), "Hearts")==0){
          printf(" _____________\n");
          printf("|             |\n");
          printf("| 2           |\n");
          printf("|             |\n");
          printf("|   (\\/)(\\/)  |\n");
          printf("|    \\/  \\/   |\n");
          printf("|             |\n");
          printf("|           2 |\n");
          printf("|_____________|\n");
         }
         break;
    case 3:
       if(strcmp((c.suit), "Diamonds")==0){ 
         printf(" _____________\n");
         printf("|             |\n");
         printf("| 3           |\n");
         printf("|   /\\  /\\    |\n");
         printf("|   \\/  \\/    |\n");
         printf("|     /\\      |\n");
         printf("|     \\/      |\n");
         printf("|          3  |\n");
         printf("|_____________|\n");
       }   
     if(strcmp((c.suit), "Spades")==0){ 
          printf(" _____________\n");
          printf("|             |\n");
          printf("| 3           |\n");
          printf("|    /\\  /\\   |\n");
          printf("|   (__)(__)  |\n");
          printf("|      /\\     |\n");
          printf("|     (__)    |\n");
          printf("|           3 |\n");
          printf("|_____________|\n");
     }
    if(strcmp((c.suit), "Clubs")==0){ 
          printf(" _____________\n");
          printf("|             |\n");
          printf("| 3           |\n");
          printf("|    *    *   |\n");
          printf("|   *|*  *|*  |\n");
          printf("|       *     |\n");
          printf("|      *|*    |\n");
          printf("|           3 |\n");
          printf("|_____________|\n");
     }
    if(strcmp((c.suit), "Hearts")==0){ 
          printf(" _____________\n");
          printf("|             |\n");
          printf("| 3           |\n");
          printf("|   (\\/)(\\/)  |\n");
          printf("|    \\/  \\/   |\n");
          printf("|     (\\/)    |\n");
          printf("|      \\/     |\n");
          printf("|           3 |\n");
          printf("|_____________|\n");
     }
     break;
  case 4:
  if(strcmp((c.suit), "Diamonds")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 4           |\n");
    printf("|   /\\  /\\    |\n");
    printf("|   \\/  \\/    |\n");
    printf("|   /\\  /\\    |\n");
    printf("|   \\/  \\/    |\n");
    printf("|          4  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Hearts")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 4           |\n");
    printf("|  (\\/)(\\/)   |\n");
    printf("|   \\/  \\/    |\n");
    printf("|  (\\/)(\\/)   |\n");
    printf("|   \\/  \\/    |\n");
    printf("|           4 |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Spades")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 4           |\n");
    printf("|   /\\  /\\    |\n");
    printf("|  (__)(__)   |\n");
    printf("|   /\\  /\\    |\n");
    printf("|  (__)(__)   |\n");
    printf("|           4 |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Clubs")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 4           |\n");
    printf("|    *   *    |\n");
    printf("|   *|* *|*   |\n");
    printf("|    *   *    |\n");
    printf("|   *|* *|*   |\n");
    printf("|           4 |\n");
    printf("|_____________|\n");
  }
  break;
  case 5:
  if(strcmp((c.suit), "Diamonds")==0){
      printf(" _____________\n");
    printf("|             |\n");
    printf("| 5           |\n");
    printf("|  /\\ /\\ /\\   |\n");
    printf("|  \\/ \\/ \\/   |\n");
    printf("|   /\\  /\\    |\n");
    printf("|   \\/  \\/    |\n");
    printf("|          5  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Hearts")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 5           |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("|  (\\/) (\\/)  |\n");
    printf("|   \\/   \\/   |\n");
    printf("|          5  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Spades")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 5           |\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|   /\\   /\\   |\n");
    printf("|  (__) (__)  |\n");
    printf("|          5  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Clubs")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 5           |\n");
    printf("|  *   *   *  |\n");
    printf("| *|* *|* *|* |\n");
    printf("|   *     *   |\n");
    printf("|  *|*   *|*  |\n");
    printf("|          5  |\n");
    printf("|_____________|\n");
  }
  break;
   case 6:
  if(strcmp((c.suit), "Diamonds")==0){
      printf(" _____________\n");
    printf("|             |\n");
    printf("| 6           |\n");
    printf("|  /\\ /\\ /\\   |\n");
    printf("|  \\/ \\/ \\/   |\n");
    printf("|  /\\ /\\ /\\   |\n");
    printf("|  \\/ \\/ \\/   |\n");
    printf("|          6  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit),"Spades" )==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 6           |\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|          6  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Hearts")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 6           |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("|          6  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Clubs")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 6           |\n");
    printf("|  *   *   *  |\n");
    printf("| *|* *|* *|* |\n");
    printf("|  *   *   *  |\n");
    printf("| *|* *|* *|* |\n");
    printf("|          6  |\n");
    printf("|_____________|\n");
  }
  break;
  case 7:
   if(strcmp((c.suit), "Diamonds")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 7           |\n");
    printf("| /\\ /\\ /\\ /\\ |\n");
    printf("| \\/ \\/ \\/ \\/ |\n");
    printf("|  /\\ /\\ /\\   |\n");
    printf("|  \\/ \\/ \\/   |\n");
    printf("|          7  |\n");
    printf("|_____________|\n");
   }
  if(strcmp((c.suit), "Spades")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 7           |\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|     /\\    7 |\n");
    printf("|____(__)_____|\n");
  }
    if(strcmp((c.suit), "Clubs")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 7           |\n");
    printf("| *  *   *  * |\n");
    printf("|*|**|* *|**|*|\n");
    printf("|  *   *   *  |\n");
    printf("| *|* *|* *|* |\n");
    printf("|          7  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Hearts")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 7           |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("|     (\\/) 7  |\n");
    printf("|______\\/_____|\n");
  }
  break;
  case 8: 
  if(strcmp((c.suit), "Diamonds")==0){
       printf(" _____________\n");
    printf("|             |\n");
    printf("| 8           |\n");
    printf("| /\\ /\\ /\\ /\\ |\n");
    printf("| \\/ \\/ \\/ \\/ |\n");
    printf("| /\\ /\\ /\\ /\\ |\n");
    printf("| \\/ \\/ \\/ \\/ |\n");
    printf("|          8  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Hearts")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 8           |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("|   (\\/)(\\/) 8|\n");
    printf("|____\\/__\\/___|\n");
  }
  if(strcmp((c.suit), "Clubs")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 8           |\n");
    printf("| *  *   *  * |\n");
    printf("|*|**|* *|**|*|\n");
    printf("| *  *   *  * |\n");
    printf("|*|**|* *|**|*|\n");
    printf("|          8  |\n");
    printf("|_____________|\n");
  }
  if(strcmp((c.suit), "Spades")==0){
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 8           |\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|   /\\   /\\ 8 |\n");
    printf("|__(__)_(__)__|\n");
  }
  break;
  case 9:
    if(strcmp((c.suit), "Diamonds")==0){
      printf(" _____________\n");
    printf("|             |\n");
    printf("| 9           |\n");
    printf("| /\\ /\\ /\\ /\\ |\n");
    printf("| \\/ \\/ \\/ \\/ |\n");
    printf("| /\\ /\\ /\\ /\\ |\n");
    printf("| \\/ \\/ \\/ \\/ |\n");
    printf("|     /\\    9 |\n");
    printf("|_____\\/______|\n");
  }
    if(strcmp((c.suit), "Hearts")==0){
    printf(" _____________\n");
    printf("|     (\\/)    |\n");
    printf("| 9    \\/     |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("|   (\\/)(\\/) 9|\n");
    printf("|____\\/__\\/___|\n");
  }
    if(strcmp((c.suit), "Spades")==0){
    printf(" _____________\n");
    printf("| 9    /\\     |\n");
    printf("|     (__)    |\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|   /\\   /\\ 9 |\n");
    printf("|__(__)_(__)__|\n");
  }
  if(strcmp((c.suit), "Clubs")==0){ 
    printf(" _____________\n");
    printf("|             |\n");
    printf("| 9           |\n");
    printf("| *  *   *  * |\n");
    printf("|*|**|* *|**|*|\n");
    printf("| *  *   *  * |\n");
    printf("|*|**|* *|**|*|\n");
    printf("|      *    9 |\n");
    printf("|_____*|*_____|\n");
  }
  break;
  case 10:
      if(strcmp((c.suit), "Diamonds")==0){
      printf(" _____________\n");
    printf("|             |\n");
    printf("| 10          |\n");
    printf("| /\\ /\\ /\\ /\\ |\n");
    printf("| \\/ \\/ \\/ \\/ |\n");
    printf("| /\\ /\\ /\\ /\\ |\n");
    printf("| \\/ \\/ \\/ \\/ |\n");
    printf("|    /\\ /\\ 10 |\n");
    printf("|____\\/_\\/____|\n");
  }
   if(strcmp((c.suit), "Hearts")==0){
    printf(" _____________\n");
    printf("|   (\\/)(\\/)  |\n");
    printf("| 10 \\/  \\/   |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("| (\\/)(\\/)(\\/)|\n");
    printf("|  \\/  \\/  \\/ |\n");
    printf("|  (\\/) (\\/)10|\n");
    printf("|___\\/___\\/___|\n");
  }
  if(strcmp((c.suit), "Spades")==0){
    printf(" _____________\n");
    printf("| 10 /\\   /\\  |\n");
    printf("|   (__) (__) |\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|  /\\  /\\  /\\ |\n");
    printf("| (__)(__)(__)|\n");
    printf("|   /\\   /\\ 10|\n");
    printf("|__(__)_(__)__|\n");
  }
  if(strcmp((c.suit), "Clubs")==0){ 
    printf(" _____________\n");
    printf("|      *      |\n");
    printf("| 10  *|*     |\n");
    printf("| *  *   *  * |\n");
    printf("|*|**|* *|**|*|\n");
    printf("| *  *   *  * |\n");
    printf("|*|**|* *|**|*|\n");
    printf("|      *   10 |\n");
    printf("|_____*|*_____|\n");
  }
  break;
    case 11:
      if(strcmp((c.suit), "Diamonds")==0){
        printf("______________\n| /\\ \\____/   |\n| \\/ /%%%% O\\   |\n|___/%%%% __/  ?|\n| \\    J   \\ ||\n|  \\ __J__ /  |\n||  /  %%%%/___ |\n|¿  \\O_%%%%/ /\\ |\n|___/____\\_\\/_|\n");
      }
      
      if(strcmp((c.suit), "Hearts")==0){
        printf(" _____________\n");
        printf("|(\\/) \\___/   |\n");
        printf("| \\/ /%%%% O\\   |\n");
        printf("|___/%%%% __/  ?|\n");
        printf("| \\    J  /\\ ||\n");
        printf("|  \\ __J___/__|\n");
        printf("||  /   %%%%/   |\n");
        printf("|¿  \\O_%%%%/(\\/)|\n");
        printf("|___/___\\__\\/_|\n"); 
      }
      if(strcmp((c.suit), "Spades")==0){ 
        printf(" _____________\n");
        printf("| /\\  \\___/   |\n");
        printf("|(__)/%%%% O\\   |\n");
        printf("|___/%%%% __/  ?|\n");
        printf("| \\    J  /\\ ||\n");
        printf("|  \\ __J_  /  |\n");
        printf("||  /   %%%%/___|\n");
        printf("|¿  \\O_%%%%/ /\\ |\n");
        printf("|___/____\\(__)|\n");
      }
       if(strcmp((c.suit), "Clubs")==0){ 
         printf("_____________\n");
         printf("|  *  \\___/   |\n");
         printf("| *|* /%%%% O\\  |\n");
         printf("|___ /%%%% __/ ?|\n");
         printf("| \\    J  /\\ ||\n");
         printf("|  \\ __J_  /  |\n");
         printf("||  /   %%%%/___|\n");
         printf("|¿  \\O_%%%%/*|* |\n");
         printf("|___/____\\_*__|\n");
       }
    break;
  case 12:
      if(strcmp((c.suit), "Diamonds")==0){
        printf(" _____________\n");
        printf("| /\\  )((\\    |\n");
        printf("| \\/  |Q((\\   |\n");
        printf("|  ___|_-___ *|\n");
        printf("| (    |   \\ ||\n");
        printf("|__\\ __|__ )  |\n");
        printf("|| \\))  -|___ |\n");
        printf("|*  \\)) Q| /\\ |\n");
        printf("|____ ))(__\\/_|\n");
      }
      if(strcmp((c.suit), "Hearts")==0){
        printf(" _____________\n");
        printf("|(\\/)  )((\\   |\n");
        printf("| \\/  |Q ((\\  |\n");
        printf("|  ___|_-___ *|\n");
        printf("| (    |   \\ ||\n");
        printf("|__\\__|__ )   |\n");
        printf("|| \\))  -|___ |\n");
        printf("|*  \\)) Q|(\\/)|\n");
        printf("|____ ))(__\\/_|\n");
      }
      if(strcmp((c.suit), "Spades")==0){
        printf(" _____________\n");
        printf("| /\\  )((\\    |\n");
        printf("|(__) |Q((\\   |\n");
        printf("|  ___|_-___ *|\n");
        printf("| (    |   \\ ||\n");
        printf("|__\\ __|__ )  |\n");
        printf("|| \\))  -|___ |\n");
        printf("|*  \\)) Q| /\\ |\n");
        printf("|____ ))(_(__)|\n");
      }
      if(strcmp((c.suit), "Clubs")==0){ 
        printf(" _____________\n");
        printf("|  *  )((\\    |\n");
        printf("| *|* |Q((\\   |\n");
        printf("|  ___|_-___ *|\n");
        printf("| (    |   \\ ||\n");
        printf("|__\\ __|__ )  |\n");
        printf("|| \\))  -|___ |\n");
        printf("|*  \\)) Q|*|* |\n");
        printf("|____ ))(__*__|\n");
      }
   break;
    case 13:
      if(strcmp((c.suit), "Diamonds")==0){
        printf(" _____________\n");
        printf("| /\\ \\____/   |\n");
        printf("| \\/ |<><>| /\\|\n");
        printf("|  __|~-~ |-|||\n");
        printf("| I  )|K|(| |||\n");
        printf("|||  )|K|(  I |\n");
        printf("|||-| ~-~|___ |\n");
        printf("|\\/ |<><>|  /\\|\n");
        printf("|__/______\\_\\/|\n");

    }
    if(strcmp((c.suit), "Hearts")==0){
      printf(" _____________\n");
      printf("|(\\/)\\____/   |\n");
      printf("| \\/ |<><>| /\\|\n");
      printf("|  __|~-~ |-|||\n");
      printf("| I  )|K|(| |||\n");
      printf("|||   )|K|( I |\n");
      printf("|||-| ~-~|___ |\n");
      printf("|\\/ |<><>|(\\/)|\n");
      printf("|___/_____\\\\/_|\n");
    }
    if(strcmp((c.suit), "Spades")==0){
      printf(" _____________\n");
      printf("| /\\ \\____/   |\n");
      printf("|(__)|<><>| /\\|\n");
      printf("|  __|~-~ |-|||\n");
      printf("| I  )|K|(| |||\n");
      printf("||| |)|K|(  I |\n");
      printf("|||-| ~-~|___ |\n");
      printf("|\\/ |<><>|(\\/)|\n");
      printf("|__/______\\\\/_|\n");
    }
    if(strcmp((c.suit), "Clubs")==0){ 
      printf(" _____________\n");
      printf("| * \\____/    |\n");
      printf("|*|*|<><>| /\\ |\n");
      printf("| __|~-~ |-|| |\n");
      printf("| I  )|K|( ||||\n");
      printf("|||  )|K|(  I |\n");
      printf("|||-| ~-~|___ |\n");
      printf("|\\/ |<><>| *|*|\n");
      printf("|__/______\\_*_|\n");

    }
      break;
      default:
      printf("%d ", c.value); 
      printf("%s\n", c.suit);
      break;
    }
  }

  void printHand(player p){
  int i;
  for(i = 0; i < 3; i++){
    printCard(p.c[i]);
  }
  if(strlen(p.c[i].suit) > 3){
      printCard(p.c[i]);
  }
}

#endif