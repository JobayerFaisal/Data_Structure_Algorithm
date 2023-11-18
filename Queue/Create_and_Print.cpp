#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int frontIndex = -1;
int rearIndex = -1;

bool isEmpty()
{
    return frontIndex == -1 && rearIndex == -1;
}

bool isFull()
{
    return (rearIndex + 1) % MAX_SIZE == frontIndex;
}

void enqueue(int item)
{
    if (isFull())
    {
        cout << "Queue is full. Cannot enqueue.\n";
        return;
    }

    if (isEmpty())
    {
        frontIndex = 0;
        rearIndex = 0;
    }
    else
    {
        rearIndex = (rearIndex + 1) % MAX_SIZE;
    }

    arr[rearIndex] = item;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }
    else if (frontIndex == rearIndex)
    {
        frontIndex = -1;
        rearIndex = -1;
    }
    else
    {
        frontIndex = (frontIndex + 1) % MAX_SIZE;
    }
}

int front()
{
    if (isEmpty())
    {
        cout << "Queue is empty. No front element.\n";
        return -1; 
    }

    return arr[frontIndex];
}

int rear()
{
    if (isEmpty())
    {
        cout << "Queue is empty. No rear element.\n";
        return -1; 
    }

    return arr[rearIndex];
}

void printQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty.\n";
        return;
    }

    int current = frontIndex;
    while (current != rearIndex)
    {
        cout << arr[current] << " ";
        current = (current + 1) % MAX_SIZE;
    }
    cout << arr[current] << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    cout << "After enqueue, The QUEUE is : ";
    printQueue();

    dequeue();
    cout << "After dequeue, The Queue is : ";
    printQueue();

    return 0;
}