#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void initializeStack(struct Stack *stack)
{
    stack->top = NULL;
}

void initializeQueue(struct Queue *queue)
{
    queue->front = queue->rear = NULL;
}

void push(struct Stack *stack, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void moveDataFromStackToQueue(struct Stack *stack, struct Queue *queue)
{
    while (stack->top != NULL)
    {
        enqueue(queue, stack->top->data);
        struct Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

void displayQueue(struct Queue *queue)
{
    struct Node *current = queue->front;
    cout << "The Queue is : ";
    while (current != NULL)
    {
        cout << current->data;
        current = current->next;
    }
    cout << "\n";
}

int main()
{
    struct Stack Stake1;
    struct Queue Queue1;

    initializeStack(&Stake1);
    initializeQueue(&Queue1);

    push(&Stake1, 1);
    push(&Stake1, 2);
    push(&Stake1, 3);
    push(&Stake1, 4);
    push(&Stake1, 5);

    moveDataFromStackToQueue(&Stake1, &Queue1);

    displayQueue(&Queue1);

    return 0;
}
