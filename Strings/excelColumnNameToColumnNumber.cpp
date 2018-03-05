#include<iostream>
#include<string.h>


using namespace std;

int getColumnNumber(string colName)
{
    int i=0;
    int res = 0;
    for(const auto& a : colName)
    {
        res = res*26 + a -'A' + 1;
    }
    //cout<<res<<endl;
    return res;
}

int main()
{
    while(1)
    {
        string str;
        getline(cin,str);
        cout<<getColumnNumber(str)<<endl;
    }
}
