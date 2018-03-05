#include<iostream>
#include<stdlib.h>
#include<string.h>

#define N 0
#define E 1
#define S 2
#define W 3


/*

            N
            |
            |
            |
            |
 W ---------------------E
            |
            |
            |
            |
            S

*/

using namespace std;

void checkIfPathCircular(string s)
{
    int x=0,y=0;

    int dir=N;
    int i=0;

    while(s[i])
    {
        char move = s[i];

        if(move == 'R')
            dir = (dir+1)%4;
        else if(move == 'L')
            dir = (4+dir-1)%4;
        else
        {
            // G 
            if(dir == N)
                y++;
            else if(dir == E)
                x++;
            else if(dir == S)
                y--;
            else if(dir == W)
                x--;
        }
        i++;
    }
    if(x == 0 && y == 0)
        cout<<"Circular\n";
    else
        cout<<"Not Circular\n";
}


int main()
{
    //string path = "GLGLGLG";
    string path = "GGLGLGGLG";
    checkIfPathCircular(path);
}
