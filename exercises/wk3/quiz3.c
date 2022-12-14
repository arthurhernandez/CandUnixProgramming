/* Instructions:
 *
 *
 1. Write a program to assign a grade to Student. 
	Get the number of assignmnets from user.
  Get the students score out of how many points for each assignmnet.
	Calculate percentage and return the grade associated with a range of marks.
 2. The overall score range and the associated grades are as follows:
     a. [97-100] = A+
     b. [90-97] = A
     c. [80-90] = B
     d. [70-80] = C
     e. less than 70 is a failing grade and should be given an F
     e. greater than 100 or less than 0 is invalid and your code should print "Invalid"
 3. Use the skeleton code provided below to create a new function "printGrade" to assign a grade based on the score ranges.
 4. Use print statements in your function to display the grade. For example, if the input marks is 77, the output should read:
        "Your grade is : C"
 5. Please adhere to standard C syntax conventions and use comments to explain your code. Failure to do so will result in a penalty.
 *
 *
 * */
#include<stdio.h> 
void printGrade(int);
//really takes in percent
void printGrade(int score){
    //if score is an A+
    if(score <= 100 && score >= 97){
        printf("Your overall score is an A+");
    }
    //if score is an A+
    else if(score >= 90){
        printf("Your overall score is an A");
    }   
    //if score is an A+
    else if(score >= 80){
        printf("Your overall score is an B");
     }
     //if score is an A+
    else if(score >= 70){
        printf("Your overall score is an C");
    }
    //if score is an A+
    else if (score >= 0){
        printf("Your overall score is an F");
    }
    //if score is an A+
    else{
        printf("Invalid");
    }

}
//returns int
int main(void){
        char ch;
        float score;
        int assignments;
        do {
            	printf("How many assignmnets did you have ? ");
    //get the number of assignmnets from the student
                scanf(" %d",&assignments);

                
    //get the student's score and the max score for each assignment
                int i;
                //holds the assignments max score fore each assignment 
                float totalScore;
                float assignmentScore;
                //iterates through for the number of assignemnts 
                for(i = 1; i <= assignments;i++){
                    //students score for each assignmnet
                    printf("Enter your score for assignment %d: \n",i);
                    scanf(" %f", &score);
                    // max score for each assingment 
                    printf("Enter the max score for assignment %d: \n",i);
                    scanf(" %f", &assignmentScore);
                    totalScore += score / assignmentScore * 100;
		   
                }
    //calculate the student's percentage in the class using the information you've gathered)
                int percent = totalScore / assignments;
                printGrade(percent);
                printf("\n would you like to start again? enter Y yes or N no");
                scanf(" %c", &ch);
		totalScore = 0;
        } while(ch == 'y'|| ch == 'Y');
return 0;
}

