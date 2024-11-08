#include <bits/stdc++.h>
using namespace std;


// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of the linked list
int findLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the median node of the linked list
struct Node* findMedian(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to swap two nodes in the linked list
void swapNodes(struct Node* node1, struct Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Function to place the median node in the middle position
void placeMedianInMiddle(struct Node* head) {
    int length = findLength(head);

    if (length <= 1) {
        // No need to perform any swaps for an empty or single-node list
        return;
    }

    struct Node* medianNode = findMedian(head);

    // Traverse to the middle node
    int middlePosition = length / 2;
    struct Node* middleNode = head;
    for (int i = 0; i < middlePosition; i++) {
        middleNode = middleNode->next;
    }

    // Swap the median node with the middle node
    swapNodes(medianNode, middleNode);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        cout<< head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        delete(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;

    // Example: Inserting values into the linked list
    insertNode(&head, 10);
    insertNode(&head, 5);
    insertNode(&head, 15);
    insertNode(&head, 20);
    insertNode(&head, 3);

    //printf("Original List: ");
    printList(head);

    // Place the median node in the middle position
    placeMedianInMiddle(head);

    cout << "Modified List: " ;
    printList(head);

    // Free the memory allocated for the linked list
    delete(head);

    return 0;
}
