#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->data == key)
            return node;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    int height(Node* node) {
        if (node == nullptr) return -1;
        int l = height(node->left);
        int r = height(node->right);
        return 1 + max(l, r);
    }

    void displayTree(Node* node, int space = 0, int indent = 5) {
        if (node == nullptr) return;

        space += indent;
        displayTree(node->right, space);
        cout << endl;
        for (int i = indent; i < space; i++) cout << " ";
        cout << node->data << "\n";
        displayTree(node->left, space);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }

    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void showTree() {
        cout << "Tree structure:\n";
        displayTree(root);
    }

    void getHeight() {
        cout << "Tree Height: " << height(root) << endl;
    }

    void getMinMax() {
        Node* minNode = findMin(root);
        Node* maxNode = root;
        while (maxNode && maxNode->right != nullptr)
            maxNode = maxNode->right;

        if (minNode && maxNode) {
            cout << "Min value: " << minNode->data << endl;
            cout << "Max value: " << maxNode->data << endl;
        }
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.displayInorder();
    tree.showTree();
    tree.getMinMax();
    tree.getHeight();

    cout << "\nSearch 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;

    tree.deleteNode(30);
    cout << "\nAfter deleting 30:\n";
    tree.displayInorder();
    tree.showTree();

    return 0;
}