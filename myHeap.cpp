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
    std::vector<int> medians; // set up empty vector of medians to print later
    int current_median;

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
                current_median = maxHeap.top();
                medians.push_back(current_median); // add current median to the vector to be printed out
                maxHeap.pop();
            } 
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } 
        else {
            // Pop the current median (which is the root of maxHeap)
            current_median = maxHeap.top();
            medians.push_back(current_median); // add current median to the vector to be printed out
            maxHeap.pop();
        }
    }
    for(int mid : medians) {
        std::cout << mid << " "; // print the current medians
    }
}