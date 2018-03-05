#include<iostream>

using namespace std;

int myAtoi(char* str)
{
    int res = 0;
    int neg = 0,i=0;
    if(str[0] == '-')
    {
        neg = 1;
        i++;
    }
    
    while(str[i])
    {
        res = res*10 + str[i] - '0';
        i++;
    }
    
    if(neg)
        res = res*-1;

    return res;
    
}

int main()
{
    while(1)
    {
        char str[100];
        cout<<"Enter Any Number : "<<endl;
        cin>>str;
        //char *str = "-128";
        cout<<"Atoi of "<<str<<" , is : "<<myAtoi(str)<<endl;
    }
}
