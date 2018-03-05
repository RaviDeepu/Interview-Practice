#include<iostream>
#include<string.h>

using namespace std;


void printPatternFromMain(char *str, int i, int n)
{
    while(i<n)
    {
        cout<<str[i];
        i++;
    }       
    cout<<endl; 
}

void checkSmallWindow(char* mainStr, char* patStr)
{
    int hashMainStr[256] = {0};
    int hashPatStr[256] = {0};

    int i=0;
    while(patStr[i])
    {
        hashPatStr[patStr[i]]++;  
        i++;
    }
    i = 0;
    int count = 0;
    int start=0;
    int startIndex=0;
    int minLength = 100000000;
    while(mainStr[i])
    {
        cout<<"Checking : "<<mainStr[i]<<endl;
        // Increment the current main string in the Main hash.
        hashMainStr[mainStr[i]]++;

        // Increment the count If the character is present in pattern & if the cur char count in hashMain is less than in hashPat
        if(hashPatStr[mainStr[i]] != 0 && hashMainStr[mainStr[i]] <= hashPatStr[mainStr[i]])
        {
            cout<<"Incrementing Count\n";
            count++;
        }
        
        if(count == strlen(patStr))
        {
            cout<<"Count Matched\n";
            while((hashMainStr[mainStr[start]] > hashPatStr[mainStr[start]]) || (hashPatStr[mainStr[start]] == 0))
            {
                if(hashMainStr[mainStr[start]] > hashPatStr[mainStr[start]])
                {
                    hashMainStr[mainStr[start]]--;
                    cout<<"Rmeoving Unwanted Chars\n";
                    cout<<"Removing this : "<<mainStr[start]<<endl;
                }
                start++;
            }   
            int tempLength = i - start + 1;
            if(minLength > tempLength)
            {
                minLength = tempLength;
                startIndex = start;
            }
        }
        i++;
    }
    cout<<"Start : "<<start<<" , MinLength : "<<minLength<<endl;
    printPatternFromMain(mainStr, start, minLength);
}

int main()
{
    char* mainStr = "this is a test string";
    char* patStr = "tist";

    checkSmallWindow(mainStr,patStr);
}


