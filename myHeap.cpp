/**
 * @file myHeap.cpp
 * @author Raitah Jinnat
 * @brief containing the function void heapMedian (const std::vector<int> * instructions)
 * @version 0.1
 * @date 2024-04-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "myHeap.hpp"

void heapMedian(const std::vector<int>* instructions) {
    // Using a max heap holding all elements <= the median and a min heap holding all elements > the median
    
    std::priority_queue<int> maxHeap; // for elements <= median so the median is the top popped off
    std::priority_queue<int> minHeap; // for elements > median

    
}