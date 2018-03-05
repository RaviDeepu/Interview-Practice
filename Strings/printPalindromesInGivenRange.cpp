#include<iostream>


using namespace std;

void printPalindromes(int min, int max)
{
    int n=0,res=0;
    for(int i=min ; i<max ; ++i)
    {
        res = 0;
        n = i;
        while(n != 0)
        {
            res = res*10 + n%10;
            n = n/10;
        }

        if(res == i)
            cout<<"Palindrome - "<<res<<endl;
    }
}

int main()
{
    int min, max;
    while(1)
    {
        cout<<"Enter Min & Max\n";
        cin>>min>>max;
        printPalindromes(min,max);
    }
}
