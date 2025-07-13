#include <iostream>
using namespace std;


class Node {
public:
    int data;   
    Node* next;     
    Node* prev;     

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyCircularList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularList() {
        head = tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        bool found = false;

        do {
            if (current->data == value) {
                found = true;
                break;
            }
            current = current->next;
        } while (current != head);

        if (!found) {
            cout << "Value not found.\n";
            return;
        }

        if (head == tail && head->data == value) {
            delete head;
            head = tail = nullptr;
        } else if (current == head) {
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete current;
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete current;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        cout << "Forward: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << "\n";
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = tail;
        cout << "Backward: ";
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != tail);
        cout << "\n";
    }
};

int main() {
    DoublyCircularList list;
    int option, value;

    do {
        cout << "\nDoubly Circular Linked List Menu:\n";
        cout << "1. Insert\n2. Delete\n3. View Forward & Backward\n0. Exit\n> ";
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
                list.displayForward();
                list.displayBackward();
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