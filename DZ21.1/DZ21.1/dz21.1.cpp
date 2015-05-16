#include <iostream>
#include <stdlib.h>

using namespace std;
class Person
{
private:
	char name[32];
	int age;
	char gender[8];
	char tel_number[16];
public:

	void fname()
	{
		cout<<"Enter name:";
		gets(name);
	}
	void fage()
	{
		cout<<"Enter age:";
		cin>>age;
	}
	void fgender()
	{
		cout<<"Enter gender:";
		cin>>gender;
		getchar();
	}
	void ftel_number()
	{
		cout<<"Enter tel number:";
		cin>>tel_number;
		getchar();
	}
	void print()
	{
		cout<<"Name:"<<name<<"\n"
			<<"Age:"<<age<<"\n"
			<<"Gender:"<<gender<<"\n"
			<<"Phone number:"<<tel_number<<"\n";
	}
};
int main()
{
	Person obj;
	obj.fname();
	obj.fage();
	obj.fgender();
	obj.ftel_number();
	obj.print();
}