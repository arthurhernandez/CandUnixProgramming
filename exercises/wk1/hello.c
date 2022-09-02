/* 
 * Basic first C program to print out my named! 
 * Author: Arthur Hernandez
*/

#include <stdio.h>

int main(void) {
  int myNumber = 0;
  printf("Hello my name is Arthur Hernandez");
  printf("Please enter a number and press ENTER: ");
  scanf("%d", &myNumber);  
  printf("Here is the number yor entered: %d\n",myNumber);
  return(0); 
}


