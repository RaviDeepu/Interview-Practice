#include <iostream>
#include <limits.h>

using namespace std;


int getMaxProfit(int a[], int n)
{
    int totalProfit = 0;
    int sigleProfit = 0;
    int minElement = a[0];
    int buy,sell;
    int i=0;
    while(i < n-1)
    {
        while(i < n-1 && (a[i] >= a[i+1] ))
        {
            i++;
        }

        if(i >= n-1)
            break;

        buy = a[i];

        i++;

        while(i<n-1 && a[i] <= a[i+1])
        {
            i++;
        }


        sell = a[i];
        i++;

        totalProfit += (sell - buy);
        cout<<"Buy @ "<<buy<<", Sell @ "<<sell<<" , Profit = "<<(sell - buy)<<endl;;
    }
    return totalProfit;
}

int main()
{
    int a[]={3,7,4,6,8,2,1,9};
    int size = sizeof(a)/sizeof(a[0]);

    cout<<"Max Profit : "<<getMaxProfit(a,size)<<endl;
}
