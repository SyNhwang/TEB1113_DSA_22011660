#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void addRoot(string name) {
        root = new Node(name);
    }

    void addLeft(Node* parent, string name) {
        parent->left = new Node(name);
    }

    void addRight(Node* parent, string name) {
        parent->right = new Node(name);
    }

    void print_paths(Node* node, string path) {
        if (!node) return;

        path += node->name + " -> ";

        if (!node->left && !node->right) {
            cout << path << "NULL" << endl;
            return;
        }

        print_paths(node->left, path);
        print_paths(node->right, path);
    }

    void view_element() {
        cout << "Root-to-leaf paths:\n";
        print_paths(root, "");
    }
};

int main() {
    Tree tree;

    tree.addRoot("A");
    tree.addLeft(tree.root, "B");
    tree.addRight(tree.root, "C");
    tree.addLeft(tree.root->left, "D");
    tree.addRight(tree.root->right, "E");

    tree.view_element();

    return 0;
}