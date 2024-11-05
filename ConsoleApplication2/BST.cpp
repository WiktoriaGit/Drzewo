#include "BST.h"

/**
 * @brief Konstruktor klasy Node inicjujacy wartosc w wezle i ustawiajacy dzieci na nullptr.
 *
 * @param val Wartosc przechowywana w wezle drzewa.
 */
Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

/**
 * @brief Konstruktor klasy BST inicjujacy puste drzewo.
 */
BST::BST() : root(nullptr) {}

/**
 * @brief Destruktor klasy BST, usuwa wszystkie wezly drzewa.
 */
BST::~BST() {
    clear();
}

/**
 * @brief Funkcja rekurencyjnie dodajaca nowy wezel do drzewa.
 *
 * @param node Wskaznik na obecny wezel.
 * @param wartosc Wartosc do dodania do drzewa.
 * @return Node* Wskaznik na korzen drzewa po dodaniu wezla.
 */
Node* BST::insert(Node* node, int wartosc) {
    if (!node) return new Node(wartosc);
    if (wartosc < node->data) node->left = insert(node->left, wartosc);
    else node->right = insert(node->right, wartosc);
    return node;
}

/**
 * @brief Funkcja rekurencyjnie usuwajaca wezel o podanej wartosci z drzewa.
 *
 * @param node Wskaznik na obecny wezel.
 * @param wartosc Wartosc do usuniecia z drzewa.
 * @return Node* Wskaznik na korzen drzewa po usunieciu wezla.
 */
Node* BST::remove(Node* node, int wartosc) {
    if (!node) return node;
    if (wartosc < node->data) node->left = remove(node->left, wartosc);
    else if (wartosc > node->data) node->right = remove(node->right, wartosc);
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

/**
 * @brief Funkcja znajdujaca wezel o najmniejszej wartosci w poddrzewie.
 *
 * @param node Wskaznik na korzen poddrzewa.
 * @return Node* Wskaznik na wezel o najmniejszej wartosci.
 */
Node* BST::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

/**
 * @brief Funkcja rekurencyjnie usuwajaca wszystkie wezly drzewa.
 *
 * @param node Wskaznik na obecny wezel.
 */
void BST::destroyTree(Node* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

/**
 * @brief Funkcja rekurencyjna znajdujaca sciezke do wezla o podanej wartosci.
 *
 * @param node Wskaznik na obecny wezel.
 * @param wartosc Wartosc wezla, do ktorego szukamy sciezki.
 * @param path Wektor przechowujacy sciezke do wezla.
 * @return true Jesli wartosc zostala znaleziona, false w przeciwnym razie.
 */
bool BST::findPath(Node* node, int wartosc, vector<int>& path) {
    if (!node) return false;
    path.push_back(node->data);
    if (node->data == wartosc) return true;
    if (wartosc < node->data && findPath(node->left, wartosc, path)) return true;
    if (wartosc > node->data && findPath(node->right, wartosc, path)) return true;
    path.pop_back();
    return false;
}

/**
 * @brief Funkcja rekurencyjna wyswietlajaca drzewo w porzadku preorder (korzen, lewe, prawe).
 *
 * @param node Wskaznik na obecny wezel.
 */
void BST::preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

/**
 * @brief Funkcja rekurencyjna wyswietlajaca drzewo w porzadku inorder (lewe, korzen, prawe).
 *
 * @param node Wskaznik na obecny wezel.
 */
void BST::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

/**
 * @brief Funkcja rekurencyjna wyswietlajaca drzewo w porzadku postorder (lewe, prawe, korzen).
 *
 * @param node Wskaznik na obecny wezel.
 */
void BST::postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

/**
 * @brief Dodaje wartosc do drzewa BST.
 *
 * @param wartosc Wartosc do dodania do drzewa.
 */
void BST::add(int wartosc) { root = insert(root, wartosc); }

/**
 * @brief Usuwa wartosc z drzewa BST.
 *
 * @param wartosc Wartosc do usuniecia z drzewa.
 */
void BST::remove(int wartosc) { root = remove(root, wartosc); }

/**
 * @brief Usuwa wszystkie wezly drzewa, czyszczac drzewo.
 */
void BST::clear() {
    destroyTree(root);
    root = nullptr;
}

/**
 * @brief Znajduje i wyswietla sciezke do wezla o podanej wartosci.
 *
 * @param wartosc Wartosc wezla, do ktorego chcemy znalezc sciezke.
 */
void BST::findPath(int wartosc) {
    vector<int> path;
    if (findPath(root, wartosc, path)) {
        cout << "Sciezka do " << wartosc << ": ";
        for (int val : path) cout << val << " ";
        cout << endl;
    }
    else {
        cout << "Wartosc nieznaleziona w drzewie.\n";
    }
}

/**
 * @brief Wyswietla drzewo w wybranym porzadku: preorder, inorder lub postorder.
 *
 * @param mode Tryb wyswietlania (1: Preorder, 2: Inorder, 3: Postorder).
 */
void BST::display(int mode) {
    if (mode == 1) {
        cout << "Preorder: ";
        preorder(root);
    }
    else if (mode == 2) {
        cout << "Inorder: ";
        inorder(root);
    }
    else if (mode == 3) {
        cout << "Postorder: ";
        postorder(root);
    }
    cout << endl;
}

/**
 * @brief Zwraca korzen drzewa BST.
 *
 * @return Node* Wskaznik na korzen drzewa.
 */
Node* BST::getRoot() { return root; }
