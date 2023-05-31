#include <iostream>
using namespace std;
#include <conio.h>
void Enqueue(int arr[], int size, int &front, int &rear, int x)
{
    if (rear < size - 1)
    {
        if (front == -1)
             {
                front = 0;
                     }
        rear++;
        arr[rear] = x;
    }
    else if (rear == size - 1)
    {
        cout << "QueueOverflow" << endl;
    }
}
void Dequeue(int arr[], int &front, int &rear)
{
    if (front <= rear && front != -1)
    {
        cout << "Dequeued Value: " << arr[front] << endl;
        front++;
    }
    else if (front > rear || front == -1)
    {
        front = rear = -1;
        cout << "QueueUnderFlow" << endl;
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
            cout << "Enter the element to push: ";
            cin >> x;
            Enqueue(arr, size, front, rear, x);
            break;
        }
        case '2':
        {
            Dequeue(arr, front, rear);
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