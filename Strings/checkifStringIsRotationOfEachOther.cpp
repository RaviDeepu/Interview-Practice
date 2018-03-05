#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void concat(char dest[], char src[])
{
    while(*dest)
        dest++;

    while(*dest++ = *src++);
}

int subString(char firstStr[], char secondStr[])
{
    int mLen = strlen(firstStr);
    int sLen = strlen(secondStr);

    for(int i = 0; i<mLen ; ++i)
    {
        int j;
        for(j=0 ; j<sLen ; ++j)
        {
            if(secondStr[j] != firstStr[i+j])
                break;
            else
                cout<<"Same - "<<secondStr[j]<<" , "<<firstStr[i+j]<<endl;
        }
    
        if(j == sLen)
        {
            return i;
        }
    }
    return -1;
    
}

void checkifStringAreRotation(char firstStr[], char secondStr[])
{

    char *temp = (char*) malloc(sizeof(char)*(strlen(firstStr)*2));

    concat(temp, firstStr);
    concat(temp, firstStr);

    cout<<"Concatenated : "<<temp<<endl;
    cout<<"First Str : "<<firstStr<<endl;
    cout<<"Second Str : "<<secondStr<<endl;
        
    int index = subString(temp, secondStr);

    if(index != -1)
    {
        cout<<"Found - at Index : "<<index<<endl;
    }
    else
    {
        cout<<"Not Found\n";
    }

}


int main()
{
    char s1[]="ABCD";
    char s2[]="CDABC";

    checkifStringAreRotation(s1,s2);
}
