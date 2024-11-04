#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

// Funkcja pomocnicza do zapisu drzewa w formacie binarnym (rekurencyjnie)
void FileManager::saveBinaryHelper(ofstream& file, Node* node) {
    if (!node) return;
    file.write(reinterpret_cast<char*>(&node->data), sizeof(int)); // zapisuje warto�� w�z�a
    saveBinaryHelper(file, node->left);    // zapis lewej ga��zi
    saveBinaryHelper(file, node->right);   // zapis prawej ga��zi
}

// Funkcja zapisuj�ca drzewo do pliku binarnego
void FileManager::saveToBinaryFile(const string& filename, Node* root) {
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

// Funkcja �aduj�ca drzewo z pliku binarnego
void FileManager::loadFromBinaryFile(const string& filename, BST& bst) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        int value;
        bst.clear();  // usuwa obecne drzewo przed za�adowaniem nowego
        while (file.read(reinterpret_cast<char*>(&value), sizeof(int))) {
            bst.add(value); // dodaje warto�ci do drzewa
        }
        file.close();
        cout << "Tree loaded from binary file.\n";
    }
    else {
        cout << "Could not open binary file.\n";
    }
}

// Funkcja �aduj�ca drzewo z pliku tekstowego
void FileManager::loadFromTextFile(const string& filename, BST& bst) {
    ifstream file(filename);
    if (file.is_open()) {
        int value;
        bst.clear();  // usuwa obecne drzewo przed za�adowaniem nowego
        while (file >> value) {
            bst.add(value); // dodaje warto�ci do drzewa
        }
        file.close();
        cout << "Tree loaded from text file.\n";
    }
    else {
        cout << "Could not open text file.\n";
    }
}
