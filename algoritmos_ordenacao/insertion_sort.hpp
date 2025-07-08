#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>

struct InsertionSortMetrics {
    long long comparisons;
    long long swaps;

    InsertionSortMetrics() : comparisons(0), swaps(0) {}
};


#endif 

