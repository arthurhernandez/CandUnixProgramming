/*Debugging quiz - File No: 3 */
/* This program should perform the duties of a basic calculator and print whether the result is >100 or <100 or equal to 100 */
/* the program should ask for the input until 'q' is enterd */
// Check for possible logical errors and rectify them 

// Total number of bugs: 14


#include<stdio.h>

int main(void){
  float num1, num2, result;
	char input;  
  while(input != 'q'){

  printf("Welcome to the Calculator\nOperation choices:\tAddition(A)\n\t\t\tSubtraction(S)\n\t\t\tMultiplication(M)\n\t\t\tDivision(D)\nEnter choice: ");
   scanf("%c", &input);
  if(input = "A" || input == 'S' || input == 'M' || input == 'D'){
    printf("Enter both numbers in required sequence: ");
    scanf("%f%f",&num1, &num2);
  
    switch(input){
      case 'A': 
        result = num1 + num2;
        break;  
      case 'S': 
        result = num1 -  num2;
	break;
      case 'M': 
        result = num1 * num2;
      	break; 
      case 'D': 
        result = num1 /  num2; 
        break;
      default:	
	break;	
    }

    if(result >100){
      printf("Greater than 100.\n");
    } else{
      printf("Less than 100.\n");
    }
  
  }else{
    printf("Please choose a valid operation\n");
  }
	
  printf("Quit the menu by selecting q.\n"); 
scanf("%c",input);
return(0);
}
}
