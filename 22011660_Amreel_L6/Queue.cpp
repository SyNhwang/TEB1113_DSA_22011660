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


class Queue {
private:
    Node* front;    
    Node* rear;    

public:
    Queue() {
        front = rear = nullptr; 
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            
            front = rear = newNode;
        } else {
            rear->next = newNode; 
            rear = newNode;      
        }
        cout << value << " enqueued.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;     
        cout << temp->data << " dequeued.\n";
        delete temp;              

        if (front == nullptr) {
            rear = nullptr;       
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}