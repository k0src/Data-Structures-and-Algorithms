//
// Created by clips on 4/28/2024.
//

#ifndef STRUCTURESALGOS_ARRAY_H
#define STRUCTURESALGOS_ARRAY_H


class Array {
public:
    explicit Array(int length);
    ~Array();
    void print();
    void insert(int item);
    void removeAt(int index);
    int indexOf(int item) const;
    int max() const;
    void reverse();
private:
    int* items;
    int length;
    int count = 0;
};


#endif //STRUCTURESALGOS_ARRAY_H
