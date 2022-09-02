  
//Arthur Hernandez
//C291
//Assignment 4-1
//Tuesday April 21st
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ISSUES 7
#define RATING 10
int**responses;
char** topics;


void setTopics();
void setResponses();
void scanTopics();
void printTable();
void additionalMaterial();
void deAllocate();


int main(void){
    char yesOrNo;
    printf("     ------------------------------------Social Issues Poll------------------------------------\n Please rate the following social issues a number between 1(least important) and 10 (most important)\n");
    setTopics();
    setResponses();
    do{
    scanTopics();
    printTable();
    additionalMaterial();
    printf("Would you like to have someone else take this poll? enter y or n: ");
    scanf(" %c",&yesOrNo);
    printf("\n");
    }while(yesOrNo != 'n' && yesOrNo != 'n');
    deAllocate();
    

return 0; 
} 

void setTopics(){
    topics = malloc(7*sizeof(*topics));
    if( topics == NULL ){
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    *topics="Climate Change";
    *(topics+1)="Domestic abuse";
    *(topics+2)="Wealth inequality";
    *(topics+3)="Government corruption";
    *(topics+4)="Racial Discrimination";
    *(topics+5)="Digital Information";
    *(topics+6)="Gun Violence";
    int i;
    for(i = 0; i < 7;i++){
        printf("%s, ", *(topics + i));
    } 
    printf("\n");
}

void setResponses(){
    int N = 7, M = 10, i, j;
    responses = (int**) malloc( N * sizeof(int*) );
    if( responses == NULL ){
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    for(i=0; i< N; i++){
        *(responses + i) = (int*)malloc(M * sizeof(int*) );
        if(*(responses + i) == NULL){
            fprintf(stderr, "Error - unable to allocate required memory\n");
        }
    }
    for(i=0; i< N; i++) { 
        for(j=0; j < M; j++) {
            *(*(responses+i)+j) = 0; 
        }
    }
    printf("\n");
}

void scanTopics(){
    int rank, i;
    for(i = 0; i < 7;i++){
    printf("please rate the importance of %s: ",*(topics+i));
    scanf("%d" , &rank);
    int rankholder = rank - 1;
    *(*(responses+i)+(rank-1)) +=  1;
    }
}

void printTable(){
    int i, j;
    printf("Scores given:           1    2    3    4    5    6    7    8    9    10  Averages:\n");
        for(i=0; i< 7; i++) { 
            float average = 0;
            int  count = 0;
            printf("%-22s", *(topics+i));
        for(j=0; j < 10; j++) {
            printf("  %d  ",*(*(responses+i)+j));
            average += *(*(responses+i)+j) * (j+1);
            count += *(*(responses+i)+j);
        }
        average = average / count;
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
            tempTotal += *(*(responses+i)+j) * (j+1);
            amountOfResponces += *(*(responses+i)+j);
        }
        if(tempTotal > highestTotal){
            highestTotal = tempTotal;
            highest = i;
        }
        if(tempTotal < lowestTotal){
            lowestTotal = tempTotal;
            lowest = i;
        }
    }
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
