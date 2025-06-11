//singly linked list 
//
//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;  //store data
//	Node* next;  //pointer to next node
//
//	Node(int val) : data(val),next(nullptr) {} //initialize node=avaibility stack 
//};
//
//void addnode_head(Node*&head,int val) {
//	Node* newnode = new Node(val);
//	newnode->next = head;
//	head = newnode;
//}
//
//void addnode_tail(Node*& head, int val) {
//	Node* newnode = new Node(val);
//	if (!head) { //if head is empty
//		head = newnode;
//		return;
//	}
//
//	Node* current = head;
//	while (current->next) {
//		current = current->next; //move 1 step in the linked lsit 
//	}
//	current->next = newnode;
//}
//
//void delete_node(Node*&head, int key) {
//	if (!head)
//		return;
//	if (head->data == key) {
//		Node* temp = head;
//		head = head->next;
//		delete temp;
//		return;
//	}
//
//	Node* current = head;
//	while (current->next && current->next->data != key) {
//		current = current->next;
//	}
//
//	if (current->next) {
//		Node* temp = current->next;
//		current->next = temp->next;
//		delete temp;
//	}
//
//}
//
//void display_node(Node* head) {
//	while (head) {
//		cout << head->data << " ";
//		head = head->next;
//	}
//	cout << endl;
//}
//
//int main() {
//	Node* head = nullptr;
//
//	addnode_tail(head, 10);
//	addnode_head(head, 40);
//	addnode_head(head, 20);
//	addnode_tail(head, 7);
//	
//	display_node(head);
//
//	delete_node(head, 20);
//	display_node(head);
//
//}