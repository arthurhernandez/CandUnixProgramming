/*
Arthur Hernandez
Assignment 3 
C291
Tuesday April 14th
Rows 
total 72 seats
Each row has 12 seats 6 columns
for(i=0; i<6; i++) {
      for(j=0;j<12;j++) {
          planeSeats[i][j] = x;
         printf(" %d", planeSeats[i][j]);
A window seat
B middle
C aisle
D aisle
E middle
F window seats
Seat assignment is randomly choosen
	make sure window seat is not taken if so choose new one in the same section
		if they dont like the window/ aisle change (no more than 3 times)
            keep changing random while running through different availible seats
After seat assignment
	1.print seat map with all seats used or unused
	2.mainifest of names of passengers and seat number 
	3.user will provide their seat number	
		boarding pass showing seat number name and what class (For 			example: JOHN DOE, SEAT: 2B, Level: First Class). 
user should have the choice of upgrading to business class or first class if a seat is available. 
"Next flight leaves in 3 hours." If no seat is available 
Menu alternatives:
F first class columns  1-2 seats 1-12
B business columns 3-5 13-24
E economy 6-12 25 - 72
*/   
#include <stdio.h>
#include <stdlib.h>
char class;
char seatNum;
char windowMiddleOrAisleSeat;
char yesOrNo;
char inputOfSeatLetter;
char name[25];
char* arrOfNames[72];

int row;
int seat;
int menuOptions;
int seatRow, seatCol;
int planeSeats[6][12];
int inputOfSeatNumber;

void checkSeat(int seatRow,int seatCol);
void chooseSeat(char class);
char seatLetter(int Seatrow);
void checkClassCapacity();
void printMap();
void printPassengers();
void printBoardingPass();
int seatNumber(char inputOfSeatLetter);


int main(void){
    // initialize list of names to show no one has reserved the seat
    int y;
    for(y = 0; y < 72; y++){
    arrOfNames[y] = "No one has choosen this seat";
}
//initialize all seats in 2d array to 0
    int i;
    int j;
   for(i=0; i<6; i++) {
      for(j=0;j<12;j++) {
          planeSeats[i][j] = 0;
         printf(" %d", planeSeats[i][j]);
      }
      printf("\n");
   }
   printf("\n");
    //menu choose class makes sure input is a charecter of type class

    do{
       	printf("------------------Menu------------------ \n");
        printf("Welcome to Arthur Airlines! \n");
        printf("Please pick what class you would like to be sat in. First class F, Business class B, or economy class E:\n");
        scanf(" %c", &class);
        printf("You choose class %c \n", class);
        if(class != 'F' && class != 'f' && class != 'B' && class != 'b' && class != 'E' && class != 'e'){
            printf("Invalid code please try again \n");
        }
    }while(class != 'F' && class != 'f' && class != 'B' && class != 'b' && class != 'E' && class != 'e');
    //checks the class capacity
    checkClassCapacity(class);
    printf("your class is %c. ", class);
    //chooses first seat
    chooseSeat(class);
    // finds the seat letter associated with the row
    seatNum = seatLetter(seatRow);
    printf("your seat number is %d%c \n",seatCol,seatNum);
    int l;
    // only gives the user 3 chances to choose a different seat
    for(l = 0; l < 2; l++){
        //enter yes or no for a different seat
        printf("would you like to choose a different seat? enter y or n. \n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'y' || yesOrNo == 'Y' ){
            chooseSeat(class);
            seatNum = seatLetter(row);
            printf("your new seat number is %d%c \n",seatCol,seatNum);
        }else{
            break;
        }
    }
    printf("Enter your full name to finalize your ticket\n");
    scanf("%[^\n]%*c", name);
    arrOfNames[seatRow * seatCol - 1] = name;
    printf("please enter the corresponding number as how you wish to proceed\n (1) seating map/chart \n (2) passenger manifest \n (3) boarding pass \n");
    scanf("%d", &menuOptions);
    if(menuOptions == 1){
        printMap();
    }else if(menuOptions == 2){
        printPassengers();

    }else if(menuOptions == 3){
        printBoardingPass();
    }
return 0;
}

void checkClassCapacity(){
    //capacity of First class
    int firstClassCap = 0;
    int i;
    int j;
   for(i=0; i<6; i++) {
      for(j=0;j<2;j++) {
          if(planeSeats[i][j] == 0){
            firstClassCap++;
          }
      }
   }
    //capacity of buisness
    int buisnessClassCap = 0;
    int k;
    int l;
   for(k=0; k<6; k++) {
      for(l=2;l<4;l++) {
          if(planeSeats[k][l] == 0){
            buisnessClassCap++;
          }
      }
   }
    //capacity of economy
    int econClassCap = 0;
    int m;
    int n;
   for(m=0; m<6; m++) {
      for(n=5;n<12;n++) {
          if(planeSeats[m][n] == 0){
            econClassCap++;
          }
      }
   }
   //checks if all capacities are full
   if(firstClassCap + buisnessClassCap + econClassCap == 0){
     printf("there is no more room left in this flight. The next flight leaves in 3 hours.\n");
     exit(0);
    }
    //checks if first class is full and buisness is not
    if(firstClassCap == 0 && (class == 'f' || class == 'F') && buisnessClassCap != 0){
       printf("there is no more room in first class would you like to be placed in buisness? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'Y' || yesOrNo == 'y'){
            //sets new class
            class = 'B';

        }else{
            printf("The next flight leaves in 3 hours.");
            exit(0);
        }
    //checks if both first and buisness are full but economy is not
    } else if(firstClassCap == 0 && (class == 'f' || class == 'F') && buisnessClassCap == 0){
         printf("there is no more room in first class and buisness class would you like to be placed in economy? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'Y' || yesOrNo == 'y'){
            class = 'E';
        }else{
            printf("The next flight leaves in 3 hours.\n");
            exit(0);
        }
    }
    //checks if buisness is full and wether there is space in first class
    if(firstClassCap != 0 && (class == 'B' || class == 'b') && buisnessClassCap == 0){
       printf("there is no more room in buissnes class would you like to upgrade to first class? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'Y' || yesOrNo == 'y'){
            //sets new class
            class = 'F';
        }else{
            printf("The next flight leaves in 3 hours.");
            exit(0);
        }
    //checks if both first and buisness are full but economy is not
    } else if(firstClassCap == 0 && (class == 'B' || class == 'b') && buisnessClassCap == 0){
         printf("there is no more room in buisness and first class would you like to be placed in economy? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'Y' || yesOrNo == 'y'){
            class = 'E';
        }else{
            printf("The next flight leaves in 3 hours.");
            exit(0);
        }
    }
    //economy is full but buisness class is not
    if(buisnessClassCap != 0 && (class == 'e' || class == 'E') && econClassCap == 0){
       printf("there is no more room in economy class would you like to upgrade to buisness? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'Y' || yesOrNo == 'y'){
            //sets new class
            class = 'B';
        }else{
            printf("The next flight leaves in 3 hours.");
            exit(0);
        }
    //checks if both first and buisness are full but economy is not
    } else if(firstClassCap != 0 && (class == 'e' || class == 'E') && econClassCap == 0){
        printf("there is no more room in economy and buisness class would you like to be placed in First class? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'Y' || yesOrNo == 'y'){
            class = 'F';
        }else{
            printf("The next flight leaves in 3 hours.");
            exit(0);
        }
    }
    //upgrades without classes having to be full
    //upgrades economy to buisness or First class
    if(class == 'E' || class == 'e' && buisnessClassCap != 0 && firstClassCap != 0){
        printf("There is availibe room in buisness and First class would you like to upgrade? enter 'F' for first class, 'B' for buisness or n for neither.\n");
        scanf(" %c", &yesOrNo);
        //first class upgrade
        if(yesOrNo == 'f' || yesOrNo == 'F'){
            class = 'F';
        //buisness class upgrade
        }else if(yesOrNo == 'B' || yesOrNo == 'b'){
            class = 'B';
        }
    }
    //upgrades economy to buisness if first is full
    else if(class == 'E' || class == 'e' && buisnessClassCap != 0 ){
        printf("There is availibe room in Buisness class would you like to upgrade? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            class = 'B';
        }
    }
    //upgrade economy to first class if buisness is full
    else if(class == 'E' || class == 'e' && firstClassCap != 0 ){
    printf("There is availibe room in First class would you like to upgrade? enter y or n.\n");
    scanf(" %c", &yesOrNo);
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            class = 'F';
        }
    }
    // uprgrades buisness to first class if first is not full
    if(class == 'B' && firstClassCap != 0){
        printf("There is availibe room in First class would you like to upgrade? enter y or n.\n");
        scanf(" %c", &yesOrNo);
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            class = 'F';
        }
    }
}

void chooseSeat(char class){
    //chooses random number depending on what type of seat type the user wants
    int minCol, maxCol;
    printf("would you like a middle, window, or aisle seat? enter m, w, or a. If you have no prefrence enter any charecter. \n");
    scanf(" %c", &windowMiddleOrAisleSeat);
    if(windowMiddleOrAisleSeat == 'm' || windowMiddleOrAisleSeat == 'M'){
        do{
	seatRow = (rand() % 6);
        }while(seatRow != 2 && seatRow != 5);
    } else if (windowMiddleOrAisleSeat == 'W' || windowMiddleOrAisleSeat == 'w'){
        do{
	seatRow = (rand() % 6);
        }while(seatRow != 1 && seatRow != 6);
    } else if (windowMiddleOrAisleSeat == 'a' || windowMiddleOrAisleSeat == 'A'){
        do{
	seatRow = (rand() % 6);
        }while(seatRow != 3 && seatRow != 4);
    } else{
	seatRow = (rand() % 6);
    }
    //chooses random number depending on what type of seat class
    if (class == 'F' || class == 'f' ){
        minCol = 0;
        maxCol = 1;
    }
    else if (class == 'B' || class == 'b' ){
        minCol = 2;
        maxCol = 3;
    }else{
            minCol = 4;
        maxCol = 11;
    }
    seatCol = (rand() % maxCol- minCol + 1) + minCol;
    checkSeat(seatRow,seatCol);
}

void checkSeat(int seatRow, int seatCol){
    //sets the seat selection in the 2d array
    if(planeSeats[seatRow - 1][seatCol - 1] == 0){
        planeSeats[seatRow - 1][seatCol - 1] = 1;
    }else{
          	chooseSeat(class);
    }
}
// easy way to go from row to letter of the row
char seatLetter(int seatRow){
    switch(seatRow){
        case 1:
            return  'A';
            break;
        case 2:
            return  'B';
            break;
        case 3:
            return  'C';
            break;
        case 4:
            return  'D';
            break;
        case 5:
            return  'E';
            break;
        case 6:
            return  'F';
            break;
        default:
        break;
    }
}
int seatNumber(char inputOfSeatLetter){
    switch(seatRow){
        case 'A':
            return  0;
            break;
        case 'B':
            return  1;
            break;
        case 'C':
            return  2;
            break;
        case 'D':
            return  3;
            break;
        case 'E':
            return  4;
            break;
        case 'F':
            return 5;
            break;
        default:
        break;
    }
}

void printMap(){
    //prints map needed for menu option 1
    int i;
    int j;
    printf("   1  2  3  4  5  6  7  8  9  10 11 12\n");
    for(i=0; i<6; i++) {
        if(i == 0){
        printf("A ");
        }else if(i == 1){
        printf("B ");
        }        if(i == 2){
        printf("C ");
        }        if(i ==3){
        printf("\nD ");
        }        if(i == 4){
        printf("E ");
        }        if(i ==5){
        printf("F ");
        }
      for(j=0;j<12;j++) {
         printf("[%d", planeSeats[i][j]);
         printf("]");
      }
      printf("\n");
    }
    printf("\n");
}


void printPassengers(){
    //prints off the array 
    int i,j;
    int k  = 0;
    printf(" Seat:    Name:\n");
    for(i=0; i<6; i++) {
	char letter = seatLetter(i+1);
         for(j=0;j<12;j++) {
             // prints off the seat letter and the number of the col
            printf("%c%d     ",letter,j+1);
            //prints off the name in the same line
            printf("%s \n", arrOfNames[k]);  
            k++; 
         }
      }
}


void printBoardingPass(){
// takes in the seat letter and turns it into the seat number
printf("please enter seat letter");
scanf(" %c",&inputOfSeatLetter);
//takes in the seat number
printf("Please enter seat number\n");
scanf("%d",&inputOfSeatNumber);
//multiply them together - 1 to get the name of the person in that seat. 
int seatNumberThroughSevenOne = (seatNumber(inputOfSeatLetter) * inputOfSeatNumber) - 1;
//find the level
char level[15]= "level";
if(seatNumberThroughSevenOne < 24){
   char  level[15] = "First Class";
}else if(seatNumberThroughSevenOne < 48){
   char level[15] = "Buisness Class";
}else{
    char level[15] = "Economy Class";
}
//print
printf("Name: %s, Seat: :%c%d, Level: %c", arrOfNames[seatNumberThroughSevenOne],inputOfSeatLetter,inputOfSeatNumber,level[15]);  
}
