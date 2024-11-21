#include <stdio.h> 
int isAllDigit (char str[]) 
{ 
    int i = 0;
    while(str[i] != '\0') {
        if((str[i] < '0') || (str[i] > '9')){
            return 0;
        }
        i++;
    }
    return 1;
} 
int main()  
{  
char someString[10] = "123456";  
if (isAllDigit(someString)) 
printf("All digit"); 
else 
printf("Not all digit");  
return 0;  
} 
