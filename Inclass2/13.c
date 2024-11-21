#include <stdio.h> 
#include <string.h>

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
void getInput (){
    char input[100];
    while (1)
    {
    printf("Enter a string to check digit or not (type END to stop): ");
    scanf("%s",input);
    if(strcmp(input,"END") == 0) {
        break;
    }
      if(isAllDigit(input)) {
        printf("All digit\n"); 
    } else {
        printf("Not all digit\n"); 
    }   

    }
    
}
int main()  
{  
getInput();
} 
