//This program uses a function called CharacterScan to read a char from the user
//The function must take an int pointer as a parameter
//The program should print the char and ascii code for each character the user enters
//The program should only exit whe nthe user enters escape

#include <stdio.h>
#include <stdlib.h>

char CharacterScan(int* iPtr);

int main(void){
    int* iPtr = 0;
    char exit;
    char aCode;
    do{
	char c = CharacterScan(iPtr);
	aCode = *iPtr;
        if(aCode != 27){
            printf("Exiting the code!\n");
            break;
        }
        else{
            printf("%c is ASCII code %d.\n", c, aCode);
        }
    }while(aCode != 27);
return 0;
}

char CharacterScan(int* iPtr){
    char c;
    printf("Enter a character: ");
    scanf(" %c",&c);
    int a = (int)c;
    iPtr =&a;
    return c;
}
