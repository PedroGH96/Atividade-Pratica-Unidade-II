#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include <vector>
#include <random>
#include <algorithm>

namespace DataGenerator {

    std::vector<int> generateRandom(int size) {
        std::vector<int> arr(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, size * 10);
        for (int i = 0; i < size; ++i) {
            arr[i] = distrib(gen);
        }
        return arr;
    }

    std::vector<int> generateNearlySorted(int size) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = i;
        }
       
        std::random_device rd;
        std::mt19937 gen(rd());
        int swaps = size / 100; 
        for (int i = 0; i < swaps; ++i) {
            int idx1 = std::uniform_int_distribution<>(0, size - 1)(gen);
            int idx2 = std::uniform_int_distribution<>(0, size - 1)(gen);
            std::swap(arr[idx1], arr[idx2]);
        }
        return arr;
    }

    std::vector<int> generateInverselySorted(int size) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = size - 1 - i;
        }
        return arr;
    }

}

#endif

