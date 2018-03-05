#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int max(int a, int b)
{
    return ( a > b ? a: b);
}

int longestValidSubstringParanthesis(string s)
{
    stack<int> stack;

    stack.push(-1);
    
    int i = 0;
    int res = 0;

    while(s[i])
    {
        if(s[i] == '(')
        {
            stack.push(i);
        }
        else if(s[i] == ')')
        {
            stack.pop();
            if(!stack.empty())
                res = max(res,i-stack.top());
            else // Push something as base value.
                stack.push(i);
        }

        i++;
    }    

    return res;
}

int main()
{

    string s;
    getline(cin,s);
    cout<<"Length of LongestSubStringParanthesis is : "<<longestValidSubstringParanthesis(s)<<endl;
}
