#include<iostream>
#include<string.h>

using namespace std;

void removeSpaces(string& str)
{
    int k=0,i=0;
    //int len = strlen(str);
    while(str[i])
    {
        if(str[i] != ' ')
        {
            str[k] = str[i];
            k++;
        }
        i++;
    }
    str[k]='\0';
}

int main()
{
    while(1)
    {   
        string str;
        cout<<"Enter String\n";
        getline(cin,str);
        //cin>>str;
        removeSpaces(str);
        cout<<"After Removing spaces : "<<str<<endl;
    }
}
