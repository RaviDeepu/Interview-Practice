#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


using namespace std;

void mystrrev(char* str)
{
    int len = strlen(str)-1;
    int i = 0;

    cout<<"Before Reversed : "<<str<<endl;
    while(i <= (len/2))
    {
        char temp = str[i];
        str[i] = str[len-i];
        str[len-i] = temp;

        i++;
    }
    cout<<"Reversed String in Function : "<<str<<endl;

}

char* myItoA(int n)
{
    int numCount = 0;
    int tempNumber = n, res=0;
    while(tempNumber != 0)
    {
        tempNumber/=10;
        numCount++;
    }

    int negative = 0;
    if(n<0)
    {
        numCount++;
        negative = 1;
        n = n * -1;
    }

    int i=numCount-1;
    char* charNumber = (char*) malloc(sizeof(char)*numCount+1);
    charNumber[numCount] = '\0';
    
    cout<<"Num Count : "<<numCount<<endl;

    tempNumber = n;
    while(n != 0 )
    {
        tempNumber = n%10;
        cout<<"TempNumber : "<<tempNumber<<endl;

        charNumber[i--] = tempNumber + '0';
        n = n/10;
        cout<<"N : "<<n<<endl;
    }
    
    //mystrrev(charNumber);

    cout<<" i : "<<i<<endl;
    if(negative)    
        charNumber[i] = '-';

    return charNumber;

}

int main()
{
    while(1)
    {
        int n;
        cout<<"Enter Number : "<<endl;
        cin>>n;

        cout<<"Itoa of : "<<n<<" , is : "<<myItoA(n)<<endl;

    } 
}
