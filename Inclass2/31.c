#include <stdio.h> 
int findStringLength (char str[]) 
{ 
     int length = 0;
     while (str[length] != '\0') {
        length++;
     }
     return length;
} 
int findSubString (char str1[], char str2[]) 
{ 
     int l1 = findStringLength(str1);
     int l2 = findStringLength(str2);

     for (int i = 0; i <= l1 - l2; i++) {
        int j;
        for ( j = 0; j< l2; j++)
        {
            if(str1[i+j] != str2[j]) {
                break;
            }
        }
        if (j == l2)
        {
           return i;
        }        
     }
     return -1;
} 
int main()  
{  
     char string1[100], string2[100]; 
     printf("Enter the main string: ");
     scanf("%s",string1);
     printf("Enter the substring to find: ");
     scanf("%s",string2);

     int output = findSubString(string1,string2);
     if (output != -1) 
          printf("Index of the first occurrence = %d\n", output); 
     else 
          printf("string2 is not a substring of string1"); 
     return 0;
 }