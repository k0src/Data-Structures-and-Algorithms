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
};


#endif //STRUCTURESALGOS_AVLTREE_H
