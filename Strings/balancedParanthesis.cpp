#include<iostream>
#include<string.h>
#include<stack>


using namespace std;

bool isDigitOrAlphabet(char c)
{
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
        return true;
    
    return false;
}

bool isMatchingPair(char c1, char c2)
{
    if(c1 == '(' && c2 == ')')
        return 1;
    else if(c1 == '{' && c2 == '}')
        return 1;
    else if(c1 == '[' && c2 == ']')
        return 1;

    return 0;
}

bool isBalancedParanthesis(char* str)
{
    stack<char> s;

    int i=0;
        
    while(str[i])
    {
        char item = str[i];
        cout<<"Item : "<<item<<endl;

        if(isDigitOrAlphabet(item))
        {
            cout<<"Digit : "<<item<<endl;
            i++;
        }
        else if((item == '(' || item == '{' || item == '['))
        {
            s.push(item);
            i++;
        }
        else // It is a closing bracket
        {
            
            if(s.empty())
                return false;

            if(!isMatchingPair(s.top(),item))
                return false;

            s.pop();
            i++;
        }
    }
    
    if(!s.empty())
    {
        cout<<"Stack is Not empty : "<<endl;
        return false;
    }

    return true;

}

int main()
{
    while(1)
    {
        char str[100];
        cout<<"Enter Paranthesised String\n";
        cin>>str;

        if(isBalancedParanthesis(str))
            cout<<"Yesssssss\n";
        else
            cout<<"NoooOOooo\n";
    }
}

