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

class Stack {
private:
    Node* top;  

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value); 
        newNode->next = top;           
        top = newNode;                  
        cout << value << " pushed to stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = top;       
        cout << temp->data << " popped from stack\n";
        top = top->next;          
        delete temp;            
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top value: " << top->data << "\n";
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        Node* current = top;  
        cout << "Stack contents (top to bottom): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.display();

    myStack.peek();

    myStack.pop();
    myStack.display();

    return 0;
}