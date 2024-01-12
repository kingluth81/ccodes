#include <stdio.h>
int main(void) {
	
	int count, error;
	float sum, num;
	char option;
	
	count=1;
	sum=0;
	error=0;
	
	for (count = 1;count>=1;count +=1) { //loop statement for data collection
		
		printf("Enter a number: ");
		scanf("%f", &num);
		
		if (num<0) {
			num=0; //makes negative numbers insignificant
		}
		
		sum=sum+num; //gets the sum of the previous sum and the new number
		
		printf("Exit (Y/N)?\n"); //asks user if they want to exit the loop
		scanf(" %c", &option);
		
		while ( (option != 'Y') && (option != 'N')) { //if character entered is invalid, new loop starts till valid character is entered
			
			error++;
			printf("Invalid character.\nExit (Y/N)?\n");
			scanf(" %c", &option);
			
		}
		
		if (option == 'Y') { //ends the loop if user answers yes to exit statement
			break; //ends loop
		}
	}
	
	printf("Sum of the positive numbers = %.2f , Count = %d\n", sum, count); //prints the output of data
	printf("You've made %d errors.",error); // number of times invalid characters entered
	
	return 0;
}