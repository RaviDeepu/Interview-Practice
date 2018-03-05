#include<iostream>
#define MAX_CHAR 256

using namespace std;

void removeCharsFromFirstStr(string firstStr, string secondStr)
{
    int count[MAX_CHAR] = {0};
    int i=0;
    while(secondStr[i])
    {
        count[secondStr[i]]++;
        i++;
    }
    
    cout<<"First Str : "<<firstStr<<endl;
    cout<<"Second Str : "<<secondStr<<endl;
    int ipIndex=0, resIndex=0;
    while(firstStr[ipIndex])
    {
        if(count[firstStr[ipIndex]] == 0)
        {
            firstStr[resIndex] = firstStr[ipIndex];
            resIndex++;
        }
        ipIndex++;
    }
    cout<<"Res Index - "<<resIndex<<endl;
    firstStr[resIndex] = 0;
    cout<<"First Str : "<<firstStr<<endl;
}


int main()
{
    string firstStr = "Ravi Prakash Giri";
    string secondStr = "Giri";

    removeCharsFromFirstStr(firstStr,secondStr);
}
