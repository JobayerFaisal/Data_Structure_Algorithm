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
        //   cout << "Address: "<< current->next ;
        current = current->next;
        // cout<< endl ;
    }
}

void delete_Head()
{
    struct node *current, *temp;

    if (head != NULL)
    {
        temp = head;

        head = head->next;

        delete (temp);
    }

    else
    {
        cout << "The list doesn't found!";
    }
}

int main()
{
    int size;
    cout << "Please,Enter the size of the List: ";
    cin >> size;
    createList(size);
    printList();

    delete_Head();
    cout << endl;
    cout << "After deletation " << endl;
    printList();
}