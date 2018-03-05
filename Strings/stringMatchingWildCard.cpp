#include<iostream>
#include<string.h>

using namespace std;


// **

bool testWildCard(char* wildCardStr, char* mainStr)
{
    if(*wildCardStr == '\0' && *mainStr == '\0')
        return true;

    
    // If WildCard contains * then mainStr must contain anything after that.
    if(*wildCardStr == '*' && *(wildCardStr+1) != '\0' && *mainStr == '\0')
        return false;

    // If wildCard contains ? then it cam move one step.
    if(*wildCardStr == '?' || *wildCardStr == *mainStr)
        return testWildCard(wildCardStr+1,mainStr+1);

    // If wildCard contains * then there are two possibilities.
    // Consider current character of mainStr
    // Ignore current character of mainStr
    
    if(*wildCardStr == '*')
        return testWildCard(wildCardStr+1,mainStr) || testWildCard(wildCardStr, mainStr+1);
   
    return false; 

}

int main()
{
    if(testWildCard("g*k","geek"))
        cout<<"YESSSSSSS\n";
    else
        cout<<"NOooooOOooo\n";
}
