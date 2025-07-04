#include "insertion_sort.hpp"

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

