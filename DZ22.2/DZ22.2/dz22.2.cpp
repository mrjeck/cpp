#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class String
{
	char* strng;
	int len;

public:

	String()
	{
		len=80;
		strng=new char[len+1];
		cin>>strng;
	}
	String(int size,char* st):len(size),strng(st)
	{
		strng = new char[len+1];
		strcpy(strng,st);
	}
	String(char* Strng)
	{
		len=strlen(Strng);
		strng = new char[len+1];
		strcpy(strng,Strng);
	}
	String(const String &s)
	{
		len=s.len;
		strng = new char[len+1];
		strcpy(strng,s.strng);
	}
	~String()
	{
		delete [] strng;
	}
	void scan ()
	{
		char st[256];
		gets(st);
		len=strlen(st);
		delete [] strng;
		strng=new char[len+1];
		strcpy(strng,st);
	}
	char* operator* (String str)
	{
		int counter=0,count;
		char* sumstr=NULL;
		char* buffer=NULL;
		for(int i=0;i<len;++i)
		{
			count=0;
			for(int j=0;j<str.len;++j)
			{
				if(strng[i]==str.strng[j])
				{
					++count;
				}
			}
			if(count>0&&sumstr!=NULL)
			{
				for(int j=0;j<counter;++j)
				{
					if(strng[i]==sumstr[j])
					{
						count=0;
						continue;
					}
				}
			}
			if(count>0)
			{
				++counter;
				if(sumstr!=NULL)
				{
					buffer=sumstr;
					sumstr=new char[counter+1];
					for(int j=0;j<counter-1;++j)
						sumstr[j]=buffer[j];
					sumstr[counter-1]=strng[i];
					sumstr[counter]='\0';
					delete[]buffer;
				}
				else
				{
					sumstr=new char[counter+1];
					sumstr[counter-1]=strng[i];
					sumstr[1]='\0';
				}
			}
		}
		return sumstr;
	}
	void print()
	{
		cout<<strng<<endl;
	}
};
int main()
{
	String s1("qsqtbgbyinuinjuyiym");
	String s2("qweqsbwsyiyiyyyyyymybnu");
	cout<<s1*s2<<endl;
	return 0;
}
