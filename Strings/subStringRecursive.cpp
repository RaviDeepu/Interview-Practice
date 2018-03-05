#include<iostream>
#include<string.h>


using namespace std;


bool exactMatch(char *text, char *pat)
{
    if (*text == '\0' && *pat != '\0')
        return false;
 
    // Else If last character of pattern reaches
    if (*pat == '\0')
        return true;
 
    if (*text == *pat)
        return exactMatch(text + 1, pat + 1);
 
    return false;
}
 
// This function returns true if 'text' contain 'pat'
bool contains(char *text, char *pat)
{
    // If last character of text reaches
    if (*text == '\0')
        return false;
 
    // If current characts of pat and text match
    if (*text == *pat)
        return exactMatch(text, pat);
 
    // If current characts of pat and tex don't match
    return contains(text + 1, pat);
}


int main()
{   
    char mainStr[]="RaviGiri";
    char pattern[]="iri";

    cout<<contains(mainStr,pattern)<<endl;

}
