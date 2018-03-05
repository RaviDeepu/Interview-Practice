#include<iostream>
#include<string.h>


using namespace std;

void printSubStr(char* str, int start, int maxLength)
{
    for(int i=start;i<maxLength;++i)
    {
        cout<<str[i];
    }
    cout<<endl;
}

void printLongestSubstring(char* str)
{
    int len = strlen(str);
    int low,high,start=-1;
    int maxLength = 1;
    for(int i=1 ; i<len ; ++i)
    {
        cout<<"i : "<<i<<endl;
        // Search for Even length SubString
        low = i;
        high = i+1;
        while(low >= 0 && high < len && str[low] == str[high])
        {
            cout<<"ODD - str[low] : "<<str[low]<<" , str[high] : "<<str[high]<<endl;
            if(high-low+1 > maxLength)
            {
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
            cout<<"Low - "<<low<<" , High : "<<high<<endl;
        }

        // Search for Odd length Substring
        low = i-1;
        high = i+1;
        while(low >= 0 && high < len && str[low] == str[high])
        {
            cout<<"EVEN - str[low] : "<<str[low]<<" , str[high] : "<<str[high]<<endl;
            if(high-low+1 > maxLength)
            {
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }

    printSubStr(str,start,maxLength);
    
}

int main()
{
    char* str = "geeksskeegfor";
    
    printLongestSubstring(str);
}

