#include <bits/stdc++.h>
using namespace std;

const int SIZE = 20;

int arr[SIZE];
int front = -1;
int rear = -1;

bool isFull()
{
    return (rear + 1) % SIZE == front;
}

bool isEmpty()
{
    return front == -1 && rear == -1;
}

void enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is full. Cannot enqueue more elements." << endl;
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    arr[rear] = data;
}

char dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return '\0';
    }

    char data = arr[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }

    return data;
}

void printQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    int current = front;
    while (current != rear)
    {
        cout << arr[current] << " ";
        current = (current + 1) % SIZE;
    }
    cout << arr[current] << endl;
}

string removeSpacesUsingQueue(const string &input)
{
    for (char ch : input)
    {
        if (ch != ' ')
        {
            enqueue(ch);
        }
    }

    string result;
    while (!isEmpty())
    {
        result.push_back(dequeue());
    }

    return result;
}

int main()
{

    string result = removeSpacesUsingQueue("We are the students of CSE");
    cout << result << endl;

    return 0;
}