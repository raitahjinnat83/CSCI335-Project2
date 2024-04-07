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

void vectorMedian(const std::vector<int> & instructions) {
    std::vector<int> result; // set up empty vector of results
    for(int num : instructions) {
        if(num > -1) { // insert instructions
            auto it = lower_bound(result.begin(), result.end(), num);
            result.insert(it, num);
        }
        else { // pop the median by returning and removing it from the result
            
        }
    }
}