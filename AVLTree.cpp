#include "AVLTree.h"

AVLTree::~AVLTree() {
    //delete here
}

void AVLTree::insert(int item) {
    root = insert(item, root);
}

AVLNode* AVLTree::insert(int item, AVLNode *node) {
    if (node == nullptr)
        return new AVLNode(item);

    if (item < root->value)
        root->leftChild = (item, root->leftChild);
    else
        root->leftChild = (item, root->rightChild);

    return root;
}