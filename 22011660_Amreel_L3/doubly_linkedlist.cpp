#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addToHead(int value) {
        Node* newNode = new Node(value);

        if (this->head == nullptr) {
            this->head = this->tail = newNode;
        } else {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }
    }

    void addToTail(int value) {
        Node* newNode = new Node(value);

        if (this->tail == nullptr) {
            this->head = this->tail = newNode;
        } else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
    }

    void deleteNode(int value) {
        Node* current = this->head;

        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value " << value << " not found in the list.\n";
            return;
        }

        //one node
        if (this->head == this->tail) {
            delete current;
            this->head = this->tail = nullptr;
        }
        //deleting the head
        else if (current == this->head) {
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete current;
        }
        //deleting the tail
        else if (current == this->tail) {
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete current;
        }
        //Deleting from the middle
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    void displayForward() {
        Node* temp = this->head;
        cout << "List (forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void displayBackward() {
        Node* temp = this->tail;
        cout << "List (backward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.addToHead(10);
    list.addToHead(20);
    list.addToTail(5);
    list.addToTail(1);

    list.displayForward();    
    list.displayBackward();   

    list.deleteNode(10);
    list.displayForward();   

    list.deleteNode(100);  

    return 0;
}