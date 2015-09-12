#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> my_vector(10);

	for (vector<int>::size_type i = 0; i!= my_vector.size(); ++i)
	{
		my_vector[i] = i*i;
		cout << my_vector[i] << " ";
	}

	return 0;
}