#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the beginning of the doubly linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    return newNode;
}

// Function to delete a node from the beginning of the doubly linked list
Node* deletionFromBeginning(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    else {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return head;
    }
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(4);
    head->next->prev = head;

    head->next->next = new Node(6);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(9);
    head->next->next->next->prev = head->next->next;

    cout << "List Before Inserting Element: " << endl;
    displayList(head);

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 2);

    cout << "List After Inserting Elements: " << endl;
    displayList(head);

    head = deletionFromBeginning(head);

    cout << "List After Deleting First Element: " << endl;
    displayList(head);

    return 0;
}
