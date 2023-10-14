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

void insertAnyPosition()
{
    int p, q;
    cout << endl;
    cout << "Please, Insert the position of the new item: ";
    cin >> p;

    cout << "Please, ENTER The number to insert: ";
    cin >> q;

    struct node *temp = new node;
    temp->val = q;
    temp->next = nullptr;

    if (p == 1)
    {
        // Insert at the beginning
        temp->next = head;
        head = temp;
    }
    else
    {
        struct node *current = head;
        int count = 1;

        while (current != nullptr && count < p - 1)
        {
            current = current->next;
            count++;
        }

        if (current == nullptr)
        {
            cout << "Invalid position." << endl;
        }
        else
        {
            // Insert after current
            temp->next = current->next;
            current->next = temp;
        }
    }
}

int main()
{
    int size;
    cout << "Please,Enter the size of the List: ";
    cin >> size;
    createList(size);
    printList();

    insertAnyPosition();
    cout << "The new list is: ";
    printList();

    return 0;
}