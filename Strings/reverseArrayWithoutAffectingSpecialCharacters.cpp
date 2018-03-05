#include<iostream>
#include<string.h>

using namespace std;

bool isAlphabet(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}



void reverseString(string& s)
{
    int i=0,j=s.length()-1;

    while(i<j)
    {
        while(!isAlphabet(s[i]))
            i++;
        
        while(!isAlphabet(s[j]))
            j--;

        if(i < j)
        {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        
            i++;
            j--;
        }
    }
}


int main()
{
    string s="AB@C*DQ";
    cout<<"Before - "<<s<<endl;
    reverseString(s);
        
    cout<<"After : "<<s<<endl;
}
