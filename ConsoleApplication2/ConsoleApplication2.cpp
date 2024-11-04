#include <iostream>
#include <string>
#include "BST.h"
#include "FileManager.h"

using namespace std;

// Funkcja do wyświetlenia menu opcji dla użytkownika
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
    BST bst;          // Tworzenie instancji drzewa BST
    int choice, value, traversalMode;
    string filename;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // Dodawanie elementu do drzewa
            cout << "Enter value to add: ";
            cin >> value;
            bst.add(value);
            cout << "Element added to tree.\n";
            break;

        case 2: // Usuwanie elementu z drzewa
            cout << "Enter value to remove: ";
            cin >> value;
            bst.remove(value);
            cout << "Element removed from tree.\n";
            break;

        case 3: // Czyszczenie całego drzewa
            bst.clear();
            cout << "Tree cleared.\n";
            break;

        case 4: // Znajdowanie ścieżki do elementu
            cout << "Enter value to find path: ";
            cin >> value;
            bst.findPath(value);
            break;

        case 5: // Wyświetlanie drzewa w wybranym porządku
            cout << "Display mode (1: Preorder, 2: Inorder, 3: Postorder): ";
            cin >> traversalMode;
            bst.display(traversalMode);
            break;

        case 6: // Zapis drzewa do pliku tekstowego
            cout << "Enter filename to save (text): ";
            cin >> filename;
            bst.saveToTextFile(filename);
            break;

        case 7: // Zapis drzewa do pliku binarnego
            cout << "Enter filename to save (binary): ";
            cin >> filename;
            FileManager::saveToBinaryFile(filename, bst.getRoot());
            break;

        case 8: // Wczytanie drzewa z pliku binarnego
            cout << "Enter filename to load (binary): ";
            cin >> filename;
            FileManager::loadFromBinaryFile(filename, bst);
            break;

        case 9: // Wczytanie drzewa z pliku tekstowego
            cout << "Enter filename to load (text): ";
            cin >> filename;
            FileManager::loadFromTextFile(filename, bst);
            break;

        case 0: // Wyjście z programu
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}

