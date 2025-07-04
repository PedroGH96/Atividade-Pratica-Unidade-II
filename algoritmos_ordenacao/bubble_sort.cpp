#include "bubble_sort.hpp"

void bubbleSort(std::vector<int>& arr, BubbleSortMetrics& metrics) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            metrics.comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                metrics.swaps++;
            }
        }
    }
}


