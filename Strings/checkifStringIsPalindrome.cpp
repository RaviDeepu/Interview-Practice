#include<iostream>
#include<string.h>

using namespace std;

void checkPalindrome(char* s)
{
    int len = strlen(s) - 1;
    int i = 0;    
    
    while(i < (len/2))
    {
        if(s[i] != s[len-i])    
        {
            cout<<"NOoooooOOoooo"<<endl;
            return;
        }
        i++;
    }
    cout<<"YesssSSSsssss"<<endl;
}

int main()
{
    char* str = "MADAMA";
    checkPalindrome(str);
}
