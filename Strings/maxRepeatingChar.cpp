#include<iostream>
#include<stdlib.h>

using namespace std;

int* getCharCountArray(char *s)
{
	int *count = (int*)calloc(256,sizeof(int));
	for(int i=0;*(s+i);i++)
	{
		count[*(s+i)]++;
	}
	return count;
}

int maxRepeatingChar(char *s)
{
	int max=0;
	int *count = getCharCountArray(s);
	max=count[0];
	for(int i=0;*(s+i);i++)	
	{
		if(count[*(s+i)] > max)
			max=i;
	}
	return max;
}

int main()
{
	char str[]="banana";
	int index = maxRepeatingChar(str);
	cout<<"Max Repeating Char : "<<str[index]<<endl;
	
}
