#include "BST.h"

Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

Node* BST::insert(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->data) node->left = insert(node->left, value);
    else node->right = insert(node->right, value);
    return node;
}

Node* BST::remove(Node* node, int value) {
    if (!node) return node;
    if (value < node->data) node->left = remove(node->left, value);
    else if (value > node->data) node->right = remove(node->right, value);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

Node* BST::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

void BST::destroyTree(Node* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

bool BST::findPath(Node* node, int value, vector<int>& path) {
    if (!node) return false;
    path.push_back(node->data);
    if (node->data == value) return true;
    if (value < node->data && findPath(node->left, value, path)) return true;
    if (value > node->data && findPath(node->right, value, path)) return true;
    path.pop_back();
    return false;
}

void BST::preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BST::postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void BST::writeToTextFile(Node* node, ofstream& file) {
    if (!node) return;
    file << node->data << " ";
    writeToTextFile(node->left, file);
    writeToTextFile(node->right, file);
}

void BST::add(int value) { root = insert(root, value); }

void BST::remove(int value) { root = remove(root, value); }

void BST::clear() {
    destroyTree(root);
    root = nullptr;
}

void BST::findPath(int value) {
    vector<int> path;
    if (findPath(root, value, path)) {
        cout << "Path to " << value << ": ";
        for (int val : path) cout << val << " ";
        cout << endl;
    }
    else {
        cout << "Value not found in tree.\n";
    }
}

void BST::display(int mode) {
    if (mode == 1) {
        cout << "Preorder traversal: ";
        preorder(root);
    }
    else if (mode == 2) {
        cout << "Inorder traversal: ";
        inorder(root);
    }
    else if (mode == 3) {
        cout << "Postorder traversal: ";
        postorder(root);
    }
    cout << endl;
}

void BST::saveToTextFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        writeToTextFile(root, file);
        file.close();
        cout << "Tree saved to text file.\n";
    }
    else {
        cout << "Could not open file.\n";
    }
}

Node* BST::getRoot() { return root; }
