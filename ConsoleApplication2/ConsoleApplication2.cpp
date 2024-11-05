#include <iostream>
#include <string>
#include "BST.h"
#include "FileManager.h"

using namespace std;

/**
 * @brief Funkcja wyswietlajaca menu z dostepnymi operacjami na drzewie BST.
 *
 * Funkcja wyswietla menu w konsoli, umozliwiajace uzytkownikowi wybor jednej
 * z dostepnych operacji, takich jak dodanie, usuniecie elementu, zapis lub
 * wczytanie drzewa oraz wyszukiwanie sciezki do elementu.
 */
void wyswietlMenu() {
    cout << "\nMenu:\n";
    cout << "1. Dodaj element\n";
    cout << "2. Usun element\n";
    cout << "3. Wyczysc drzewo\n";
    cout << "4. Znajdz sciezke do elementu\n";
    cout << "5. Wyswietl drzewo\n";
    cout << "6. Zapisz drzewo do pliku tekstowego\n";
    cout << "7. Wczytaj drzewo z pliku tekstowego\n";
    cout << "8. Zapisz drzewo do pliku binarnego\n";
    cout << "9. Wczytaj drzewo z pliku binarnego\n";
    cout << "0. Wyjdz\n";
    cout << "Wybierz opcje: ";
}

/**
 * @brief Glowna funkcja programu zarzadzajaca interfejsem uzytkownika dla operacji na drzewie BST.
 *
 * Funkcja main zawiera petle, ktora pozwala uzytkownikowi na wykonywanie roznych operacji
 * na drzewie BST, takich jak dodawanie, usuwanie, wyswietlanie, zapisywanie i wczytywanie drzewa.
 * Uzytkownik wybiera opcje z menu, a program wykonuje odpowiednia operacje.
 *
 */
int main() {
    BST bst; ///< Obiekt drzewa BST przechowujacy strukture danych
    int wybor; ///< Zmienna przechowujaca wybor uzytkownika z menu
    int wartosc; ///< Wartosc elementu, na ktorym operujemy w BST
    int trybWyswietlania; ///< Tryb wyswietlania drzewa: 1 - Preorder, 2 - Inorder, 3 - Postorder
    string nazwaPliku; ///< Nazwa pliku, z ktorego wczytujemy lub do ktorego zapisujemy drzewo

    // Petla glowna programu pozwalajaca na wielokrotne wykonywanie operacji na drzewie
    while (true) {
        wyswietlMenu();
        cin >> wybor;

        switch (wybor) {
        case 1:
            cout << "Podaj wartosc do dodania: ";
            cin >> wartosc;
            bst.add(wartosc); ///< Dodanie elementu o wartosci `wartosc` do drzewa BST
            cout << "Dodano element.\n";
            break;

        case 2:
            cout << "Podaj wartosc do usuniecia: ";
            cin >> wartosc;
            bst.remove(wartosc); ///< Usuniecie elementu o wartosci `wartosc` z drzewa BST
            cout << "Usunieto element.\n";
            break;

        

        case 4:
            cout << "Podaj wartosc do znalezienia sciezki: ";
            cin >> wartosc;
            bst.findPath(wartosc); ///< Wyszukanie sciezki do elementu o wartosci `wartosc` w drzewie BST
            break;

        case 5:
            cout << "Tryb wyswietlania (1: Preorder, 2: Inorder, 3: Postorder): ";
            cin >> trybWyswietlania;
            bst.display(trybWyswietlania); ///< Wyswietlenie drzewa BST w wybranym trybie
            break;

        case 6:
            cout << "Podaj nazwe pliku do zapisu (tekst): ";
            cin >> nazwaPliku;
            FileManager::zapiszTxt(nazwaPliku, bst.getRoot()); ///< Zapisanie drzewa BST do pliku tekstowego
            break;

        case 7:
            cout << "Podaj nazwe pliku do wczytania (tekst): ";
            cin >> nazwaPliku;
            FileManager::wczytajTxt(nazwaPliku, bst); ///< Wczytanie drzewa BST z pliku tekstowego
            break;

        case 8:
            cout << "Podaj nazwe pliku do zapisu (binarny): ";
            cin >> nazwaPliku;
            FileManager::zapiszBin(nazwaPliku, bst.getRoot()); ///< Zapisanie drzewa BST do pliku binarnego
            break;

        case 9:
            cout << "Podaj nazwe pliku do wczytania (binarny): ";
            cin >> nazwaPliku;
            FileManager::wczytajBin(nazwaPliku, bst); ///< Wczytanie drzewa BST z pliku binarnego
            break;

        case 0:
            cout << "Koniec programu.\n";
            return 0; ///< Zakonczenie programu

        default:
            cout << "Niepoprawna opcja. Sprobuj ponownie.\n";
            break;
        }
    }
    return 0;
}
