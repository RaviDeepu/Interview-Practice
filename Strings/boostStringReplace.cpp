#include<boost/algorithm/string.hpp>
#include<iostream>

using namespace std;


int main()
{
    string str("Ravi++++Giri");
    boost::replace_all(str,"+"," ");

    cout<<str<<endl;
}
