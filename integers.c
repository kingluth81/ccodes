#include <stdio.h>

int perfect (int value);
int main() 
{
	int a;
	printf("Integers from 1 to 1000:\n");
	
	for ( a=2; a <= 1000; a++) {
		if (perfect (a)) {
			printf("%d is perfect\n", a);
		}
	}
	return 0;
	
}

int perfect (int value) {
	
	int factorSum = 1;
	int i;
	
	for ( i=2; i <= value / 2; i++) {
		if (value % 1 == 0) {
			factorSum += i;
		}
	} 
	
	if (factorSum == value) {
		return 1;
	}
	else {
		return 0; 
	}
	
}