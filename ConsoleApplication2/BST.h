#pragma once
#ifndef BST_H
#define BST_H

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief Klasa reprezentujaca wezel w drzewie BST.
 *
 * Klasa Node przechowuje wartosc wezla oraz wskazniki na lewe i prawe dziecko.
 */
class Node {
public:
    int data; ///< Wartosc przechowywana w wezle
    Node* left; ///< Wskaznik na lewe dziecko wezla
    Node* right; ///< Wskaznik na prawe dziecko wezla

    /**
     * @brief Konstruktor klasy Node inicjujacy wartosc wezla.
     *
     * @param val Wartosc przypisana do wezla.
     */
    Node(int val);  
};


/**
 * @brief Klasa reprezentujaca drzewo poszukiwan binarnych (BST).
 *
 * Klasa BST umozliwia wykonywanie operacji na drzewie, takich jak dodawanie, usuwanie,
 * wyszukiwanie sciezki do wezla oraz wyswietlanie drzewa w roznych kolejnosciach.
 */
class BST {
private:
    Node* root; ///< Wskaznik na korzen drzewa BST

    /**
     * @brief Rekurencyjnie dodaje nowy wezel do drzewa.
     *
     * @param node Wskaznik na obecny wezel.
     * @param wartosc Wartosc do dodania.
     * @return Node* Wskaznik na korzen drzewa po dodaniu wezla.
     */
    Node* insert(Node* node, int wartosc);

    /**
     * @brief Rekurencyjnie usuwa wezel o podanej wartosci z drzewa.
     *
     * @param node Wskaznik na obecny wezel.
     * @param wartosc Wartosc do usuniecia.
     * @return Node* Wskaznik na korzen drzewa po usunieciu wezla.
     */
    Node* remove(Node* node, int wartosc);

    /**
     * @brief Znajduje wezel o najmniejszej wartosci w poddrzewie.
     *
     * @param node Wskaznik na korzen poddrzewa.
     * @return Node* Wskaznik na wezel o najmniejszej wartosci.
     */
    Node* minValueNode(Node* node);

    /**
     * @brief Usuwa wszystkie wezly drzewa rekurencyjnie.
     *
     * @param node Wskaznik na obecny wezel.
     */
    void destroyTree(Node* node);

    /**
     * @brief Znajduje sciezke do wezla o podanej wartosci.
     *
     * @param node Wskaznik na obecny wezel.
     * @param wartosc Wartosc wezla, do ktorego szukamy sciezki.
     * @param path Wektor przechowujacy sciezke do wezla.
     * @return true Jesli wartosc zostala znaleziona, false w przeciwnym razie.
     */
    bool findPath(Node* node, int wartosc, vector<int>& path);

    /**
     * @brief Wyswietla drzewo w porzadku preorder.
     *
     * @param node Wskaznik na obecny wezel.
     */
    void preorder(Node* node);

    /**
     * @brief Wyswietla drzewo w porzadku inorder.
     *
     * @param node Wskaznik na obecny wezel.
     */
    void inorder(Node* node);

    /**
     * @brief Wyswietla drzewo w porzadku postorder.
     *
     * @param node Wskaznik na obecny wezel.
     */
    void postorder(Node* node);

public:
    /**
     * @brief Konstruktor klasy BST inicjujacy puste drzewo.
     */
    BST();

    /**
     * @brief Destruktor klasy BST, usuwa wszystkie wezly drzewa.
     */
    ~BST();

    /**
     * @brief Dodaje wartosc do drzewa BST.
     *
     * @param wartosc Wartosc do dodania.
     */
    void add(int wartosc);

    /**
     * @brief Usuwa wartosc z drzewa BST.
     *
     * @param wartosc Wartosc do usuniecia.
     */
    void remove(int wartosc);

    /**
     * @brief Usuwa wszystkie wezly drzewa.
     */
    void clear();

    /**
     * @brief Znajduje i wyswietla sciezke do wezla o podanej wartosci.
     *
     * @param wartosc Wartosc wezla, do ktorego szukamy sciezki.
     */
    void findPath(int wartosc);

    /**
     * @brief Wyswietla drzewo w wybranym porzadku: preorder, inorder lub postorder.
     *
     * @param mode Tryb wyswietlania (1: Preorder, 2: Inorder, 3: Postorder).
     */
    void display(int mode);

    /**
     * @brief Zwraca wskaznik na korzen drzewa BST.
     *
     * @return Node* Wskaznik na korzen drzewa.
     */
    Node* getRoot();
};

#endif
