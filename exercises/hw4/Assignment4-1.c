//Arthur Hernandez
//C291
//Assignment 4-question 1 (with dynamic allocation)
//Tuesday April 21st
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ISSUES 7
#define RATING 10
int**responses;
char** topics;

//creates a pointer arr of 7 topics
void setTopics();
//creates and sets a 3d 7 by 10 table with all values to 0
void setResponses();
//scanner for the input of each topic and places responses in table
void scanTopics();
//prints the table entirely 
void printTable();
//goes through the response table and checks for highest lowest and amount of responses 
void additionalMaterial();
//deallocates all malloc memory 
void deAllocate();


int main(void){
    char yesOrNo;
    //menu
    printf("     ------------------------------------Social Issues Poll------------------------------------\n Please rate the following social issues a number between 1(least important) and 10 (most important)\n");
    setTopics();
    setResponses();
    //stays in do while until user enter n or N
    do{
    scanTopics();
    printTable();
    additionalMaterial();
    //scans for yes or no
    printf("Would you like to have someone else take this poll? enter y or n: ");
    scanf(" %c",&yesOrNo);
    printf("\n");
    }while(yesOrNo != 'n' && yesOrNo != 'N');
    deAllocate();
    

return 0; 
} 

void setTopics(){
    //array of pointers memory 
    topics = malloc(7*sizeof(*topics));
    if( topics == NULL ){//makes sure mem is open
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    //sets each instance of topics 
    *topics="Climate Change";
    *(topics+1)="Domestic abuse";
    *(topics+2)="Wealth inequality";
    *(topics+3)="Government corruption";
    *(topics+4)="Racial Discrimination";
    *(topics+5)="Digital Information";
    *(topics+6)="Gun Violence";
    int i;
    //prints them for the user first 
    for(i = 0; i < 7;i++){
        printf("%s, ", *(topics + i));
    } 
    printf("\n");
}

void setResponses(){
    //initialize counters
    int N = 7, M = 10, i, j;
    //set memory allocation 
    responses = (int**) malloc( N * sizeof(int*) );
    if( responses == NULL ){//check the mem is open 
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    //pointer inside pointer initialization and check
    for(i=0; i< N; i++){
        *(responses + i) = (int*)malloc(M * sizeof(int*) );
        if(*(responses + i) == NULL){
            fprintf(stderr, "Error - unable to allocate required memory\n");
        }
    }
    //sets all responses to 0
    for(i=0; i< N; i++) { 
        for(j=0; j < M; j++) {
            *(*(responses+i)+j) = 0; 
        }
    }
    printf("\n");
}

void scanTopics(){
    int rank, i;
    // loops through each topic
    for(i = 0; i < 7;i++){
    printf("please rate the importance of %s: ",*(topics+i));
    scanf("%d" , &rank); //scans the input 
    int rankholder = rank - 1;
    *(*(responses+i)+(rank-1)) +=  1; // will only be placed if its 1-10
    }
}

void printTable(){
    int i, j;
    //prints the top of the table
    printf("Scores given:           1    2    3    4    5    6    7    8    9    10  Averages:\n");
        //for each x,y it will print out its position
        for(i=0; i< 7; i++) {
            float average = 0;
            int  count = 0;
            //prints topic for each row
            printf("%-22s", *(topics+i));
        for(j=0; j < 10; j++) {
            //prints the amount of responses
            printf("  %d  ",*(*(responses+i)+j));
	    //finds the average for each row
            average += *(*(responses+i)+j) * (j+1);
            count += *(*(responses+i)+j);
        }
        // total points per row / number of entries 
        average = average / count;
        //print average 
        printf("   %.3f\n", average); 
    }
}

void additionalMaterial(){
    // highest point total, add all points in each issue and compare to the rest
    // lowest point total, same as lowest but compare to lowest
    // amount of responses / 7 = number of people answered
    int highestTotal = 0, i, j;
    int highest = 0;
    int lowestTotal = *(*(responses+0)+0) * (j+0);
    int lowest = 0;
    int tempTotal;
    int amountOfResponces = 0;
    for(i=0; i< 7; i++) { 
        tempTotal = 0;
        for(j=0; j < 10; j++) {
	    //sets tempTotal to the total points in the row and amountOfResponses to the amount in the row
            tempTotal += *(*(responses+i)+j) * (j+1);
            amountOfResponces += *(*(responses+i)+j);
        }
        // checks if temp > highest and sets it and its topic equal to it if true
        if(tempTotal > highestTotal){
            highestTotal = tempTotal;
            highest = i;
        }
        // checks if temp < lowest and sets itself and its topic equal to it if true
        if(tempTotal < lowestTotal){
            lowestTotal = tempTotal;
            lowest = i;
        }
    }
    // prints the highest, lowest issues and the amount of people who have taken the poll according to the number of responses 
    printf("%s received the highest point total of %d points\n", *(topics+highest),highestTotal);
    printf("%s received the lowest point total of %d points\n", *(topics+lowest),lowestTotal);
    printf("%d people have taken this poll\n", amountOfResponces / 7);
}

void deAllocate(){
    // free allocated space for topics 
    free(topics);
    int i;
    //free allocated space for responses 
    for(i=0; i< 7; i++) {
        free(*(responses + i));
    }
    free(responses); 
    
}
