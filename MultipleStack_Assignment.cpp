#include <iostream>
using namespace std;

const int max_stacks = 10;
const int max_size = 100;

int multiStack[max_stacks][max_size];
int tops[max_stacks];

void push(int stackNum, int value)
{
    if (tops[stackNum] < max_size - 1)
    {
        tops[stackNum]++;
        multiStack[stackNum][tops[stackNum]] = value;
    }
}

void pop(int stackNum)
{
    if (tops[stackNum] >= 0)
    {
        tops[stackNum]--;
    }
}

int main()
{
    for (int i = 0; i < max_stacks; i++)
    {
        tops[i] = -1;
    }

    int choice, stackNum, value;
    while (true)
    {
        cout << "Multi-Stack Program" << endl;
        cout << "1. Push value to stack" << endl;
        cout << "2. Pop value from stack" << endl;
        cout << "3. Exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter stack number (0-" << max_stacks - 1 << "): ";
                cin >> stackNum;
                cout << "Enter value to push: ";
                cin >> value;
                push(stackNum, value);
                break;
            case 2:
                cout << "Enter stack number (0-" << max_stacks - 1 << "): ";
                cin >> stackNum;
                pop(stackNum);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
