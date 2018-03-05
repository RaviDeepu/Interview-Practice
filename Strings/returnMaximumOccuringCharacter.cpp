#include<iostream>
#define MAX_CHAR 256
using namespace std;

char returnMaxOccuringChar(string s)
{
    int count[MAX_CHAR] = {0};
    
    // Build Count Array
    int i=0;
    while(s[i])
    {
        count[s[i]]++;
        i++;
    }

    char maxChar;
    int max=-1;

    i=0;
    while(s[i])
    {
        if(count[s[i]] > max)
        {
            max = count[s[i]] ;
            maxChar = s[i] ; 
        }
        i++;
    }

    //cout<<"Max Occuring Cha"
    return maxChar;

}

int main()
{
    string str = "RRavRi iGiri";
    cout<<"Max Occuring Char - "<<returnMaxOccuringChar(str)<<endl;;
}
