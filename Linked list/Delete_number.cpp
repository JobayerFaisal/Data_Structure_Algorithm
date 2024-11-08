#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteOccurrences(Node* head, int x) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;

        if (current->data == x) {
            
            if (current == head) {
                head = next;
                
                delete current;
            } 
            
            else {
                current->prev->next = next;
                if (next != nullptr) {
                    next->prev = current->prev;
                }
                delete current;
            }
        }

        current = next;
    }

    return head;
}

int main() {
    Node* head = nullptr;

    insert(head, 2);
    insert(head, 5);
    insert(head, 2);
    insert(head, 4);
    insert(head, 2);
    insert(head, 8);

    cout << "Original Doubly Linked List: ";
    printList(head);

    int x = 4;
    head = deleteOccurrences(head, x);

    cout << "Doubly Linked List after delete " << x << ": ";
    printList(head);

    return 0;
}
