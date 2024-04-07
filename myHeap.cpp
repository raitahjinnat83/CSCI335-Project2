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
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // for elements > median

    for (int num : *instructions) {
        if (num > -1) {
            // Insert the number into the appropriate heap
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Balance the heaps if necessary
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } else {
            // Pop the current median (which is the root of maxHeap)
            int current_median = maxHeap.top();
            std::cout << current_median << " "; // print it before popping
            maxHeap.pop();
        }
    }
}