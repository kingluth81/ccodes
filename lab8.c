#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int num;
bool prime;

int readNum () {  //to read the input
   int num;
    printf ("Enter a number: ");
    scanf ("%d", &num);
  
       if (num < 0) {
        printf ("Error: Invalid character.\n"); //for errors
    }
  return num;
}

int sumDigits (int num) { //to get the sum of digits

  int extra, sum = 0;

  while (num)
    {
      extra = num % 10;
      sum += extra;
      num /= 10;
    }
    printf("Sum of digits is %d.\n", sum); //output of sum of digits
    return sum;
}

bool isPrime (int num) { //bool value for prime check
    
  bool _flag=true; //initializes bool as true 
  
  if (num<=1) {
      _flag=false;
  }

  for (int i = 2; i < num; i++) //checks if num is prime
    {
      if (num % i == 0) {
	  _flag=false;
	  break;
	}
    }
    return _flag;
}

int main ()
{
  int num = readNum ();
  int sum = sumDigits (num);
  bool prime = isPrime (num);
  
  if (prime) { //checks if bool value of prime is true or false
      printf("It is a prime number.");
  } else printf("It is not a prime number.");
  return 0;
}