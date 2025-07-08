#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <utility> 

struct MergeSortMetrics {
    long long comparisons;
    long long swaps;

    MergeSortMetrics() : comparisons(0), swaps(0) {}
  };
}
#endif // MERGE_SORT_HPP
