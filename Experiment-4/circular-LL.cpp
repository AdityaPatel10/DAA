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
    if (head == NULL) {
        newNode->next = newNode;  
        return newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {  
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->next = head;  
        return newNode;       
    }
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == head) {
        delete head;
        return NULL;
    } else {
        Node* temp = head;
        while (temp->next != head) { 
            temp = temp->next;
        }
        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;
        delete toDelete;
        return head;
    }
}

void displayList(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;  
}

int main() {
    Node* head = new Node(7);
    head->next = head;  

    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 6);

    cout << "List Before Inserting Any Element: " << endl;
    displayList(head);

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 2);

    cout << "List After Inserting Elements: " << endl;
    displayList(head);
    
    head = deleteFromBeginning(head);
    cout << "List After Deleting First Element: " << endl;
    displayList(head);

    return 0;
}
