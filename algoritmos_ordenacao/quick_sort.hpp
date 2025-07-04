#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>
#include <utility> 

struct QuickSortMetrics {
    long long comparisons;
    long long swaps;

    QuickSortMetrics() : comparisons(0), swaps(0) {}
};

int partition(std::vector<int>& arr, int low, int high, QuickSortMetrics& metrics) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        metrics.comparisons++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            metrics.swaps++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    metrics.swaps++;
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high, QuickSortMetrics& metrics) {
    if (low < high) {
        int pi = partition(arr, low, high, metrics);
        quickSort(arr, low, pi - 1, metrics);
        quickSort(arr, pi + 1, high, metrics);
    }
}

#endif 

