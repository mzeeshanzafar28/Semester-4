#include <iostream>
using namespace std;
#include <conio.h>

void push(int arr[][1], int tops[], int size, int stackNo, int x)
{
    if (tops[stackNo] == size - 1)
    {
        cout << "Stack " << stackNo << " is full" << endl;
    }
    else
    {
        arr[++tops[stackNo]][stackNo] = x;
    }
}

void pop(int arr[][1], int tops[], int stackNo)
{
    if (tops[stackNo] == -1)
    {
        cout << "Stack " << stackNo << " is empty" << endl;
    }
    else
    {
        cout << "Popped value from stack " << stackNo << " = " << arr[tops[stackNo]--][stackNo] << endl;
    }
}

int main()
{
    int size, num;
    cout << "Enter size of each stack" << endl;
    cin >> size;
    cout << "Enter the number of stacks" << endl;
    cin >> num;
    int arr[size * num][1];
    int tops[num];
    for (int i = 0; i < num; i++)
    {
        tops[i] = -1;
    }
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
            int x, stackNo;
            cout << "Enter the stack number (0-" << num - 1 << "): ";
            cin >> stackNo;
            cout << "Enter the element to push: ";
            cin >> x;
            push(arr, tops, size, stackNo, x);
            break;
        }
        case '2':
        {
            int stackNo;
            cout << "Enter the stack number (0-" << num - 1 << "): ";
            cin >> stackNo;
            pop(arr, tops, stackNo);
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
    return 0;
}