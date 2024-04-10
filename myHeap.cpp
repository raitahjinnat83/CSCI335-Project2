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
    
    std::priority_queue<int> small; // for elements <= median so the median is the top popped off
    std::priority_queue<int, std::vector<int>, std::greater<int> > large; // for elements > median
    std::vector<int> medians; // set up empty vector of medians to print later
    int current_median;

    // auto start = std::chrono::high_resolution_clock::now(); // start time
    for (int num : *instructions) {
        if (num > -1) {
            // Insert the number into the appropriate heap (small or large)
            if (small.empty() || num <= small.top()) {
                small.push(num);
            } else {
                large.push(num);
            }

            // Rebalance the heaps if necessary
            if (small.size() > large.size() + 1) {
                large.push(small.top());
                small.pop();
            } else if (large.size() > small.size()) {
                small.push(large.top());
                large.pop();
            }
        } 
        else {
            // The current median is the top of the small heap (max heap)
            int current_median = small.top();
            medians.push_back(current_median); // Store current median

            // Remove the current median from the small heap
            small.pop();

            // Rebalance the heaps if necessary after removing the median
            if (large.size() > small.size()) {
                small.push(large.top());
                large.pop();
            }
        }
    }

    // auto end = std::chrono::high_resolution_clock::now(); // end time
    
    // std::chrono::duration<double, std::micro> elapsed = end - start; // calculate elapsed time

    // // Output the execution time in microseconds
    // std::cout << "Execution time: " << elapsed.count() << " microseconds" << std::endl;

    for(int mid : medians) {
        std::cout << mid << " "; // print the current medians
    }
}