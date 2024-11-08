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

void delete_at_Anyposition()
{

        int p, q;
    cout << endl;
    cout << "Please, Insert the number to delete: ";
    cin >> p;


    struct node *temp,*temp1;

if(head!=NULL) {

temp = head;

while(temp->next!=NULL && temp->val != p) {

temp1 = temp;

temp = temp->next;

}

if (temp->val == p){

temp1->next = temp->next;

delete(temp);

}

else 
cout<< "“ITEM NOT FOUND”" ;

}

}

int main()
{
    int size;
    cout << "Please,Enter the size of the List: ";
    cin >> size;
    createList(size);
    printList();

    delete_at_Anyposition();
    cout << endl;
    cout << "After deletation " << endl;
    printList();
}