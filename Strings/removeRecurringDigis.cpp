#include<iostream>
#include<string.h>

using namespace std;

void removeRecurringDigits(string& str)
{
    int resIndex=0;
    int i=0;
    
    for(int i=0 ; i<str.length() ; ++i)
    {
        str[resIndex++] = str[i];
        
        while(i < str.length() && str[i] == str[i+1])
            i++;

    }
    str[resIndex] = '\0';
}

int main()
{
    string s;
    while(1)
    {
        getline(cin,s);
        removeRecurringDigits(s);
        cout<<s.c_str()<<endl;
    }
}
