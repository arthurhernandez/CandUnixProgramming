/* Print the sum of all multiples of 3 and multiples of 8 from 0 to 100 
*  Print all the characters from 'A' to 'Z' in the reverse order 
*  Total number of bugs : 16
*/

#include <stdio.h>

int main(){

    int i, limit = 100, sum = 0;
    char c; 

    printf("The value of limit is %d\n", limit);

    for(i = 0; i <= limit; i++){

       if(i%3 == 0){
           sum +=  i;
       }
       if(i%8 == 0){
           sum +=  i;
       }
       
    }

    printf("\nSum = %d \n", sum);

    for(c = 'Z'; c >= 'A'; c--){
            printf("%c ", c);
            printf(", ");
    }
    
    return 0;
}
//33
//12
