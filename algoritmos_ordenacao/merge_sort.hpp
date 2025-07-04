#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <utility> 

struct MergeSortMetrics {
    long long comparisons;
    long long swaps;

    MergeSortMetrics() : comparisons(0), swaps(0) {}
};

void merge(std::vector<int>& arr, int left, int mid, int right, MergeSortMetrics& metrics) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        metrics.comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        metrics.swaps++; 
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        metrics.swaps++; 
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        metrics.swaps++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right, MergeSortMetrics& metrics) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, metrics);
        mergeSort(arr, mid + 1, right, metrics);
        merge(arr, left, mid, right, metrics);
    }
}




#endif // MERGE_SORT_HPP

