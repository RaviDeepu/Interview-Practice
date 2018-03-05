#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


// hashTable[i] stores all characters that correspond to digit i in phone
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};


void printStringUtil(char data[], int index, int number[], int len)
{
    if(index == len)
    {
        cout<<data<<endl;
    }
    else
    {
        for(int i=0;i<strlen(hashTable[number[index]]);++i)
        {
            data[index] = hashTable[number[index]][i];
            printStringUtil(data,index+1,number,len);
        }
    }
}

void printString(int number[], int size)
{

    cout<<"Stelen - "<<strlen(hashTable[number[0]])<<endl;
    char *data = (char*) malloc(sizeof(char) * strlen(hashTable[number[0]]));

    printStringUtil(data, 0, number, size);
}

int main()
{
    int number[]={2,3,4};
    
    int size = sizeof(number)/sizeof(number[0]);

    printString(number,size);

}
