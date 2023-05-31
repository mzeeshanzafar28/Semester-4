#include<iostream>
using namespace std;
struct student
{
	int rollno;
	char name[30];
	int marks;
};
int main()
{
	student *s = new student;
	cin>>s->rollno;
	cin>>s->name;
	cin>>s->marks;
	cout<<s->rollno<<'\t'<<s->name<<'\t'<<s->marks;
	return 0;
}

