#include<iostream>
using namespace std;

int main()
{
	int *pi, a[5]={1,3,2,4,5};
	int i=0;
	pi = a;
//	while(i<5)
//	{
//		cout<<"enter value of i["<<i+1<<"]\t";
//		cin>>a[i];
//		i++;
//	}
	for(i=0; i<5; i++)
	{
		cout<<"You entered the value of a["<<i+1<<"]\t"<<*pi<<endl;
		pi++;
	}
	return 0;
}

