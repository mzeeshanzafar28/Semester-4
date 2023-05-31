#include<iostream>
using namespace std;

void swap(int &x, int &y) {
	x = x + y;
	y = x - y;
	x = x - y;
}
int main()
{
	int a = 10, b = 20;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	swap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	return 0;
}