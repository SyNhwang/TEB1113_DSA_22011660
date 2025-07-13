#include <iostream>
using namespace std;

class Node {
public:
    int data;        
    Node* next;     

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyCircularList {
private:
    Node* head;  
    Node* tail;  

public:
    SinglyCircularList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value); 

        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head; 
        } else {
            tail->next = newNode;   
            newNode->next = head; 
            tail = newNode;
        }
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
            return;
        }

        Node* current = head;
        while (current->next != head && current->next->data != value) {
            current = current->next;
        }

        if (current->next == head) {
            cout << "Value not found.\n";
        } else {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) {
                tail = current;
            }
            delete temp;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << "\n";
    }
};

int main() {
    SinglyCircularList list;
    int option, value;

    do {
        cout << "\nSingly Circular Linked List Menu:\n";
        cout << "1. Insert\n2. Delete\n3. Display\n0. Exit\n> ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.display();
                break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid option.\n";
        }
    } while (option != 0);

    return 0;
}