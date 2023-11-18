#include <bits/stdc++.h>
using namespace std;


const int SIZE = 20;

int arr[SIZE];
int front = -1;
int rear = -1;

bool isFull()
{
    return (rear + 1) == front;
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
        rear = (rear + 1);
    }

    arr[rear] = data;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1);
    }
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
        current = (current + 1);
    }
    cout << arr[current] << endl;
}

void deleteNeg()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    int originalFront = front;
    int newFront = front;

    while (newFront != rear)
    {
        if (arr[newFront] < 0)
        {
            newFront = (newFront + 1) % SIZE;
        }
        else
        {
            arr[originalFront] = arr[newFront];
            originalFront = (originalFront + 1) % SIZE;
            newFront = (newFront + 1) % SIZE;
        }
    }

    if (arr[newFront] >= 0)
    {
        arr[originalFront] = arr[newFront];
        originalFront = (originalFront + 1) % SIZE;
    }

    front = originalFront;
    if (front == rear)
    {
        front = rear = -1;
    }
}

void move(int i)
{
    for (; i < rear; i++)
        arr[i] = arr[i + 1];
}

void deletenegative()
{
    int i;
    if (front == -1)
        cout << "queue empty\n";
    else
    {
        for (i = front; i <= rear;)
        {
            if (arr[i] < 0)
            {
                if (i == rear)
                {
                    dequeue();
                    i = i + 1;
                }
                else
                {
                    move(i);
                    rear = rear - 1;
                    i = i - 1;
                }
            }
            else
                i = i + 1;
        }
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(-3);
    enqueue(-4);
    enqueue(5);
    printQueue();

    deletenegative();

    printQueue();

    return 0;
}