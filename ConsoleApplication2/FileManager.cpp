#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief Funkcja pomocnicza do rekurencyjnego zapisu drzewa w formacie binarnym.
 *
 * Funkcja zapisuje wartosc wezla, a nastepnie rekurencyjnie zapisuje lewe i prawe poddrzewo.
 *
 * @param plik Strumien wyjsciowy binarny do zapisu.
 * @param node Wskaznik na obecny wezel drzewa.
 */
void FileManager::zapiszBinHelp(ofstream& plik, Node* node) {
    if (!node) return;
    plik.write(reinterpret_cast<char*>(&node->data), sizeof(int));
    zapiszBinHelp(plik, node->left);
    zapiszBinHelp(plik, node->right);
}

/**
 * @brief Funkcja pomocnicza do rekurencyjnego zapisu drzewa w formacie tekstowym.
 *
 * Funkcja zapisuje wartosc wezla do pliku tekstowego, a nastepnie rekurencyjnie zapisuje lewe i prawe poddrzewo.
 *
 * @param plik Strumien wyjsciowy tekstowy do zapisu.
 * @param node Wskaznik na obecny wezel drzewa.
 */
void FileManager::zapiszTxtHelp(ofstream& plik, Node* node) {
    if (!node) return;
    plik << node->data << " ";
    zapiszTxtHelp(plik, node->left);
    zapiszTxtHelp(plik, node->right);
}
     
/**
 * @brief Zapisuje drzewo BST do pliku binarnego.
 *
 * @param nazwaPliku Nazwa pliku, do ktorego zapisujemy drzewo.
 * @param root Wskaznik na korzen drzewa BST.
 */
void FileManager::zapiszBin(const string& nazwaPliku, Node* root) {
    ofstream plik(nazwaPliku, ios::binary);
    if (plik.is_open()) {
        zapiszBinHelp(plik, root);
        plik.close();
        cout << "Zapisano drzewo do pliku binarnego.\n";
    }
    else {
        cout << "Blad otwarcia pliku binarnego.\n";
    }
}

/**
 * @brief Wczytuje drzewo BST z pliku binarnego.
 *
 * Funkcja odczytuje kazda wartosc z pliku binarnego i dodaje ja do drzewa BST.
 *
 * @param nazwaPliku Nazwa pliku, z ktorego wczytujemy drzewo.
 * @param bst Obiekt drzewa BST, do ktorego dodajemy wartosci.
 */
void FileManager::wczytajBin(const string& nazwaPliku, BST& bst) {
    ifstream plik(nazwaPliku, ios::binary);
    if (plik.is_open()) {
        int wartosc;
        bst.clear();
        while (plik.read(reinterpret_cast<char*>(&wartosc), sizeof(int))) {
            bst.add(wartosc);
        }
        plik.close();
        cout << "Wczytano drzewo z pliku binarnego.\n";
    }
    else {
        cout << "Blad otwarcia pliku binarnego.\n";
    }
}

   
/**   

     
/**

 * @brief Zapisuje drzewo BST do pliku tekstowego.
 *
 * @param nazwaPliku Nazwa pliku, do ktorego zapisujemy drzewo.
 * @param root Wskaznik na korzen drzewa BST.
 */
void FileManager::zapiszTxt(const string& nazwaPliku, Node* root) {
    ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        zapiszTxtHelp(plik, root);
        plik.close();
        cout << "Drzewo zapisano do pliku tekstowego.\n";
    }
    else {
        cout << "Blad otwarcia pliku.\n";
    }
}   

/**
 * @brief Wczytuje drzewo BST z pliku tekstowego.
 *
 * Funkcja odczytuje kazda wartosc z pliku tekstowego i dodaje ja do drzewa BST.
 *   
 * @param nazwaPliku Nazwa pliku, z ktorego wczytujemy drzewo.
 * @param bst Obiekt drzewa BST, do ktorego dodajemy wartosci.
 */
void FileManager::wczytajTxt(const string& nazwaPliku, BST& bst) {
    ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        int wartosc;
        bst.clear();
        while (plik >> wartosc) {
            bst.add(wartosc);
        }   
        plik.close();
        cout << "Wczytano drzewo z pliku tekstowego.\n";
    }
    else {
        cout << "Blad otwarcia pliku tekstowego.\n";
    }
}
