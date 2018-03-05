#include<iostream>
#include<stdio.h>
#define NO_OF_CHARS 256
using namespace std;

int main()
{
     char str[] = "geeksforgeeks";
    
     for(int i=0;i<NO_OF_CHARS;++i)
     {
         printf("%d, %c\n",i,i);
     }
    
     //printf("%s", removeDups(str));
     //getchar();
     return 0;
}
