#include<iostream>
#include<vector>
#define MAX_CHAR 256

using namespace std;

char* removeDuplicates(char *s)
{
    int ipIndex=0,resIndex=0;
    //int count[MAX_CHAR] = {0};
    vector<int> count (MAX_CHAR,0);
    int i=0;
    while(s[ipIndex])
    {
        if(count[s[ipIndex]] == 0)
        {
            s[resIndex] = s[ipIndex];
            resIndex++;
        }
        count[s[ipIndex]] = 1;
        ipIndex++;
    }

    s[resIndex] = '\0';

    return s;

}

int main()
{
    char str[]="Amadeus";
    
    cout<<removeDuplicates(str)<<endl;
}
