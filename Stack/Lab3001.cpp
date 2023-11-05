#include <bits/stdc++.h>
using namespace std;

int arr[100];
int top = -1;

bool isEmpty()
{
    return (top == -1);
}

bool isFull()
{
    return (top == 100 - 1);
}

void push(int data)
{
    if (isFull())
    {
        cout << "Stack_overflow! Cannot push any element." << endl;
        return;
    }
    top++;
    arr[top] = data;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack_underflow! Cannot pop from an empty stack." << endl;
        return -1;
    }

    int data = arr[top];
    top--;
    return data;
}

void printStack()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Current stack: ";
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, data;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push data in stack)\n";
        cout << "2. Print stack\n";
        cout << "3. Pop stack\n";

        cout << "0. Exit\n";
        cout << "Please, Enter your choice first: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Please, Enter data to push into the stack: ";
            cin >> data;
            push(data);
            cout << "And,";
            printStack();
            break;
        case 2:
            printStack();
            break;
        case 3:
            data = pop();
            if (data != -1)
            {
                cout << "Data " << data << " popped from the stack." << endl;
                cout << "And,";
                printStack();
            }
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
