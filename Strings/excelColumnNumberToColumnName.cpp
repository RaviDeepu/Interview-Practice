#include<iostream>
#include<string.h>

using namespace std;

void reverse(char* str)
{
    int len = strlen(str)-1;
    int i=0;

    while(i < len)
    {
        char temp = str[i];
        str[i] = str[len-i];
        str[len-i] = temp;
        i++;
    }
    cout<<"Reversed colName : "<<str<<endl;
}

char* getColumnName(int colNumber)
{
    int res=0;
    char colName[50];
    int i=0;

    while(colNumber > 0)
    {
        int rem = colNumber%26;

        if(rem == 0)
        {
            colName[i] = 'Z';
            colNumber = (colNumber/26)-1;
        }
        else
        {
            colName[i] = (rem-1)+'A';
            colNumber = colNumber/26;
        }
        i++;
    }
    colName[i]='\0';
    reverse(colName);
    cout<<"ColName - "<<colName<<endl;
    return colName;
}

int main()
{
    int colNumber;

    while(1)
    {
        cout<<"Enter Column Number\n";
        cin>>colNumber;

        cout<<getColumnName(colNumber)<<endl;
    }
}
