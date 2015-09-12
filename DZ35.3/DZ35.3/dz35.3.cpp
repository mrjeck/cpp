#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Student
{
public:
	string FirstName;
	string LastName;
	int Course;

	Student(string AFirstName, string ALastName, int ACourse) :
		FirstName(AFirstName), LastName(ALastName), Course(ACourse) {};

	friend ostream & operator << (ostream &s, const Student & ss)
	{
		s.setf(ios::left);
		return s << setw(6) << ss.FirstName 
			     << setw(9) << ss.LastName 
				 << setw(8) << ss.Course 
			     << endl;
	}
};


void FillVector(vector<Student> &a)
{
	a.push_back(Student("Jerry", "Klinton", 5));
	a.push_back(Student("Laura", "Simpson", 2));
	a.push_back(Student("Amy", "Smith", 4));
	a.push_back(Student("Jeb", "Brown", 3));
	a.push_back(Student("John", "Gates", 1));
}

template<class C>
void print(C& c) 
{
	typename C::iterator it;

	for(it = c.begin(); it != c.end(); it++)
		cout << *it;
  
	cout << endl;
}

bool LessFirstName(const Student & s1, const Student & s2)
{
	return s1.FirstName < s2.FirstName;
}

bool GreaterLastName(const Student & s1, const Student & s2)
{
	return s1.LastName > s2.LastName;
}

bool LessCourse(const Student & s1, const Student & s2)
{
	return s1.Course < s2.Course;
}

int main()
{
	vector<Student> a;
	FillVector(a);
	vector<Student> b(a);

	cout << "Original vector" << endl;
	print(a);

	sort(a.begin(), a.end(), LessFirstName);
	cout << "Vector sorted by first name in asc order" << endl;
	print(a);

	a = b;
	stable_sort(a.begin(), a.end(), GreaterLastName);
	cout << "Vector stable sorted by last name in desc order" << endl;
	print(a);

	a = b;
	partial_sort(a.begin(), a.begin()+3, a.end(), LessCourse);
	cout << "Vector partial (3 elemenst) sorted by course in asc order" 
		 << endl;
	print(a);
	
	return 0;
}