#include <iostream>
using namespace std;
#include<conio.h>

void push(int s[], int value, int &t, int size)
{
    if (t == size - 1)
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        s[++t] = value;
    }
}

void pop(int s[], int &t)
{
    int value;
    if (t == -1)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        value = s[t--];
        cout << "Popped value: " << value << endl;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    int *stack = new int[size];
    int top = -1;
    short repeat = 1;
    char ch;
    do
    {
        cout << "1. Push Value" << endl;
        cout << "2. Pop Value" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        ch = getche();
        cout<<endl;
        switch (ch)
        {
        case '1':
        {
            int value;
            cout << "Enter a value to push: ";
            cin >> value;
            push(stack, value, top, size);
            break;
        }
        case '2':
            pop(stack, top);
            break;
        case '3':
            repeat = 0;
            break;
        default:
            cout << "Invalid input." << endl;
        }
    } while (repeat);
    return 0;
}
