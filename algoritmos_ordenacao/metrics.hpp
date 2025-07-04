#ifndef METRICS_HPP
#define METRICS_HPP

#include <chrono>
#include <vector>
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"

struct Metrics {
    long long comparisons;
    long long swaps;
    double time_ms;

    Metrics() : comparisons(0), swaps(0), time_ms(0.0) {}
};


template <typename SortFunc, typename... Args>
Metrics measurePerformance(Func func, std::vector<int>& arr, Args&&... args) {
    Metrics metrics;

    auto start_time = std::chrono::high_resolution_clock::now();
    func(arr, std::forward<Args>(args)...);
    auto end_time = std::chrono::high_resolution_clock::now();

    metrics.time_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1e6;

    return metrics;
}

#endif 

