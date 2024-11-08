#include <bits/stdc++.h>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to swap nodes in a linked list
Node* swapNodes(Node* head, int x, int y) {
    if (x == y) {
        return head;
    }

    Node *prevX = nullptr, *currX = head;
    while (currX != nullptr && currX->data != x) {      // find x
        prevX = currX;
        currX = currX->next;}

    Node *prevY = nullptr, *currY = head;
    while (currY != nullptr && currY->data != y) {      // FIND Y
        prevY = currY;
        currY = currY->next;}

    if (currX == nullptr || currY == nullptr) {
        return head;
    }

    if (prevX != nullptr) {
        prevX->next = currY;
    } else {
        head = currY;
    }

    if (prevY != nullptr) {
        prevY->next = currX;
    } else {
        head = currX;
    }

    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(20);
    head->next->next->next->next->next = new Node(14);

    cout << "Original Linked List: ";
    printList(head);

    int x = 12, y = 20;
    head = swapNodes(head, x, y);

    cout << "Linked List after swapping " << x << " and " << y << ": ";
    printList(head);

    return 0;
}
