#include<iostream>
#include<string>

using namespace std;


// abcd

void compressString(string str)
{
    string res;

    int resCounter=0,count=1;
    char tempChar,prevChar;
    bool hash[256] = {0};
    
    tempChar = str[0];
    res[resCounter++] = tempChar;

    hash[tempChar] = 1;

    for(int i=1 ; i<str.length() ; ++i)
    {
        prevChar = tempChar;
        tempChar = str[i];
        if(hash[tempChar] == 1)
        {
            count++;
        }
        else
        {
            res[resCounter++] = count + '0';
            res[resCounter++] = tempChar;
            count=1;
            hash[tempChar] = 1;
            hash[prevChar] = 0;
        }
    }

    res[resCounter++] = count+'0';
    res[resCounter++]='\0';
    cout<<res.c_str()<<endl;


}

int main()
{
    while(1)
    {
        string str;
        cout<<"Enter tring\n";
        cin>>str;
        compressString(str);
    }
}
