//67070501048 Atiwit
#include <stdio.h>

long int factorial (int n)
{
     int i;
     long int product = 1;
     //ถ้า i=n > 1 ให้ คูณiลดลงไปทีละ1กับproduct
     for (i = n; i>1; i--)
          product *= i;
     return product;
}

// Write your function here
long int combination (int n,int r)
{
     long int cal;
        cal = factorial(n)/(factorial(n-r)*factorial(r)); //ncr
     return cal;
}

int main() 
{ 
     int n, r;
     long int ans;
     printf("To calculate nCr, enter n and r: "); 
     scanf("%d %d", &n, &r); 
     ans = combination(n, r); 
     printf("\n%dC%d = %ld", n, r, ans);
     return 0; 
}