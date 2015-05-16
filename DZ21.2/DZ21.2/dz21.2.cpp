#include <iostream>
#include <stdio.h>
using namespace std;
class String{
   private:
   char *data;
   int max_length;
   public:
   String()
   {
        data=new char[80];
        max_length=80;
   }
   String(int i)
   {
       data = new char[i];
       max_length=i;
   }
    String(const String &s)
    {
        if (max_length < s.max_length)
        {
            delete [] data;
            data=new char[s.max_length];
            max_length=s.max_length;
         }
         for(int i=0;i<max_length;++i)
         {
              data[i]=s.data[i];
         }
    }
    String(const char *s)
    {
         max_length=strlen(s) + 1;
         data=new char[max_length];
         for(int i=0;i<max_length;i++)
         {
              data[i]=*(s+i);
         }
     }
     ~String()
     {
          delete [] data;
     }
    friend ostream &operator<<(ostream &out, String &s)
	{
		for(int i = 0; i < s.max_length; ++i)
			out<<s.data[i];
		return out;
	}
};
int main()
{

	
}