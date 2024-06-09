#include "Sorter.h"

using namespace std;

void Sorter::bubbleSort(vector<int>& array) {
    for (int i = 0; i < array.size() - 1; i++) {
        bool isSorted;
        for (int j = 1; j < array.size() - i; j++) {
            isSorted = true;
            if (array[j] < array[j - 1]) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
            return;
    }
}

void Sorter::selectionSort(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        int minIndex = i;
        for (int j = i; j < array.size(); j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void Sorter::insertionSort(vector<int>& array) {
    for (int i = 1; i < array.size(); i++) {
        int current = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

// Function to merge two halves
void Sorter::merge(int left[], int leftSize, int right[], int rightSize, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            result[k++] = left[i++];
        else
            result[k++] = right[j++];
    }

    while (i < leftSize)
        result[k++] = left[i++];

    while (j < rightSize)
        result[k++] = right[j++];
}

// Function to implement merge sort
void Sorter::mergeSort(int array[], int size) {
    if (size < 2)
        return;

    // Divide array in half
    int middle = size / 2;

    int *left = new int[middle];
    int *right = new int[size - middle];

    for (int i = 0; i < middle; i++)
        left[i] = array[i];

    for (int i = middle; i < size; i++)
        right[i - middle] = array[i];

    // Sort each half
    mergeSort(left, middle);
    mergeSort(right, size - middle);

    // Merge
    merge(left, middle, right, size - middle, array);

    // Free dynamically allocated memory
    delete[] left;
    delete[] right;
}

int Sorter::partition(vector<int>& array, int start, int end) {
    int pivot = array[end];
    int boundary = start - 1;

    for (int i = start; i <= end; i++) {
        if (array[i] <= pivot) {
            boundary++;
            swap(array[i], array[boundary]);
        }
    }
    return boundary;
}

void Sorter::quickSort(vector<int>& array, int start, int end) {
    // Base condition
    if (start >= end)
        return;
    // Partition the array
    int boundary = partition(array, start, end);
    // Sort left
    quickSort(array, start, boundary - 1);
    // Sort right
    quickSort(array, boundary + 1, end);
}

void Sorter::countingSort(vector<int>& array) {
    int maxNum = *std::max_element(array.begin(), array.end());
    vector<int> countArray(maxNum + 1, 0);

    for (int n : array)
        countArray[n]++;

    int k = 0;
    for (int i = 0; i < countArray.size(); i++) {
        for (int j = 0; j < countArray[i]; j++) {
            array[k++] = i;
        }
    }
}

void Sorter::bucketSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // Find maximum and minimum values in arr
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    // Number of buckets
    int bucketCount = arr.size();
    std::vector<std::vector<int>> buckets(bucketCount);

    // Calculate interval
    double interval = double(maxValue - minValue + 1) / bucketCount;

    // Place each element in its corresponding bucket
    for (int i = 0; i < arr.size(); ++i) {
        int bucketIndex = (arr[i] - minValue) / interval;
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets and concatenate the results
    arr.clear();
    for (auto & bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for (int j : bucket) {
            arr.push_back(j);
        }
    }
}