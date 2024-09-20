#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        return NULL;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(4);
    head->next->next = new Node(6);

    cout << "List Before Inserting Element: " << endl;
    displayList(head);

    // Corrected: Capture the returned head
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 2);

    cout << "List After Inserting Elements: " << endl;
    displayList(head);
    
    // Corrected: Capture the returned head after deletion
    head = deleteFromBeginning(head);
    cout << "List After Deleting First Element: " << endl;
    displayList(head);

    return 0;
}
