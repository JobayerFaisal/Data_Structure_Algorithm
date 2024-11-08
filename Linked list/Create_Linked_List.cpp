#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void print()
{
    struct node *curr = head;

    while (curr != NULL)
    {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl;
}

void create(int n)
{
    int value;

    cout << "Please,Enter the Numbers: ";
    for (int i = 0; i < n; i++)
    {

        cin >> value;
        struct node *curr = new node;

        curr->val = value;
        curr->next = NULL;

        if (head == NULL)
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

int main()
{
    int n;
    cout << "Please,Enter the size of the list: ";
    cin >> n;
    create(n);
    print();

    return 0;
}