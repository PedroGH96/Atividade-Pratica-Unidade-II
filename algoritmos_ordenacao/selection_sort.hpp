#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <utility> 

struct SelectionSortMetrics {
    long long comparisons;
    long long swaps;

    SelectionSortMetrics() : comparisons(0), swaps(0) {}
};

void selectionSort(std::vector<int>& arr, SelectionSortMetrics& metrics) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            metrics.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
            metrics.swaps++;
        }
    }
}

#endif 

