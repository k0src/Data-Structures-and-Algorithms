#include "AVLTree.h"
#include <algorithm>
#include <iostream>

AVLTree::~AVLTree() {
    //delete here
}

void AVLTree::insert(int item) {
    root = insert(item, root);
}

AVLNode* AVLTree::insert(int item, AVLNode *node) {
    if (node == nullptr)
        return new AVLNode(item);

    if (item < node->value)
        node->leftChild = insert(item, node->leftChild);
    else
        node->rightChild = insert(item, node->rightChild);

    node->height = std::max(height(node->leftChild), height(node->rightChild)) + 1;

    return balance(node);
}

AVLNode* AVLTree::balance(AVLNode *node) {
    if (isLeftHeavy(node)) {
        if (balanceFactor(node->leftChild) < 0)
            root->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }
    else if (isRightHeavy(node)) {
        if (balanceFactor(node->rightChild) > 0)
            root->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }
    return node;
}

AVLNode* AVLTree::rotateLeft(AVLNode *node) {
    auto newRoot = node->rightChild;
    node->rightChild = newRoot->leftChild;
    newRoot->leftChild = node;

    node->height = std::max(height(node->leftChild), height(node->rightChild)) + 1;
    newRoot->height = std::max(height(node->leftChild), height(node->rightChild)) + 1;

    return newRoot;
}

AVLNode* AVLTree::rotateRight(AVLNode *node) {
    auto newRoot = node->leftChild;
    node->leftChild = newRoot->rightChild;
    newRoot->rightChild = node;

    node->height = std::max(height(node->leftChild), height(node->rightChild)) + 1;
    newRoot->height = std::max(height(node->leftChild), height(node->rightChild)) + 1;

    return newRoot;
}

int AVLTree::height(AVLNode *node) {
    return (node == nullptr) ? -1 : node->height;
}

bool AVLTree::isLeftHeavy(AVLNode *node) {
    return balanceFactor(node) > 1;
}

bool AVLTree::isRightHeavy(AVLNode *node) {
    return balanceFactor(node) < -1;
}

int AVLTree::balanceFactor(AVLNode *node) {
    return (node == nullptr) ? 0 : height(node->leftChild) - height(node->rightChild);
}
