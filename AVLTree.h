#ifndef STRUCTURESALGOS_AVLTREE_H
#define STRUCTURESALGOS_AVLTREE_H

#include "AVLNode.h"

class AVLTree {
public:
    AVLTree() = default;
    ~AVLTree();

    void insert(int item);
private:
    AVLNode* root = nullptr;
    AVLNode* insert(int item, AVLNode* node);
    int height(AVLNode* node);
    bool isLeftHeavy(AVLNode* node);
    bool isRightHeavy(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* balance(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
};


#endif //STRUCTURESALGOS_AVLTREE_H
