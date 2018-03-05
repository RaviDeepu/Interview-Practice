#include<iostream>
#include<string.h>
#define NO 0
#define YES 1

using namespace std;

/*

It will have two states
YES - The previous character is "a"
No - The previous character is not "a" 
*/

void removeBandAC(char str[])
{
    int state = NO;
    int resIndex = 0;

    for(int i=0 ; i<strlen(str) ; ++i)
    {
        if(state == NO && str[i] != 'a' && str[i] != 'b')
        {
            str[resIndex++] = str[i];
        }
    
        if(state == YES && str[i] != 'c')
        {
            // Fill a
            str[resIndex++] = 'a';

            if(str[i] != 'a' && str[i] != 'b')
            {
                str[resIndex++] = 'a';
            }
        }

        state = (str[i] == 'a') ? YES : NO;
    }

    if(state == YES)
    {
        str[resIndex++] = 'a';
    }
    
    str[resIndex] = '\0';
    

}

int main()
{
    char str[] = "ababac";
    removeBandAC(str);;
    cout<<str<<endl;
}
