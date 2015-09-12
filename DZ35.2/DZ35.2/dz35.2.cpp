#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    vector< vector <int> > a(10);
    int i, j;
 
    for (i = 0; i < 10; i++)
        a[i].resize(10);
 
    for (i = 1; i < 10; i++)
        for (j = 1; j < 10; j++)
            a[i][j] = i * j;
    
    for (i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
            cout << setw(3) << a[i][j];
    
        cout << endl;
    }
    return 0;
}