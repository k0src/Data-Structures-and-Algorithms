#ifndef STRUCTURESALGOS_SORTER_H
#define STRUCTURESALGOS_SORTER_H

#include <vector>
#include <algorithm>

using namespace std;

class Sorter {
public:
    void bubbleSort(vector<int>& array);
    void selectionSort(vector<int>& array);
    void insertionSort(vector<int>& array);
    void merge(int left[], int leftSize, int right[], int rightSize, int result[]);
    void mergeSort(int array[], int size);
    int partition(vector<int>& array, int start, int end);
    void quickSort(vector<int>& array, int start, int end);
    void countingSort(vector<int>& array);
    void bucketSort(std::vector<int>& arr);
};


#endif //STRUCTURESALGOS_SORTER_H