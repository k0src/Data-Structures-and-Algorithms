#ifndef STRUCTURESALGOS_TREE_H
#define STRUCTURESALGOS_TREE_H

#include "TreeNode.h"

class Tree {
public:
    Tree();
    ~Tree();
    void add(int item);
    bool has(int item);
private:
    TreeNode* root = nullptr;
};


#endif //STRUCTURESALGOS_TREE_H