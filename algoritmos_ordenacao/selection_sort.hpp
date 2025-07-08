#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <utility> 

struct SelectionSortMetrics {
    long long comparisons;
    long long swaps;

    SelectionSortMetrics() : comparisons(0), swaps(0) {}
  };
}

#endif 

