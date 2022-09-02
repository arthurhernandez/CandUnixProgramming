#include <stdio.h>
//Arthur Hernandez
//C291 Assignemnt 2
//Tuesday April 7th
int main(){
//paycode tests paycode from menu
// typeofstudent tests international or domestic for AI's
char paycode, typeOfStudent;
// numofemployees is the number for each paycode and num of products sold for piece workers is whole integers
int numOfEmployees, numOfProductSold;
// hours worked and the wage can be a double including the all the totals after being inputted
double  hoursWorked, workerWage, pricePerProduct, totalInternational = 0, totalDomestic = 0, totalHourly = 0, totalCommision = 0, totatPiece = 0;
    //stays in loop while paycode is not q
    do{
	//menu takes in what type of worker or if the user would like to quit ONLY
       	printf("------------------Menu------------------ \n");
        printf("Please enter a pay code or \"Q\" to quit \nList of Paycodes: \nPay code for AI's - W \nPay code for hourly workers - H\nPay code for commsission workers - C\nPay code for Piece workers - P\n");
        printf("------------------Menu------------------ :");
        scanf(" %c", &paycode);
	//switch takes the paycode and applies it unless it is not correct then it will output default invalid and restart
	switch(paycode){
		//case AI
        	case 'W':
            	case 'w':
			//this will be the same in every switch other than default. 
			// takes how many employees
                	printf("Please enter the number of employees for this paycode:");
                	scanf(" %d", &numOfEmployees);
			// same in all cases as well. checks there is more than 2 employees 
                	if(numOfEmployees < 2){
                	    printf("Must have a minimum of 2 employees\n");
                    	    break;
                	}
                	int i;
			//runs through the number of employees
                	for(i = 1; i <= numOfEmployees; i++){
                    		do{	
					//scans for facts needed to determine pay of worker
                       		        printf("For employee number %d please enter \"D\" for domestic student or \"I\" for international:",i);
                        		scanf(" %c", &typeOfStudent);
                       			printf("For employee number %d please enter number of hours worked:",i);
                        		scanf("%lf", &hoursWorked);
                        		printf("For employee number %d please enter the workers wage:", i);
                        		scanf("%lf", &workerWage);
					// decides wether each student worker is a domestic or international student
                        		if(typeOfStudent == 'D' || typeOfStudent == 'd'){
                            		    totalDomestic += hoursWorked * workerWage;
                        		}
                        		else if (typeOfStudent == 'I' || typeOfStudent == 'i')
                       			{
                            			if(hoursWorked > 20){
                               				totalInternational += 20 * workerWage;
                           			}else{
                                			totalInternational += hoursWorked * workerWage;
                            			}
                        		}
					//if not either, the code entered was invalid, try again
                        		else{
                            			printf("INVALID STUDENT TYPE PLEASE TRY AGAIN -------- \n ");
                        		}
				//will not terminate unless the codes entered for each student are vaild
				// only time a while is used in a while or any conditional loop. 
                    		}while (typeOfStudent != 'D' && typeOfStudent != 'd' && typeOfStudent != 'I' && typeOfStudent != 'i');
                	}
                	break;
		//Hourly workers
            	case 'H':
            	case 'h':
                	printf("Please enter the number of employees for this paycode:");
                	scanf(" %d", &numOfEmployees);
                	if(numOfEmployees < 2){
                    		printf("Must have a minimum of 2 employees\n");
                    		break;
                	}
                	int j;
                	for(j = 1;j<=numOfEmployees; j++){
                    		//gets the amount of hours worked and the workers wage.
				printf("For employee number %d please enter number of hours worked:",j);
                    		scanf("%lf", &hoursWorked);
                    		printf("For employee number %d please enter the workers wage:", j);
                    		scanf("%lf", &workerWage);
				//if hours worked is more than 10, the first 10 will be payed regularly and anything over that 1.5 times as much per hour
                        	if(hoursWorked > 10){
                            		totalHourly += 10 * workerWage;
                            		hoursWorked -= 10;
                            		totalHourly += (hoursWorked * workerWage) * 1.5;
				//worked less than 10 hours that week
                        	}else{
                            		totalHourly += hoursWorked * workerWage;
                        	}
                	}
                	break;
		//Commision workers
            	case 'c':
           	case 'C':	
                	printf("Please enter the number of employees for this paycode:");
                	scanf(" %d", &numOfEmployees);
                	if(numOfEmployees < 2){
                   		printf("Must have a minimum of 2 employees");
                    		break;
                	}
                	int k;
                	for(k = 1; k <= numOfEmployees; k++){
				//only gets the workers gross hourly wage as they are paid by commision 
                    		printf("For employee number %d please enter the workers wage:",k);
                    		scanf("%lf", &workerWage);
                    		totalCommision += 250 + (workerWage * 7.1);
                	}
                	 break;
		//pieceworkers
            	case 'P':
            	case 'p':
                	printf("Please enter the number of employees for this paycode:");
                	scanf("%d", &numOfEmployees);
                	if(numOfEmployees < 2){
                	    printf("Must have a minimum of 2 employees\n");
                    	    break;
                	}
                	int l;
                	for(l = 1; l <= numOfEmployees; l++){
				//gets how many products the employee sold that week and how much he will be payed per product
                    		printf("For employee number %d please enter the amount of product sold by the worker:", l);
                    		scanf(" %d", &numOfProductSold);
                    		printf("Please enter the amount of money that will be paid per product for worker  number %d:",l);
                    		scanf("%lf", &pricePerProduct);
                    		totatPiece += numOfProductSold * pricePerProduct;
                	}
                	break;
		//quit case just breaks the switch 
            	case 'Q':
            	case 'q':
                	break;
		//default case reports that a correct paycode or q was not inputted
            	default:
                	printf("INVALID PASSCODE PLEASE TRY AGAIN\n");
                	break;
        }
	//these conditions will stay after each iteration in the while loop until q is inputted
    	printf("Weekly salary paid to workers who are international students: $%lf\n", totalDomestic);
    	printf("Weekly salary paid to workers who are domestic students: $%lf\n", totalInternational);
    	printf("Weekly salary paid to AI's: $%lf\n", totalDomestic+totalInternational);
    	printf("Weekly salary paid to hourly workers: $%lf\n", totalHourly);
        printf("Weekly salary paid to commision workers: $%lf\n", totalCommision);
        printf("Weekly salary paid to piece workers: $%lf\n", totatPiece);
	printf("Total weekly salary paid to all workers $%lf\n", (totalCommision+totalDomestic+totalHourly+totalInternational+totatPiece));
    }while(paycode != 'Q' &&  paycode != 'q');
return 0;
}




