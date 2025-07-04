#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>

struct InsertionSortMetrics {
    long long comparisons;
    long long swaps;

    InsertionSortMetrics() : comparisons(0), swaps(0) {}
};

void insertionSort(std::vector<int>& arr, InsertionSortMetrics& metrics) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            metrics.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                metrics.swaps++; 
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

#endif 

