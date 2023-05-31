#include <iostream>
using namespace std;
#include <conio.h>

void push(int arr[], int &top, int size, int x)
{
    if (top == size - 1)
    {
        cout << "StackOverflow" << endl;
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

void pop(int arr[], int &top)
{
    if (top == -1)
    {
        cout << "StackUnderFlow" << endl;
    }
    else
    {
        cout << "Popped value = " << arr[top] << endl;
        top--;
    }
}

int main()
{
    int size;
    cout << "Enter size of stack" << endl;
    cin >> size;
    int *arr = new int[size];
    int top = -1;
    char ch;
    do
    {
        cout << "Enter your choice:" << endl;
        cout << "1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
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
            push(arr, top, size, x);
            break;
        }
        case '2':
        {
            pop(arr, top);
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
