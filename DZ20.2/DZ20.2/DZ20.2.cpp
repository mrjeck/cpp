#include<iostream>
#include<windows.h>
using namespace std;
class Group
{
	char group[50];
public:
	void Inpgroup()
	{
		cout<<"������� ������: \n";
		gets(group);
		OemToCharA(group,group);
	}
	void Show()
	{
		cout<<"������: "<<group<<endl;
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
		cout<<"�������: "<<fam<<endl;
		cout<<"���: "<<name<<endl;
		cout<<"�������: "<<age<<endl;
	}
	void Inpfam()
	{
		cout<<"������� ������� ��������: \n";
		gets(fam);
		OemToCharA(fam,fam);
	}
	void Inpname()
	{
		cout<<"������� ��� ��������: \n";
		gets(name);
		OemToCharA(name,name);
	}
	void Inpage()
	{
		cout<<"������� �������: \n";
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
		cout<<"1. �������� �������� � ������\n2. �������� ���� ���������.\n0. �����\n";
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
				cout<<"���� ��������� �����, ������� ������� ��\n";
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
			cout<<"������ ������������ ����� ����\n";
			break;
		}
	}while(key!=0);

}