#include<iostream>
using namespace std;

int main()
{
	int y = 20;
	int * py = &y;
	cout<<"Value of y "<<y<<endl;
	cout<<"Address of y "<<&y<<endl;
	cout<<"Value of py "<<py<<endl;
	cout<<"Address of py "<<&py<<endl;
	cout<<"Value of y using py "<<*py<<endl;
	return 0;
}

