#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insert(node->left, value);
        else node->right = insert(node->right, value);
        return node;
    }

    Node* remove(Node* node, int value) {
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

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }

    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    bool findPath(Node* node, int value, vector<int>& path) {
        if (!node) return false;
        path.push_back(node->data);
        if (node->data == value) return true;
        if (value < node->data && findPath(node->left, value, path)) return true;
        if (value > node->data && findPath(node->right, value, path)) return true;
        path.pop_back();
        return false;
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void writeToTextFile(Node* node, ofstream& file) {
        if (!node) return;
        file << node->data << " ";
        writeToTextFile(node->left, file);
        writeToTextFile(node->right, file);
    }

public:
    BST() : root(nullptr) {}

    void add(int value) { root = insert(root, value); }

    void remove(int value) { root = remove(root, value); }

    void clear() {
        destroyTree(root);
        root = nullptr;
    }

    void findPath(int value) {
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

    void display(int mode) {
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

    void saveToTextFile(const string& filename) {
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

    Node* getRoot() { return root; }
};

class FileManager {
public:
    static void saveToBinaryFile(const string& filename, Node* root) {
        ofstream file(filename, ios::binary);
        if (file.is_open()) {
            saveBinaryHelper(file, root);
            file.close();
            cout << "Tree saved to binary file.\n";
        }
        else {
            cout << "Could not open binary file.\n";
        }
    }

    static void loadFromBinaryFile(const string& filename, BST& bst) {
        ifstream file(filename, ios::binary);
        if (file.is_open()) {
            int value;
            bst.clear();
            while (file.read(reinterpret_cast<char*>(&value), sizeof(int))) {
                bst.add(value);
            }
            file.close();
            cout << "Tree loaded from binary file.\n";
        }
        else {
            cout << "Could not open binary file.\n";
        }
    }

    static void loadFromTextFile(const string& filename, BST& bst) {
        ifstream file(filename);
        if (file.is_open()) {
            int value;
            bst.clear();
            while (file >> value) {
                bst.add(value);
            }
            file.close();
            cout << "Tree loaded from text file.\n";
        }
        else {
            cout << "Could not open text file.\n";
        }
    }

private:
    static void saveBinaryHelper(ofstream& file, Node* node) {
        if (!node) return;
        file.write(reinterpret_cast<char*>(&node->data), sizeof(int));
        saveBinaryHelper(file, node->left);
        saveBinaryHelper(file, node->right);
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add element\n";
    cout << "2. Remove element\n";
    cout << "3. Clear tree\n";
    cout << "4. Find path to element\n";
    cout << "5. Display tree\n";
    cout << "6. Save tree to text file\n";
    cout << "7. Save tree to binary file\n";
    cout << "8. Load tree from binary file\n";
    cout << "9. Load tree from text file\n";
    cout << "0. Exit\n";
    cout << "Select an option: ";
}

int main() {
    BST bst;
    FileManager fm;
    int choice, value, traversalMode;
    string filename;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            bst.add(value);
            break;
        case 2:
            cout << "Enter value to remove: ";
            cin >> value;
            bst.remove(value);
            break;
        case 3:
            bst.clear();
            cout << "Tree cleared.\n";
            break;
        case 4:
            cout << "Enter value to find path: ";
            cin >> value;
            bst.findPath(value);
            break;
        case 5:
            cout << "Display mode (1: Preorder, 2: Inorder, 3: Postorder): ";
            cin >> traversalMode;
            bst.display(traversalMode);
            break;
        case 6:
            cout << "Enter filename to save (text): ";
            cin >> filename;
            bst.saveToTextFile(filename);
            break;
        case 7:
            cout << "Enter filename to save (binary): ";
            cin >> filename;
            FileManager::saveToBinaryFile(filename, bst.getRoot());
            break;
        case 8:
            cout << "Enter filename to load (binary): ";
            cin >> filename;
            FileManager::loadFromBinaryFile(filename, bst);
            break;
        case 9:
            cout << "Enter filename to load (text): ";
            cin >> filename;
            FileManager::loadFromTextFile(filename, bst);
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}