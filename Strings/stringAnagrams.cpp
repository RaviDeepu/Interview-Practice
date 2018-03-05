#include<iostream>
#include<string.h>

using namespace std;



bool areAnagrams(char* str1, char* str2)
{
    int countArray[256] = {0};

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 != len2)
        return false;

    int i=0;
    while(str1[i] && str2[i])
    {
        countArray[str1[i]]++;
        countArray[str2[i]]--;
        i++;
    }


    for(int j=0 ; j<256 ; ++j)
    {
        if(countArray[j])   
            return false;
    }

    return true;
    
}


int main()
{
    char str1[] = "geeksforgeeks";
    char str2[] = "forgekksgeeks";

    cout<<str1<<endl;
    cout<<str2<<endl;

    if(areAnagrams(str1,str2))
        cout<<"Yesssss"<<endl;
    else
        cout<<"NoooOOOoooo"<<endl;
}
