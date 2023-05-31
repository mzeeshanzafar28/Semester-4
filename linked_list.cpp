#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<iomanip>

struct Node{
	int data;
	Node *next;
};

// void addBetweenHeadAndTail(Node *&head,Node *&tail,int val)
// {
// 	Node *n = new Node;
// 	n->data = val;
// 	n->next = NULL;
// 	if (head == NULL)
// 	{
// 		head = tail = n;
// 	}
// 	else{
// 		if (head == tail)
// 		{
// 			tail = n;
// 			head->next = tail;
// 			return;
// 		}
		
// 		Node *temp = head;
// 		while (temp->next != tail)
// 		{
// 			temp = temp->next;
// 		}
// 		temp->next = n;
// 		n->next = tail;
// 		tail->next = NULL;
// 	}
// }

void createList(Node *&head,int val)
{
	if (head == NULL)
	{
		Node *n = new Node;
		n->data = val;
		n->next = NULL;
		head = tail = n;
	}
	else{
		cout<<"List Already Created"<<endl;
	}
}

void addAfterIntermediate(Node *&head, Node *&tail, int val, int x)
{
	if (head == NULL)
	{
		cout<<"Add something first"<<endl;
		return;
	}

	Node *temp = head;
	int flag = 0;
	while (temp->next != tail && head != tail)
	{
		if (x == temp->data)
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}

	if (flag == 0)
	{
		cout<<"Cannot find Node specified"<<endl;
		return;
	}

	Node *n = new Node;
	n->data = val;
	n->next = temp->next;
	temp->next = n;


}

void addBeforeIntermediate(Node *&head, Node *&tail, int val, int x)
{
	if (head == NULL)
	{
		cout<<"Create a list first"<<endl;
		return;
	}

	Node *temp = head;
	int flag = 0;
	while (temp->next != tail && head != tail)
	{
		if (x == temp->next->data)
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}

	if (flag == 0)
	{
		cout<<"Cannot find Node specified"<<endl;
		return;
	}

	Node *n = new Node;
	n->data = val;
	n->next = temp->next;
	temp->next = n;


}


void addBeforeHead(Node *&head,Node *&tail,int val)
{
	Node *n = new Node;
	n->data = val;
	if (head == NULL)
	{
		head = tail = n;
		n->next = NULL;
		return;
	}
	n->next = head;
	head = n;
}

void addAfterTail(Node *&head, Node *&tail, int val)
{
	Node *n = new Node;
	n->data = val;
	n->next = NULL;
	if (head == NULL)
	{
		head = tail = n;
	}
	else{
		tail->next = n;
		tail = n;
	}
}

void deleteBetweenHeadAndTail(Node *&head, Node *&tail, int val)
{
	int flag = 0;
	if (head == NULL)
	{
		cout<<"First Enter an element"<<endl;
		return ;
	}
	else
	{
		Node *n = head;
		Node *m = n;
		while (n->next !=tail)
		{
			if (n->data == val)
			{
				if (n == head || n == tail)
				{
					cout<<"Cannot delete using this function"<<endl;
					return ;
				}
				else
				{
					m->next	= n->next;
					delete n;
					flag = 1;
					break;
				}
			}
			m = n;
			n = n->next;
		}
	}
	if (flag == 0)
	{
		cout<<"***No such value***"<<endl;
	}
}

void deleteHead(Node *&head,Node *&tail)
{
	if (head == NULL)
	{
		cout<<"Add Something first"<<endl;
		return;

	}
	else if (head!=tail)
	{
		Node *n = head;
		head = head->next;
		delete n;
		return;
	}
	delete head;
}

void deleteTail(Node *&head, Node *&tail)
{
	if (tail == NULL)
	{
		cout<<"Nothing to delete"<<endl;
		return;
	}
	
	if (head != tail)
	{
	Node *n = head;
	while (n->next != tail)
	{
		n = n->next;
	}
	tail = n;
	n = n->next;
	tail->next = NULL;
	delete n;
	return;
	}
	delete tail;
}

void displayLink(Node *&head, Node *&tail)
{
	if (head == NULL)
	{
		cout<<"Nothing to display"<<endl;
		return;
	}
	else{
		Node *n = head;
		while (n!=NULL)
		{
			cout<<n->data<<endl;
			n = n->next;
		}
	}
}

int main()
{
Node *head = NULL;
Node *tail = NULL;

int val,x;
char ch;
while (1)
{
	cout<<"0. Create List"<<endl;
	cout<<"1. Add Before Intermediate"<<endl;
	cout<<"2. Add After Intermediate"<<endl;
	cout<<"3. Add Before Head"<<endl;
	cout<<"4. Add After Tail"<<endl;
	cout<<"5. Delete Between Head And Tail"<<endl;
	cout<<"6. Delete Head"<<endl;
	cout<<"7. Delete Tail"<<endl;
	cout<<"8. Display Link"<<endl;
	cout<<"9. Exit"<<endl;
	cout<<"\nEnter Your Choice :";

	cin>>ch;
	if (ch == '0')
	{
		cout<<"Enter value: ";
		cin>>val;
		createList(head,val);
	}
	else if (ch == '1')
	{
	cout<<"Enter element before which you want to add a node: ";
	cin>>x;
	cout<<"Enter value :";
	cin>>val;
	addBeforeIntermediate(head,tail,val,x);
	system("cls");
	}
	else if (ch == '2')
	{
	cout<<"Enter element after which you want to add a node: ";
	cin>>x;
	cout<<"Enter value :";
	cin>>val;
	addAfterIntermediate(head,tail,val,x);
	system("cls");
	}
	else if (ch == '3')
	{
	cout<<"Enter value :";
	cin>>val;
	addBeforeHead(head,tail,val);
	system("cls");
	}
	else if (ch == '4')
	{
	cout<<"Enter value :";
	cin>>val;
	addAfterTail(head,tail,val);
	system("cls");
	}
	else if (ch == '5')
	{
	cout<<"Enter value :";
	cin>>val;
	deleteBetweenHeadAndTail(head,tail,val);
	system("cls");
	}
	else if (ch == '6')
	{
	deleteHead(head,tail);
	system("cls");
	}
	else if (ch == '7')
	{
	deleteTail(head,tail);
	system("cls");
	}
	else if (ch == '8')
	{
	displayLink(head,tail);
	}
	else if (ch == '9')
	{
	break;
	}
	else
	{
		cout<<"\nIncorrect Selection. Try Again\n"<<endl;
	}
cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - -"<<endl;


}


getch();
return 0;
}