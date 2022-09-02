// Program to read integers into a 3X3 matrix and display them
// Number of errors/bugs = 11


#include <stdio.h>
void display(int Matrix[3][3],int size);

int main(void) {
	int size=3;
	int Matrix[size][size];
	printf("Enter 9 elements of the matrix:\n");
	int i;
	for (i = 0; i < size; i++){
      		int j = 0;
      		for (; j < size; j++){
        		scanf(" %d", &Matrix[i][j]);      		}
    	}
	display(Matrix,3);
	return 0;
}

void display(int Matrix[3][3],int size) {
	int i;	
	for ( i = 0; i < size; i++) {
		int j;	
		for (j = size; j >= 0; j--) 
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
	}    
}
