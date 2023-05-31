#include <iostream>
using namespace std;
#include <conio.h>

void Enqueue(int arr[], int size, int &f, int &r, int x)
{
	if (r < size - 1 && r != f - 1)
	{
		if (f == -1)
			f = 0;
		arr[++r] = x;
	}
	else if (r == size - 1 && f > 0)
	{
		r = 0;
		arr[r] = x;
	}
	else if ((r == size - 1 && f == 0) || (r == f - 1))
	{
		cout << "Queue is full" << endl;
	}
}

void Dequeue(int arr[], int size, int &f, int &r)
{
	if ((f == size && r == size - 1) || f == -1)
	{
		f = r = -1;
		cout << "Queue is empty" << endl;
	}
	else
	{
		if (f == size && r < size - 1)
		{
			f = 0;
		}
		cout << "Dequeued Value: " << arr[f++] << endl;
		if (r == f - 1)
		{
			f = r = -1;
		}
	}
}

int main()
{
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	int *arr = new int[size];
	int front, rear;
	front = rear = -1;
	char ch;
	do
	{
		cout << "Enter your choice:" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Exit" << endl;
		ch = getche();
		cout << endl;
		switch (ch)
		{
		case '1':
		{
			int x;
			cout << "Enter the element to enqueue: ";
			cin >> x;
			Enqueue(arr, size, front, rear, x);
			break;
		}
		case '2':
		{
			Dequeue(arr, size, front, rear);
			break;
		}
		case '3':
		{
			break;
		}
		default:
		{
			cout << "Invalid choice" << endl;
		}
		}
	} while (ch != '3');
	delete[] arr;
	return 0;
}
