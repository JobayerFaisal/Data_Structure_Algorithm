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
        cout << "Stack overflow. Cannot push more elements." << endl;
        return;
    }

    top++;
    arr[top] = data;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow. Cannot pop from an empty stack." << endl;
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
        cout << arr[i];
    }
    cout << endl;
}

string decimalToBinary(int decimalNumber)
{
    if (decimalNumber == 0)
    {
        return "0";
    }

    while (decimalNumber > 0)
    {
        int remainder = decimalNumber % 2;
        
        push(remainder);
        decimalNumber /= 2;
    }
    printStack();

    
}

int main()
{
    int choice, data;

    cout << "Enter a decimal number to convert to binary: ";
    int decimalNumber;
    cin >> decimalNumber;
    cout << "Binary representation: " << decimalToBinary(decimalNumber) << endl;

    return 0;
}