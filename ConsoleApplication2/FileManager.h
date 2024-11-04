#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "BST.h"

class FileManager {
public:
    static void saveToBinaryFile(const std::string& filename, Node* root);
    static void loadFromBinaryFile(const std::string& filename, BST& bst);
    static void loadFromTextFile(const std::string& filename, BST& bst);

private:
    static void saveBinaryHelper(std::ofstream& file, Node* node);
};

#endif
