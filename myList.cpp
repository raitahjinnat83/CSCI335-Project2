/**
 * @file myList.cpp
 * @author Raitah Jinnat
 * @brief 
 * @version 0.1
 * @date 2024-04-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "myList.hpp"

void listMedian(const std::vector<int>* instructions) {
    std::list<int> result{}; // set up empty list of results
    int current_median; // set up current median

    for (int num : *instructions) {
        if(num > -1) { // insert number
            auto it = lower_bound(result.begin(), result.end(), num);
            result.insert(it, num);
        }
         else { // pop the median by printing it and removing it from the result
            auto it_med = result.begin();
            if(result.size() % 2 == 0) { // even scenario
                std::advance(it_med, result.size()/2 - 1);
            }
            else{ // odd scenario
                std::advance(it_med, result.size()/2);
            }
            current_median = *it_med;
            std::cout << current_median << " "; // print current median
            result.remove(current_median);
        }
    }
}
