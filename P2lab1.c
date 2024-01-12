// COMP 1410
// Due: 01/24/19

#include <stdio.h>
#include <math.h>

//Declaration of Non Recursive functions
void fun1n(int n);
void fun2n(int n);
void Fibonaccin(int n);
void GCDn(int x,int y);
void Powern(int a,int b);
void displayn(int j, int k);
void DrawTrianglen(int n);

// Declaration of Recursive functions
int fun1r(int n);
int fun2r(int n);
int Fibonaccir(int n);
int GCDr(int x,int y);
int Powerr(int a,int b);
int displayr(int j, int k);
int DrawTriangler(int n);
 

int main(void)
{
    int d = 0; // initialize d for users desired question
	
   // Displays options a user can choose from 
    printf("Press 1 for non-recursive factorial function\n");
    printf("Press 2 for non-recursive summation function\n");
    printf("Press 3 for non-recursive Fibonacci function\n");
	printf("Press 4 for non-recursive GCD\n");
	printf("Press 5 for non-recursive power function\n");
	printf("Press 6 for non-recursive display positive integers function\n");
	printf("Press 7 for non-recursive DrawTriangle function\n");
	printf("Press 8 for recursive factorial function\n");
	printf("Press 9 for recursive summatoin function\n");
	printf("Press 10 for recursive Fibonacci function\n");
	printf("Press 11 for recursion GCD function\n");
	printf("Press 12 for recursive power function\n");
	printf("Press 13 for recursive display positive integers function \n");
	printf("Press 14 for recursive DrawTriangle function\n");
	
	printf("0 - EXIT\n");
 
    printf("Press one number from the menu above or press 0 to EXIT if not in the mood!: ");
    scanf("%d",&d);

    while(d != 0)
	{
        // if statement to assign each Non-recursive/Recursive questions to a number
		if(d==1) {
			int n = 0;
            printf("Enter n value: ");
            scanf("%d",&n);
			fun1n(n);
		}
           
        if(d==2) {
			int n=0;
            printf("Enter n value: ");
            scanf("%d",&n);
			fun2n(n);
		}
        
        if(d==3) {
			int n=0;
        	printf("Enter a value:");
	        scanf("%d",&n);
			Fibonaccin(n);
		}
            
        if(d==4) {
			int x, y =0;
            printf("Enter two integers: ");
            scanf("%d %d", &x, &y);
            GCDn(x,y);
		}
       
        if(d==5) {
			int a, b =0;
            printf("Enter base and power intergers: ");
            scanf("%d %d", &a, &b);
			Powern(a,b);
		}
		
		if (d==6) {
			int j, k = 0;
			printf("Enter two integers > 0: ");
			scanf("%d %d", &j, &k);
			displayn(j,k);
		}
       
        if(d==7) {
			int n=0;
            printf("Enter desired triangle range.:");
            scanf("%d",&n);
			DrawTrianglen(n);
		}
        
        if(d==8) {
			int n=0;
            printf("Enter n value: ");
            scanf("%d",&n);
			printf("%d\n",fun1(n));
		}
       	
        if(d==9) {
			int n = 0;
            printf("Enter n value: ");
            scanf("%d",&n);
            printf("%d\n",fun2r(n));
		}
        
        if(d==10) {
			 int n = 0;
            printf("Enter a value: ");
            scanf("%d",&n);
            printf("%d\n",Fibonaccir(n));
		}
      
        if(d==11) {
			int x, y =0;
            printf("Enter two integers: ");
            scanf("%d %d",&x,&y);
            printf("The GCD for %d and %d is--> %d\n",x,y,GCDr(x,y));
		}
          
        if(d==12) {
			int a, b =0;
            printf("Enter base and power integers: ");
            scanf("%d %d",&a,&b);        
			printf("%d\n",Powerr(a,b));
		}
        	
		if (d==13) {	
		}
			
        if(d==14) {
			int n=0;
            printf("Enter desired triangle range.:");
            scanf("%d",&n);
			DrawTriangler(n);
		}
        
        
    //To keep the loop running until user press 0 to exit
    printf("Press 1 for non-recursive factorial function\n");
    printf("Press 2 for non-recursive summation function\n");
    printf("Press 3 for non-recursive Fibonacci function\n");
	printf("Press 4 for non-recursive GCD\n");
	printf("Press 5 for non-recursive power function\n");
	printf("Press 6 for non-recursive positive integers function\n");
	printf("Press 7 for non-recursive DrawTriangle function\n");
	printf("Press 8 for recursive factorial function\n");
	printf("Press 9 for recursive summation function\n");
	printf("Press 10 for recursive Fibonacci function\n");
	printf("Press 11 for recursion GCD function\n");
	printf("Press 12 for recursive power function\n");
	printf("Press 13 for recursive positive integers function \n");
	printf("Press 14 for recursive DrawTriangle function\n");
	
	printf("0 - EXIT\n");
 
    printf("Press one number from the menu above or press 0 to EXIT if not in the mood!: ");
    scanf("%d",&d);
	}
         
}

// Non-recursive factorial function   
void fun1n(int n) {
	int d = 0; 

    for(int i = 1; i<=n ;i++)
    {
		d = d + i;
	}
	
    printf("Factorial of %d is %d\n",n,d);
    printf("\n");
}

// Non-recursive summation function 
void fun2n(int n) {
	int d = 0;
	
	for (int i = 1; i<=n ;i++)
    {		
		d = d + (i+1)*(i+1);
	}
	
    printf("Summation of %d is %d\n",n,d);
    printf("\n");
}

//Non-recursive Fibonacci function
void Fibonaccin(int n) {
	int f, a = 0;
    int b = 1;
	
	printf("Fibonacci value if the %dth element-->",n);    
	
	for (int i = 2; i<=n; i++)
    {
		f = a + b;
		a = b;
		b = f;		
	}
    
    printf("%d",b);
    printf("\n");
}
// Non-recursive GCD function
void GCDn(int x,int y) {
	int gcd;

    for(int i=1; i <= x && i <= y; ++i)
    {
        // Checks if i is factor of both integers
        if(x%i==0 && y%i==0)
            gcd = i;
    }

    printf("gcd of %d and %d is %d", x, y, gcd);
    printf("\n");
}

// Non-recursive power function
void Powern(int a,int b) {
	int result = 1;
    for (int i = 1; i <= b; i++)
    {
        result = result * a;  
    }
    printf("Your result is %d",result);
    printf("\n");
}


// Non-recursive display function
void displayn(int j, int k) {
	for (int i=1; i<k; i++) {
		if (i%j==0) {
			printf("Positive value is %d", i);
			printf("\n");
		}
	} 
}


// Non-recursive DrawTriangle funtion
void DrawTrianglen(int n) {
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j<= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

// Recursive factorial function
int fun1(int n) {
	if (n == 1)
    {
        return 1;
    }
    else
    return n + fun1(n-1);
    printf("\n");
}

// Recursive summation function
int fun2r(int n ) {
	if (n == 1)
    {
    return 4;
    }
    else
    return (1 + n)*(1 + n) + fun2r(n-1);
    printf("\n");
}

// Recursive Fibonacci function
int Fibonaccir(int n) {
	if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return Fibonaccir(n-1) + Fibonaccir(n-2);
    }
    printf("\n");
}

// Recursive GCD function
int GCDr(int x,int y) {
	if (y != 0)
       return GCDr(x, x%y);
    else 
       return x;
    printf("\n"); 
}

// Recursive power function
int Powerr(int a,int b) {
	if (b != 0)
        return a * Powerr(a,b-1);
    else
        return 1;
    printf("\n"); 
}

// Recursive DrawTriangle function
int DrawTriangler(int n) {
	if (n == 1)
    {
        // prints first * in first row
        printf("*\n");
    }
    else
    {

        // printds next row of *
        DrawTriangler(n - 1);

        // print a row of *'s
        for(int i = n; i > 0; i--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}