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

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (front == nullptr) {
            front = rear = newNode;
            rear->next = front;  
        } else {
            rear->next = newNode;  
            rear = newNode;        
            rear->next = front;    
        }
        cout << value << " enqueued.\n";
    }
    
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        if (front == rear) {
            cout << front->data << " dequeued.\n";
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            cout << temp->data << " dequeued.\n";
            front = front->next;
            rear->next = front;  
            delete temp;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}