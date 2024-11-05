#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "BST.h"

/**
 * @brief Klasa FileManager obsluguje zapisywanie i wczytywanie drzewa BST z plikow binarnych i tekstowych.
 *
 * Klasa zawiera metody do zapisu i odczytu drzewa BST w formacie binarnym oraz tekstowym,
 * wykorzystujac pomocnicze funkcje rekurencyjne.
 */
class FileManager {
public:
    /**
     * @brief Zapisuje drzewo BST do pliku binarnego.
     *
     * @param nazwaPliku Nazwa pliku, do ktorego zapisujemy drzewo.
     * @param root Wskaznik na korzen drzewa BST.
     */
    static void zapiszBin(const std::string& nazwaPliku, Node* root);

    /**
     * @brief Wczytuje drzewo BST z pliku binarnego.
     *
     * @param nazwaPliku Nazwa pliku, z ktorego wczytujemy drzewo.
     * @param bst Obiekt drzewa BST, do ktorego dodajemy wczytane wartosci.
     */
    static void wczytajBin(const std::string& nazwaPliku, BST& bst);

    /**
     * @brief Wczytuje drzewo BST z pliku tekstowego.
     *
     * @param nazwaPliku Nazwa pliku, z ktorego wczytujemy drzewo.
     * @param bst Obiekt drzewa BST, do ktorego dodajemy wczytane wartosci.
     */
    static void wczytajTxt(const std::string& nazwaPliku, BST& bst);

    /**
     * @brief Zapisuje drzewo BST do pliku tekstowego.
     *
     * @param nazwaPliku Nazwa pliku, do ktorego zapisujemy drzewo.
     * @param root Wskaznik na korzen drzewa BST.
     */
    static void zapiszTxt(const std::string& nazwaPliku, Node* root);

private:
    /**
     * @brief Funkcja pomocnicza do rekurencyjnego zapisu drzewa w formacie binarnym.
     *
     * @param plik Strumien wyjsciowy binarny do zapisu.
     * @param node Wskaznik na obecny wezel drzewa.
     */
    static void zapiszBinHelp(std::ofstream& plik, Node* node);

    /**
     * @brief Funkcja pomocnicza do rekurencyjnego zapisu drzewa w formacie tekstowym.
     *
     * @param plik Strumien wyjsciowy tekstowy do zapisu.
     * @param node Wskaznik na obecny wezel drzewa.
     */
    static void zapiszTxtHelp(std::ofstream& plik, Node* node);
};

#endif
