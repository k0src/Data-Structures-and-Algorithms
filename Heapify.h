#ifndef STRUCTURESALGOS_HEAPIFY_H
#define STRUCTURESALGOS_HEAPIFY_H


class Heapify {
public:
    static void heapify(int array[], int size);
private:
    static void heapify(int array[], int size, int index);
    static void swap(int array[], int size, int first, int second);
};

#endif