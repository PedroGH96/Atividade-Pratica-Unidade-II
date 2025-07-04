#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <algorithm>

#include "data_generator.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"


template <typename SortFunc, typename MetricsType>
void run_sort_and_collect_metrics(
    const std::string& algorithm_name,
    SortFunc sort_func,
    std::vector<int> data,
    std::ofstream& output_file,
    MetricsType& metrics_obj
) {
    auto start_time = std::chrono::high_resolution_clock::now();
    sort_func(data, metrics_obj);
    auto end_time = std::chrono::high_resolution_clock::now();
    double time_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1e6;

    output_file << algorithm_name << ","
                << data.size() << ","
                << time_ms << ","
                << metrics_obj.comparisons << ","
                << metrics_obj.swaps << "\n";
}


template <typename SortFunc, typename MetricsType>
void run_sort_and_collect_metrics_recursive(
    const std::string& algorithm_name,
    SortFunc sort_func,
    std::vector<int> data,
    std::ofstream& output_file,
    MetricsType& metrics_obj
) {
    auto start_time = std::chrono::high_resolution_clock::now();
    sort_func(data, 0, data.size() - 1, metrics_obj);
    auto end_time = std::chrono::high_resolution_clock::now();
    double time_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1e6;

    output_file << algorithm_name << ","
                << data.size() << ","
                << time_ms << ","
                << metrics_obj.comparisons << ","
                << metrics_obj.swaps << "\n";
}

int main() {
    std::vector<int> small_sizes = {100, 500, 1000, 2000}; 
    std::vector<int> large_sizes = {1000, 5000, 10000, 20000};
    std::vector<std::string> data_types = {"random", "nearly_sorted", "inversely_sorted"};

    std::ofstream output_file("sorting_metrics.csv");
    output_file << "Algorithm,Size,Time_ms,Comparisons,Swaps\n";

    for (const std::string& type : data_types) {
       
        for (int size : small_sizes) {
            std::vector<int> original_data;
            if (type == "random") {
                original_data = DataGenerator::generateRandom(size);
            } else if (type == "nearly_sorted") {
                original_data = DataGenerator::generateNearlySorted(size);
            } else if (type == "inversely_sorted") {
                original_data = DataGenerator::generateInverselySorted(size);
            }

            //BubbleSort
            BubbleSortMetrics bubble_metrics;
            run_sort_and_collect_metrics("BubbleSort_" + type, bubbleSort, original_data, output_file, bubble_metrics);

            //InsertionSort
            InsertionSortMetrics insertion_metrics;
            run_sort_and_collect_metrics("InsertionSort_" + type, insertionSort, original_data, output_file, insertion_metrics);

            //SelectionSort
            SelectionSortMetrics selection_metrics;
            run_sort_and_collect_metrics("SelectionSort_" + type, selectionSort, original_data, output_file, selection_metrics);
        }

        // O(N log N) algorithms
        for (int size : large_sizes) {
            std::vector<int> original_data;
            if (type == "random") {
                original_data = DataGenerator::generateRandom(size);
            } else if (type == "nearly_sorted") {
                original_data = DataGenerator::generateNearlySorted(size);
            } else if (type == "inversely_sorted") {
                original_data = DataGenerator::generateInverselySorted(size);
            }

            //MergeSort
            MergeSortMetrics merge_metrics;
            run_sort_and_collect_metrics_recursive("MergeSort_" + type, mergeSort, original_data, output_file, merge_metrics);

            //QuickSort
            QuickSortMetrics quick_metrics;
            run_sort_and_collect_metrics_recursive("QuickSort_" + type, quickSort, original_data, output_file, quick_metrics);
        }
    }

    output_file.close();
    std::cout << "Metrics collected and saved to sorting_metrics.csv\n";

    return 0;
}

