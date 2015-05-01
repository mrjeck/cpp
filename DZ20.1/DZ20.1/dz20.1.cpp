#include <iostream>
#include <windows.h>
using namespace std;
class Counter
{
	int count;
	int countmin;
	int countmax;

	public: 
		Counter(int min,int max)
		{
			countmin=min;
			count=countmin;
			countmax=max;
		}
		void counting ()
		{
			++count;
			if(count>countmax)
				count=countmin;
		}
		void showcount()
		{
			cout<<count;
		}
		int two;
};

int main (void)
{
	int min,max;
	cout<<"Enter initial value:";
	cin>>min;
	cout<<endl;
	cout<<"Enter the final value:";
	cin>>max;

	Counter clock(min,max);
	while(1)
	{
		system("cls");
		clock.counting ();
		clock.showcount();
		Sleep(200);
	}
	return 0;
}