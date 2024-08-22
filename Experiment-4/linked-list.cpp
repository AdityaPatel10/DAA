#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int d){
        data =d;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void Delete() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main() {
    LinkedList llist;
    llist.insert(6);
    llist.insert(2);
    llist.insert(9);
    llist.insert(10);
    cout << "List after inserting elements at the beginning: " ;
    llist.display();
    llist.Delete();
    cout << "List after deleting an element from the beginning: ";
    llist.display();
    return 0;
}