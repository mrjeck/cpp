#include <iostream>
#include <string.h>


using namespace std;
  
    class Student
{
  protected:
    char name [30];
	char adres[50];
    int course;   
    int ID;  
public:
	Student()
	{
		strcpy(name,"Vasiliy");
			strcpy(adres,"Kharkov");
			course=5;
			ID=123;
	}
};


class Aspirant  : public Student
{   
protected:
    char *theme; 
public:
	Aspirant()
	{
	strcpy(theme,"Theme");
	}



	void DisplayInfo()    
   {
     cout<<"Name: "<<name<<endl;
       cout<<"Course: "<<course<<endl;
        cout<<"ID: "<<ID<<endl;
		cout<<"Theme:"<<theme<<endl;
}

};
void main()
{

}