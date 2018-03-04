#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


class Person
{
	char *pname;
	int page;
	public:
		Person():pname(0),page(0)
		{
		}
		
		Person(char* name,int age):pname(new char[strlen(name)+1]),page(age)
		{
			strcpy(pname,name);
		}

		void display()
		{
			cout<<"Name : "<<pname<<"  Age : "<<page<<endl;
		}
};



class RC
{
		int count;
	public:
		void AddRef()
		{
			count++;
		}

		int Release()
		{
			return --count;
		}
};


template<typename T>
class SP
{
		T *ptr;
		RC *reference;
	public:
		SP(T *p = 0):ptr(p),reference(0)
		{
			reference = new RC();
			reference->AddRef();
		}

		SP(SP<T>& obj)
		{
			ptr=obj.ptr;
			reference=obj.reference;
			reference->AddRef();
		}

		SP& operator=(SP<T> &obj)
		{
			if(this != &obj)
			{
				if(reference->Release() == 0)
				{
					delete ptr;
					delete reference;
				}			
				
				ptr=obj.ptr;
				reference=obj.reference;
				reference->AddRef();
			}
			return *this;
		}


		T& operator*()
		{
			return *ptr;
		}

		T* operator->()
		{
			return ptr;
		}
};



