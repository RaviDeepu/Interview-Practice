#include<iostream>


using namespace std;

void swap(char* a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char *str,int l, int r)
{
    if(l == r)
    {
        cout<<str<<endl;
    }
    else
    {
        for(int i=l;i<=r ; ++i)
        {
            swap(&str[i],&str[l]);
            permute(str,l+1,r);
            swap(&str[i],&str[l]);
        }
    }
}


int main()
{
    char str[]="ABC";
    
    permute(str,0,2);
}
