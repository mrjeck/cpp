#include <iostream>
#include <stdio.h>

using namespace std;

class Dynamic_array
{
	int* arr;
	int size;
	public:
	Dynamic_array()
	{
		arr=nullptr;
		size=0;
	}
	Dynamic_array(Dynamic_array &obj)
	{
		size=obj.size;
		arr=new int[size];
		for(int i=0;i<size;++i)
		arr[i]=obj.arr[i];
	}
	~Dynamic_array()
	{
		if(!arr)
		{
			delete(arr);
		}
	}
	void add(int number)
	{
		if(!arr)
		{
			arr=new int;
			arr[size]=number;
			++size;
		}
		else
		{
			int* buffer;
			int* arr2=new int[size+1];
			for(int i=0;i<size;++i)
			arr2[i]=arr[i];
			arr2[size]=number;
			++size;
			buffer=arr;
			arr=arr2;
			delete(buffer);
		}
	}
	void sub()
	{
		if(arr)
		{
			if(size==1)
			{
				delete(arr);
				arr=nullptr;
			}
			else
			{
			int* buffer;
			int* arr2=new int[size-1];
			for(int i=0;i<size;++i)
			arr2[i]=arr[i];
			buffer=arr;
			arr=arr2;
			delete(buffer);
			}
		}
	}
	int &operator[] (int i)
	{
		if(i<size)
		return arr[i];
		else
		{
			cout<<"\nError "<<"arr["<<i<<"] going beyond the array\n";
			exit(EXIT_FAILURE);
		}
			
	}
	void operator= (int i)
	{
		 arr[i]=i;
	}
	int operator+ (int i)
	{
		return arr[i]+i;
	}
	void operator++ ()
	{
		int i;
		cin>>i;
		add(i);
	}
	void operator-- ()
	{
		sub();
	}
};
int main()
{
	Dynamic_array m;
	
	for(int i=0;i<10;++i)
	{
		m.add(i);
	}
	for(int i=0;i<20;++i)
	{
		cout<<m[i]<<"  ";
	}
	
return 0;
}