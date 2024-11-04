#pragma once
#ifndef BST_H
#define BST_H

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int val);
};

class BST {
private:
    Node* root;
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* minValueNode(Node* node);
    void destroyTree(Node* node);
    bool findPath(Node* node, int value, vector<int>& path);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    void writeToTextFile(Node* node, ofstream& file);

public:
    BST();
    ~BST();
    void add(int value);
    void remove(int value);
    void clear();
    void findPath(int value);
    void display(int mode);
    void saveToTextFile(const string& filename);
    Node* getRoot();
};

#endif
