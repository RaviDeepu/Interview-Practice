#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

void getComputersCustomers(string cList, int noOfComputers)
{
    int occupied = 0;
    /*
        seen[i] = 0 // If i is seen first time.
        seen[i] = 1 // If i is in cafe but not yet assigned the computer
        seen[i] = 2 // If i is in cafe and assigned a computer.
    */

    int seen[256] = {0};
    int i=0;

    vector<char> v;

    while(cList[i])
    {
        // If cList[i]  is seen first time
        if(seen[cList[i]] == 0)
        {
            seen[cList[i]] = 1;
            if(occupied < noOfComputers)
            {
                occupied++;
                seen[cList[i]] = 2;
            }
            else
            {
                v.push_back(cList[i]);
            }
        }        
        else
        {
            if(seen[cList[i]] == 2)
            {
                occupied--;
            }
            seen[cList[i]] = 0;
        }
        
        i++;
    }

    for(auto a:v)
    {
        cout<<a<<" Could not get computer"<<endl;
    }
}


int main()
{   
    string cList;
    int noOfComputers;
    cout<<"Enter the Customer List\n";
    getline(cin,cList);
    
    cout<<"Enter no of Customers\n";
    cin>>noOfComputers;
    getComputersCustomers(cList, noOfComputers);


}
