#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#define PI 3.14

using namespace std;

class Circle
{
protected:
	double radius;
public:
	Circle(double _radius):radius(_radius)
	{}
	virtual ~Circle()
	{}
	virtual double GetRadius()
	{
		return radius;
	}
	virtual double GetPer()
	{
		return 2*PI*radius;
	}
	virtual void SetInfo(double _radius){radius=_radius;}
};
class Square
{
protected:
	double a;
public:
	Square(double _a):a(_a)
	{}
	virtual ~Square()
	{}
	double GetA()
	{
		return a;
	}
	virtual double GetArea(){return a*a;
	}
	virtual void SetInfo(double _a)
	{
		a=_a;
	}
};
class CinS:public Circle, public Square
{
public:
	CinS(double _radius, double _a):Circle(_radius),Square(_a)
	{}
	~CinS(){}
	virtual void SetInfo(double _radius, double _a)
	{
		a=_a;
		radius=_a/2;
	}
	double GetRadius(){return radius;
	}
	double GetArea(){return PI*(radius*radius);
	}
	double GetPer(){return 2*PI*radius;
	}
};
int main()
{
	Circle Ob1(0);
	int s=0;
	cout<<"Enter radius of the circle\n";
	cin>>s;
	Ob1.SetInfo(s);
	cout<<"For circle with radius: "<< Ob1.GetRadius() <<'\n';
	cout<<"Perimetr: "<< Ob1.GetPer() <<'\n';
	cout<<"\n";
	Square Ob2(0);
	int d=0;
	cout<<"Enter side of the square\n";
	cin>>d;
	Ob2.SetInfo(d);
	cout<<"For square with side: "<< Ob2.GetA() <<'\n';
	cout<<"Area is: "<< Ob2.GetArea() <<'\n';
	cout<<"\n";
	CinS Ob3(0,0);
	int f=0;
	cout<<"Enter side of square\n";
	cin>>f;
	Ob3.SetInfo(f/2,f);
	cout<<"For square with side: "<< Ob3.GetA() <<" and circle with radius: "<< Ob3.GetRadius() <<'\n';
	cout<<"Perimetr of circle is: "<< Ob3.GetPer() <<'\n';
	cout<<"Area of circle is: "<< Ob3.GetArea() <<'\n';
	return 0;
}