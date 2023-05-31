//Double Linked List

#include<iostream>
using namespace std;
#include<conio.h>

struct Node{
int data;
Node *next;
Node *prev;
};

void createList(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
    {
        Node *n = new Node;
        n->data = val;
        n->next = NULL;
        n->prev = NULL;
        head = tail = n;
        return;
    }
    cout<<"List Already exists"<<endl;
}

void addBeforeIntermediate(Node *&head, Node *&tail, int val, int x)
{
    if (head == NULL)
    {
        cout<<"Create a List First"<<endl;
        return;
    }
    if (head == tail)
    {
        cout<<"Only one Node exists, cannot use this function"<<endl;
        return;
    }

    Node *temp = head;
    int flag = 0;
    while (temp->next != tail)
    {
        if (temp->data == x)
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
    n->next = temp;
    temp->prev = n;
    n->prev = temp->prev;
    temp->prev->next = n;


}

void addAfterIntermediate(Node *&head, Node *&tail, int val, int x)
{
    if (head == NULL)
    {
        cout<<"Create a list first"<<endl;
        return;
    }

    if (head == tail)
    {
        cout<<"Only one Node exists, cannot use this function"<<endl;
        return;
    }

    Node *temp = head;
    int flag = 0;
    while (temp->next != tail && head != tail)
    {
        if (temp->data == x)
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
    n->prev = temp;
    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
}

void addBeforeHead(Node *&head , Node *&tail, int val)
{
    Node *n = new Node;
    n->data = val;
    if (head == NULL)
    {
        cout<<"Head does not exist, current Node will be the first one"<<endl;
        n->next = NULL;
        n->prev = NULL;
        head = tail = n;
        return;
    }
    n->next = head;
    n->prev = NULL;
    head->prev = n;
    head = n;
}

void addAfterTail(Node *&head , Node *&tail, int val)
{
    Node *n = new Node;
    n->data = val;
    n->next = NULL;
    if (tail == NULL)
    {
        cout<<"Tail does not exist, current Node will be the tail now"<<endl;
        head = tail = n;
        return;
    }
   n->prev = tail;
   n->next = NULL;
   tail->next = n;
   tail = n;
}

void deleteBetweenHeadAndTail(Node *&head, Node *&tail, int x)
{
    if (head == NULL)
    {
        cout<<"What are you trying to delete ? add Something first"<<endl;
        return;
    }
    if (head == tail || head->next == tail)
    {
        cout<<"Adding this much won't help, try harder, add some more Nodes to do this"<<endl;
        return;
    }
    int flag = 0;
    Node *temp = head;
    while (temp->next != tail)
    {
        if (x == temp->data)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            flag = 1;
            return;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        cout<<"You should try deleting something that actually exists"<<endl;
    }

}

void deleteHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout<<"Deleting a non-existing head is not allowed"<<endl;
        return;
    }
    if (head == tail)
    {
        cout<<"Cannot delete this one because it's the head as well as the tail"<<endl;
        return;
    }
    Node *temp = head;
    tail->next = head->next;
    head->next->prev = tail;
    head = head->next;
    delete temp;

}

void deleteTail(Node *&head, Node *&tail)
{
    if (tail == NULL)
    {
        cout<<"Deleting a non-existing tail is not allowed"<<endl;
        return;
    }
    if (head == tail)
    {
        cout<<"Cannot delete this one because it's the head as well as the tail"<<endl;
        return;
    }
   tail->prev->next = head;
   head->prev = tail->prev;
}

void displayLink(Node *&head, Node *&tail)
{
    if (head->next != head)
    {
        Node *temp = head;
        while (temp->next != head)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        return;
    }
    cout<<"***** Out of Inventory *****"<<endl;
}

// <------ MAIN SECTION ----->
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val, x ;
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
		createList(head,tail,val);
		system("cls");
	}
	else if (ch == '1')
	{
	cout<<"Enter element before which you want to add a node: ";
	cin>>x;
	cout<<"Enter value :";
	cin>>val;
	addBeforeIntermediate(head,tail,val,x);
	}
	else if (ch == '2')
	{
	cout<<"Enter element after which you want to add a node: ";
	cin>>x;
	cout<<"Enter value :";
	cin>>val;
	addAfterIntermediate(head,tail,val,x);
	}
	else if (ch == '3')
	{
	cout<<"Enter value :";
	cin>>val;
	addBeforeHead(head,tail,val);
	}
	else if (ch == '4')
	{
	cout<<"Enter value :";
	cin>>val;
	addAfterTail(head,tail,val);
	}
	else if (ch == '5')
	{
	cout<<"Enter value :";
	cin>>val;
	deleteBetweenHeadAndTail(head,tail,val);
	}
	else if (ch == '6')
	{
	deleteHead(head,tail);
	}
	else if (ch == '7')
	{
	deleteTail(head,tail);
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