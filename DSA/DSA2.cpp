#include <iostream>
using namespace std;

int main()
{
	int a[5] = {99, 88, 77, 66, 55};
	cout << a << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Value of a[" << i << "] " << a[i] << endl;
		cout << "At address " << &a[i] << endl;
	}
	return 0;
}
