#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
 
using namespace std;

typedef string  T_str;

class bad_int : public out_of_range
{
public:     
    bad_int() : out_of_range("�� ����� �� ��� ����� �����!")
    {
	}
};

int main()
{
    locale::global(locale(""));
    T_str  num_str;
    int    n;
    for(;;)
    {
        cout << endl
                  << endl
                  << "������� ����� �����: ";
        cin >> num_str;
        istringstream sin(num_str);    
        
        try
        {        
            if(!(sin >> n))
            {
                throw bad_int();
            }
            cout << n
				<< endl; 
        }
        catch(bad_int& e)
        {
            cout << e.what()
                      << endl;
        }      
    }  
}