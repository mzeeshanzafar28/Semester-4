#include<iostream>
using namespace std;
#include<conio.h>
int sum(int a)
{
	if (a == 0)
	{
		return a;
	}
	else
	{
		cout << a << endl;
		return a + sum(a - 1);
	}
}
int main()
{
	int s = sum(5);
	cout << s;
	return 0;
}
