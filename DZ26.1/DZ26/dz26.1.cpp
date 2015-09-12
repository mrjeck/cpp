#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <time.h>
#include <windows.h>

using namespace std;

class cylinder
{
	int size;
	
public:
	int* arr;
	cylinder(int* a, int s) :size(s)
	{
		arr = new int[size];
		for (int i = 0; i < size;++i)
			arr[i] = a[i];
	}
	~cylinder()
	{
		delete[]arr;
	}
	void shift()
	{
		int first = arr[0];
		for (int i = 1; i < size; ++i)
			arr[i - 1] = arr[i];
		arr[size - 1] = first;
	}
	void reset()
	{
		while(arr[0]!=1)
		{
			shift();
		}
	
	}
};

void show(int* arr1,int* arr2,int* arr3,char* str)
	{
		cout<<" ---------------------------\n";
		cout<<"|                           |\n";
		cout<<"|                           |\n";
		cout<<"|       "<<" ---"<<" ---"<<" ---"<<"        |\n";;
		cout<<"|       |"<<" "<<arr1[7]<<" "<<"|"<<" "<<arr2[7]<<" "<<"|"<<" "<<arr3[7]<<" "<<"|"<<"       |\n";
		cout<<"|        "<<"---"<<" ---"<<" ---"<<"        |\n";
		cout<<"|      >|"<<" "<<arr1[0]<<" "<<"|"<<" "<<arr2[0]<<" "<<"|"<<" "<<arr3[0]<<" "<<"|"<<"<      |\n";
		cout<<"|        "<<"---"<<" ---"<<" ---"<<"        |\n";
		cout<<"|       |"<<" "<<arr1[1]<<" "<<"|"<<" "<<arr2[1]<<" "<<"|"<<" "<<arr3[1]<<" "<<"|"<<"       |\n";;
		cout<<"|       "<<" ---"<<" ---"<<" ---"<<"        |\n";;
		cout<<"|                           |\n";
		cout<<"|---------------------------|\n";
		cout<<"|         |"<<str<<"|        |\n";
		cout<<"|         ----------        |\n";
		cout<<"|                           |\n";
		cout<<"|                           |\n";
		cout<<"|                           |\n";
		cout<<" --------------------------- \n";
	}

int main()
{
	int barrel[8]={1,2,3,4,5,6,7,8},turnover1,turnover2,turnover3;
	cylinder bar1(barrel,8);
	cylinder bar2(barrel,8);
	cylinder bar3(barrel,8);
	char *str=new char[9];
	char menu;
	srand(time(NULL));
	cout<<"Press enter";
	while(1)
	{
	menu=getch();
	if(menu==13)
	{
					system("cls");
					turnover1=rand()%20+1;
					turnover2=rand()%20+1;
					turnover3=rand()%20+1;
					strcpy(str,"########");
					while(turnover1||turnover2||turnover3)
					{
						
					show(bar1.arr,bar2.arr,bar3.arr,str);
					Sleep(100);
					system("cls");
					if(turnover1)
						{
						bar1.shift();
						--turnover1;
						}
					if(turnover2)
						{
						bar2.shift();
						--turnover2;
						}
					if(turnover3)
						{
							bar3.shift();
							--turnover3;
						}
					}
					if(*bar1.arr==*bar2.arr&&*bar2.arr==*bar3.arr)
							strcpy(str,"YOU WIN!");
						else
							strcpy(str,"YOU LOSE");
					show(bar1.arr,bar2.arr,bar3.arr,str);
	}
	else if(menu==32)
		{
			bar1.reset();
			bar2.reset();
			bar3.reset();
			system("cls");
			strcpy(str,"########");
			show(bar1.arr,bar2.arr,bar3.arr,str);
		}
	else if(menu==27)
		{
			system("cls");
			break;
		}
	}
	delete(str);
	return 0;
}