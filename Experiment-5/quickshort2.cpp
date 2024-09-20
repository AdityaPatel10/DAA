#include <iostream>
#include <chrono>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
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
    temp->next = NULL;
    return temp;
}

// Function to append a node to the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

// Function to get the last node of the linked list
Node* getLastNode(Node* head) {
    while (head != NULL && head->next != NULL)
        head = head->next;
    return head;
}

// Partition function for Quick Sort
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL, *cur = head, *tail = pivot;
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if ((*newHead) == NULL) (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

// Quick Sort Recur Function
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node *newHead = NULL, *newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;
        newHead = quickSortRecur(newHead, temp);
        temp = getLastNode(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

// Main Quick Sort function for linked list
void quickSort(Node** head_ref) {
    *head_ref = quickSortRecur(*head_ref, getLastNode(*head_ref));
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to generate a linked list with random numbers
void generateRandomList(Node** head_ref, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int num = rand() % 1000;  // Generates numbers between 0 and 999
        append(head_ref, num);
    }
}

int main() {
    Node* head = NULL;

    int sizes[] = {1000, 5000, 10000, 20000};  // Different values of n

    for (int n : sizes) {
        head = NULL;
        generateRandomList(&head, n);

        cout << "Sorting " << n << " elements..." << endl;

        auto start = chrono::high_resolution_clock::now();  // Start timing
        quickSort(&head);
        auto end = chrono::high_resolution_clock::now();    // End timing

        chrono::duration<double> time_taken = end - start;
        cout << "Time taken for " << n << " elements: " << time_taken.count() << " seconds." << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
