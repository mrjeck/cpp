#include <iostream>
#include <stdlib.h>

using namespace std;

class Date
{
	int day;
	int month;
	int year;
	int Month[12];
	int days;
public:
	Date(int d,int m,int y):day(d),month(m),year(y),days(0)
	{
		Month[0]=30;
		Month[1]=28;
		Month[2]=31;
		Month[3]=30;
		Month[4]=31;
		Month[5]=30;
		Month[6]=31;
		Month[7]=31;
		Month[8]=30;
		Month[9]=31;
		Month[10]=30;
		Month[11]=31;
		days=(year-year/4)*365+(year/4)*366;
		for(int i=0;i<month;++i)
		{
			if(!(year%4)&&i==1)
			{
				days+=29;
				continue;
			}
			days+=Month[i];
		}
		days+=day;
	}
	int operator- (Date obj)
	{
		if(days>obj.days)
		return days-obj.days;
		else
		return obj.days-days;
	}
	void operator+ (int Days)
	{
		int remain;
		days+=Days;
		day=0;
		month=0;
		year=days/365.25;
		remain=days-((year-year/4)*365+(year/4)*366);
			for(int i=0;i<12;++i)
			{
				if(!(year%4)&&i==1&&(remain-Month[i]>0))
						{
							remain-=29;
							++month;
							continue;
						}
				if(remain-Month[i]>0)
				{
					remain-=Month[i];
					++month;
				}
				else
					{
						if(!i)
							++month;
						break;
					}
			}
			day=remain;
	}
	void print()
	{
		cout<<days<<endl;
		cout<<day<<"."<<month<<"."<<year<<endl;
	}
};

int main()
{
	int days;
	Date D(22,12,2020);
	Date Z(5,11,2000);
	days=D-Z;
	D.print();
	D+10;
	D.print();
	return 0;
}