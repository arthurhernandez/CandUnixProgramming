// The factorial of an integer is the product of the number with all
// the positive integers below it.

// For example: Factorial of 5 = 5 * 4 * 3 * 2 * 1 = 120

// Number of errors/bugs = 6
#include<stdio.h>
int factorial(int number);
int main(void) {
	int n,fact;
	printf("Debugging Practice 1 - Quiz 3, Q3\n\n");
	printf("Please enter the number whose factorial you wish to find: ");
	scanf(" %d", &n);
	fact = factorial(n);
	printf("The factorial of %d is %d \n", n, fact);
}

int factorial(int number) {
  if(number == 0){
    return 1;
  }else{
    return number * factorial(number-1);
  }
}


 

