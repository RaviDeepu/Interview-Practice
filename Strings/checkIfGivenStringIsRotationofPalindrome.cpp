#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string str)
{
    int len = str.length();
    int i=0,j=len-1;
            
    while( i < j)
    {
        if(str[i] != str[j])
            return false;

        i++;
        j--;
    }

    return true;
}

void checkIfStringIsRotationOfPalindrome(string str)
{
    int len = str.length();

    for(int i=0 ; i<len ; ++i)
    {
        string s1 = str.substr(0,i+1);
        string s2 = str.substr(i+1,len-i-1);
        cout<<s2<<" , "<<s1<<endl;
        if(isPalindrome(s2.append(s1)))    
        {
            cout<<"Yess : "<<s1<<" , "<<s2<<" are Palindrome "<<endl;
            return;
        }
    }
    cout<<"NoooOOOOooo"<<endl;
}

int main()
{
    string str = "aaaad";
    int n = str.length();

    checkIfStringIsRotationOfPalindrome(str);

    /*
    for(int i=0 ; i<n-1 ; ++i)
    {
        cout<<str.substr(0,i+1)<<endl;
        cout<<str.substr(i+1,n-i-1)<<endl;
    }
    */
}
