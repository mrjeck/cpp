#include<iostream>
#include<windows.h>
using namespace std;
class Group
{
	char group[50];
public:
	void Inpgroup()
	{
		cout<<"Введите группу: \n";
		gets(group);
		OemToCharA(group,group);
	}
	void Show()
	{
		cout<<"Группа: "<<group<<endl;
		cout<<endl;
	}
};
class Student
{
	char name[50];
	char fam[50];
	int age;
public:
	void Show()
	{
		cout<<"Фамилия: "<<fam<<endl;
		cout<<"Имя: "<<name<<endl;
		cout<<"Возраст: "<<age<<endl;
	}
	void Inpfam()
	{
		cout<<"Введите фамилию студента: \n";
		gets(fam);
		OemToCharA(fam,fam);
	}
	void Inpname()
	{
		cout<<"Введите имя студента: \n";
		gets(name);
		OemToCharA(name,name);
	}
	void Inpage()
	{
		cout<<"Введите возраст: \n";
		cin>>age;
		cin.ignore(1);
	}
};
void main()
{
	setlocale(LC_CTYPE,"Rus");
	int n=0,a=0,key;
	Student obj[100];
	Group gr[100];
	do
	{
		cout<<"1. Добавить студента в группу\n2. Показать базу студентов.\n0. Выход\n";
		cin>>key;
		cin.ignore(1);
		switch(key)
		{
		case 1:
			gr[n].Inpgroup();
			obj[n].Inpfam();
			obj[n].Inpname();
			obj[n].Inpage();
			n++;
			system("pause");
			system("cls");
			break;
		case 2:
			if(n==0)
				cout<<"База студентов пуста, вначале введите их\n";
			else
			{
				for(int i=0;i<n;i++)
				{
					obj[i].Show();
					gr[i].Show();
				}
			}
			system("pause");
			system("cls");
			break;
		case 0:
			break;
		default:
			cout<<"Выбран неправильный пункт меню\n";
			break;
		}
	}while(key!=0);

}