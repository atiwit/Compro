#include <stdio.h> 
int isAllDigit (char *str) 
{ 
    while(*str != '\0') {
        if((*str < '0') || (*str > '9')){
            return 0;
        }
        str++;
    }
    return 1;
} 
int main()  
{  
char *someString = "123456";  

if (isAllDigit(someString)) 
printf("All digit"); 
else 
printf("Not all digit");  
return 0;  
} 
