#include<iostream>
#include<stdlib.h>


using namespace std;

char printSecondFrequentCharacter(char str[])
{
    int count[256] = {0};
        
    int i=0;
    while(str[i])
    {
        count[str[i]]++;
        i++;
    }

    int first=0,second=0;
    for(int i=0 ; i<256 ; ++i)
    {
        if(count[i] > first)
        {
            second = first;
            first = i;
        }
        else if(count[i] > second)
        {
            second = i;
        }
    }

    return second;

}

int main()
{
    char str[]="ravi";
    
    char res = printSecondFrequentCharacter(str);
    
    if(res != '\0')
        cout<<"Second character is : "<<res<<endl;    
    else
        cout<<"No Second character\n";
}   
