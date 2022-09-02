
//This program is supposed to scan 5 ints from the user
//Using those 5 ints, it should construct a linked list of 5 elements
//Then it prints the elements of the list using the PrintList function

#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
        struct Node* next;
};
void PrintList(struct Node* n);
int main(void){
        struct Node* first = NULL;
        struct Node* second = NULL;
        struct Node* third = NULL;
        struct Node* fourth = NULL;
        struct Node* fifth = NULL;



        first = (struct Node*)malloc(sizeof(struct Node)); 
        second = (struct Node*)malloc(sizeof(struct Node)); 
        third = (struct Node*)malloc(sizeof(struct Node)); 
        fourth = (struct Node*)malloc(sizeof(struct Node)); 
        fifth = (struct Node*)malloc(sizeof(struct Node)); 

        int i;
        scanf(" %d \n", &i);
        first->data = i;
        first->next = second; 
        scanf(" %d\n", &i);
        second->data = i;
        second->next = third;
        scanf(" %d\n", &i);
        third->data = i;
        third->next = fourth;
       
        scanf(" %d\n", &i);
        fourth->data = i;
        fourth->next = fifth;
       
        scanf(" %d\n", &i);
        fifth->data = i;
        fifth->next = NULL;

        PrintList(first);
}

void PrintList(struct Node* n){
        while(n != NULL){
                printf(" %d ", n->data);
                n = n->next;
        }

	printf("\n");
}


