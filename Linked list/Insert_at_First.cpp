#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *head = nullptr;
struct node *tail = nullptr;

void createList(int n)
{
    int value;
    cout << "Please,Enter the Numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        struct node *curr = new node;

        curr->val = value;
        curr->next = nullptr;

        if (head == nullptr)
        {
            head = curr;
            tail = curr;
        }

        else
        {
            tail->next = curr;
            tail = curr;
        }
    }
}


void printList()
{
    struct node *current = head;

    cout << "The List is: ";
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
}

void insertHead(){

    struct node *temp = new node;

    int h ;

    cout<<endl<< "Enter the new value of HEAD of the list: ";
    cin>> h;
    temp->val = h;
    temp->next = head;

    head = temp ;
}


int main()
{
    int size;
    cout << "Please,Enter the size of the List: ";
    cin >> size;
    createList(size);
    printList();

    insertHead();
    cout<< "The new list is: ";
    printList();

    return 0;
}