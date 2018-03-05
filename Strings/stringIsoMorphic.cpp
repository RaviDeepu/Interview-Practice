#include<iostream>
#include<string.h>

using namespace std;


bool checkAreIsomorphic(string s1,string s2)
{
    // Check if the string x is visited or not.
    bool marked[256] = {false};

    // Map the string isoMorphic contents
    int map[256] = {-1};


    for(int i=0;i<256;++i)
        map[i] = -1;;

    if(s1.length() != s2.length())
    {
        cout<<"Different Sizesn\n";
        return false;
    }

    
    int i=0,j=0;
    while(s1[i] && s2[i])
    {

        // s1[i] is occuring first time.
        if(map[s1[i]] == -1)
        {
            // If s1[i] is already marked then retuen false;
            if(marked[s1[i]] == true)
            {
                cout<<s1[i]<<" is already marked. So returning FALSE\n";
                return false;
            }
            
            map[s1[i]] = s2[j];
            marked[s1[i]] = true;
        }
        else // If s[i] is occuring second time then check if it has the same mapping
        {
            if(map[s1[i]] != s2[j])
            {
                cout<<"Error is mapping of "<<s1[i]<<" and "<<s2[j]<<endl;
                return false;
            }
        }
        i++;
        j++;
    }

    return true;
}



int main()
{
    string s1;
    string s2;

    cout<<"Enter Main String\n";
    getline(cin,s1);

    cout<<"Enter Mapped String\n";
    getline(cin,s2);

    if(checkAreIsomorphic(s1,s2))
        cout<<s1<<" , "<<s2<<" are IsoMorphic\n";
    

}
