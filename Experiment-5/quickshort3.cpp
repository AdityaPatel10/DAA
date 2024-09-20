#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

// Function to add a new node at the end of the linked list
void append(Node** head_ref, int data) {
    Node* temp = *head_ref;
    Node* new_node = newNode(data);
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Partition function for linked list
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *curr = head, *tail = pivot;
    
    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (*newHead == nullptr) {
                *newHead = curr; // Mark new head
            }
            prev = curr; // Move prev pointer
        } else {
            if (prev) {
                prev->next = curr->next; // Bypass current node
            }
            Node* temp = curr->next;
            curr->next = nullptr; // Move current node to the end
            tail->next = curr;
            tail = curr;
            curr = temp;
            continue;
        }
        curr = curr->next;
    }

    if (*newHead == nullptr) {
        *newHead = pivot; // Pivot is the smallest element
    }
    
    *newEnd = tail;

    return pivot;
}

// Function to get the tail of a linked list
Node* getTail(Node* head) {
    while (head != nullptr && head->next != nullptr) {
        head = head->next;
    }
    return head;
}

// Recursive QuickSort function for linked list
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) {
        return head;
    }

    Node* newHead = nullptr, *newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// Main function to sort a linked list
void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

int main() {
    Node* a = nullptr;
    
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        append(&a, x);
    }

    cout << "Linked list before sorting: ";
    printList(a);

    quickSort(&a);

    cout << "Linked list after sorting: ";
    printList(a);

    return 0;
}
