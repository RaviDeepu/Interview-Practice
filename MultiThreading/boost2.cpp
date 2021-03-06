#include<boost/thread.hpp>

using namespace std;

class CallableClass
{
private:
// Number of iterations
int m_iterations;
 
public:
 
// Default constructor
CallableClass()
{
m_iterations=10;
}
 
// Constructor with number of iterations
CallableClass(int iterations)
{
m_iterations=iterations;
}
 
// Copy constructor
CallableClass(const CallableClass& source)
{
m_iterations=source.m_iterations;
}
 
// Destructor
~CallableClass()
{
}
 
// Assignment operator
CallableClass& operator = (const CallableClass& source)
{
m_iterations=source.m_iterations;
return *this;
}
 
// Static function called by thread
static void StaticFunction()
{
for (int i=0; i < 10; i++)  // Hard-coded upper limit
{
cout<<i<<"Do something in parallel (Static function)."<<endl;
boost::this_thread::yield(); // 'yield' discussed in section 18.6
}
}
 
// Operator() called by the thread
void operator () ()
{
for (int i=0; i<m_iterations; i++)
{
cout<<i<<" - Do something in parallel (operator() )."<<endl;
boost::this_thread::yield(); // 'yield' discussed in section 18.6
}
}
 
};


int main()
{
boost::thread t(&CallableClass::StaticFunction);
usleep(300); 
for (int i=0; i<10; i++)
{
cout<<i<<" - Do something in main method."<<endl;
}
 
return 0;
}

