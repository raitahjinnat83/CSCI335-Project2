/**
 * @file myVector.cpp
 * @author Raitah Jinnat
 * @brief ontaining the function void vectorMedian (const std::vector<int> * instructions)
 * @version 0.1
 * @date 2024-04-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "myVector.hpp"

void vectorMedian(const std::vector<int>* instructions) {
    std::vector<int> result; // set up empty vector of results
    std::vector<int> medians; // set up empty vector of medians to print later
    int current_median;
    for(int num : *instructions) {
        if(num > -1) { // insert number
            auto it = lower_bound(result.begin(), result.end(), num);
            result.insert(it, num);
        }
        else { // pop the median by printing it and removing it from the result
            if(result.size() % 2 == 0) { // if the result's size is currently even
                current_median = result[result.size()/2 - 1];
            }
            else {
                current_median = result[result.size()/2]; // odd scenario
            }
            // regardless of the current median, it needs to be removed
            medians.push_back(current_median); // add current median to the vector to be printed out
            auto it_2 = find(result.begin(), result.end(), current_median); // find the current median
            result.erase(it_2); // erase the current median
        }
    }
    for(int mid : medians) {
        std::cout << mid << " "; // print the current medians
    }
}