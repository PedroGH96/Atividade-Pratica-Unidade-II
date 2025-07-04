#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>
#include <utility> 

struct BubbleSortMetrics {
    long long comparisons;
    long long swaps;

    BubbleSortMetrics() : comparisons(0), swaps(0) {}
};

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

#endif 

