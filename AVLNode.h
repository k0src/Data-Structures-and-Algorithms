#ifndef STRUCTURESALGOS_AVLNODE_H
#define STRUCTURESALGOS_AVLNODE_H

class AVLNode {
public:
    AVLNode(int value);
private:
    AVLNode* leftChild;
    AVLNode* rightChild;
    int value;
    friend class AVLTree;
};


#endif //STRUCTURESALGOS_AVLNODE_H