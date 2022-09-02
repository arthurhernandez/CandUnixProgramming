/*
Arthur Hernandez
Assignment 4 question 2
//Tue April 21st 
//C291
*/
// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
char *suitSaver[5];
char *faceSaver[5];
// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]); // dealing doesn't modify the arrays
void faceFunction(); //takes care of checking for pairs, 2 pairs, 3 or 4 of a kind, and straight
void suitFunction(); // takes care of checking for a flush 
int main(void)
{
   // initialize deck array
   unsigned int deck[SUITS][FACES] = { 0 };

   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   // initialize suit array                       
   const char *suit[SUITS] =            
      {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
      {"Ace", "Deuce", "Three", "Four",         
       "Five", "Six", "Seven", "Eight",         
       "Nine", "Ten", "Jack", "Queen", "King"};

   deal(deck, face, suit); // deal the deck
   faceFunction(); // check faces
   suitFunction(); // check suits
} 

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   } 
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
    int count = 0;
   // deal each of the cards
   for (size_t card = 1; card <= CARDS; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wDeck[row][column] == card) {
                suitSaver[count] = wSuit[row];
                faceSaver[count] = wFace[column];
                if(count > 4){break;}
               printf("%5s of %-8s%c", wFace[column], wSuit[row],
                  card % 2 == 0 ? '\n' : '\t'); // 2-column format
                  count++;
            } 
         } 
      } 
   } 
   printf("\n\n");
}
// checks for pairs 2 pairs ect.
void faceFunction(){
    //uses the same array to check if theyre the same 
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four","Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int pairs = 0;
    int i = 0;
    int j = 0;
    //initialize instances of each face to be 0 for each , take into account to not go out of bounds when checking for straight
    int faceInstance[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //checks 5 cards
    for(i = 0; i < 5;i++){
        //compares each to each type of face
        for(j = 0; j<13; j++){
            if (faceSaver[i] == face[j]) {
                //adds 1 to its instance holder 
                faceInstance[j] += 1;
            }
        }
    }
    for(i = 0;i < 13;i++){
        //print all faces and the amount 
        printf(" %s's: %d    " , face[i],faceInstance[i]);
    }
    printf("\n");
    //checks each instance
    for(i = 0; i < 13;i++){
        //checks for 4 of a kind
        if(faceInstance[i] == 4){
            printf("Your hand has 4 %s's!\n" , face[i]);
        //checks for trips
        }else if(faceInstance[i] == 3){
            printf("Your hand has 3 %s's! \n" , face[i]);
        }
        //checks for straight by checking the next five
        if(faceInstance[i] != 0 && faceInstance[i+1] != 0 && faceInstance[i+2] != 0 && faceInstance[i+3] != 0 && faceInstance[i+4] != 0 ){
            printf("You have a %d high straight!", faceInstance[i+4]);
        }
        //adds 1 to pair counter
        if(faceInstance[i] == 2){
            pairs++;
        }
    }
    //check pair counter
    if(pairs== 2){
        printf("Your hand contains a 2 pairs\n");
        }
    else if (pairs == 1){
        printf("Your hand contains a pair\n");
    }
    printf("\n\n");
}
//checks for flush
void suitFunction(){
    //uses previous suit array
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int i = 0;
    int j = 0;
    //initialize suit no need to worry about outofbounds for flush
    int suitInstance[5] = {0,0,0,0,0};
    //for 5 cards
    for(i = 0; i < 5;i++){
        //check each suit
        for(j = 0; j<4; j++){
            if (suitSaver[i] == suit[j]) {
                suitInstance[j] += 1;
            }
        }
    }
    //print instances 
    for(i = 0;i < 4;i++){
        printf(" %s's: %d    " , suit[i],suitInstance[i]);
        //print if its a flush
        if(suitInstance[i] == 5){
            printf("You have a %s Flush!!!!! \n",suit[i]);
        }

    }
}

