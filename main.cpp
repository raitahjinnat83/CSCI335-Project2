/**
 * @file main.cpp
 * @author Raitah Jinnat (raitah.jinnat83@myhunter.cuny.edu)
 * @brief reads input from file, converts it to an integer, and passes it to each method
 * @version 0.1
 * @date 2024-04-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;
// 04/06: inclusion of header files which have not been implemented yet.
#include "myVector.hpp"
#include "myList.hpp"
// #include "myHeap.hpp"
// #include "myAVLtree.hpp"

int main(){

    std::vector<int> vector_of_test_instructions_; // set up an empty vector of integers corresponding to each instruction in the test file
    std::ifstream inputFile("testinput.txt"); // set up the file path corresponding to the input file

    // account for error in opening the test file
    if (!inputFile.is_open()) { 
        std::cerr << "NAWT OPEN"; 
        return -1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string instruction;
        iss >> instruction;

        if (instruction == "insert") {
            int number;
            if (iss >> number) {
                vector_of_test_instructions_.push_back(number);
            }
        } else { // assume the line reads "pop median"
            vector_of_test_instructions_.push_back(-1);
        }
    }

    vectorMedian(&vector_of_test_instructions_); // tested and works locally
    listMedian(&vector_of_test_instructions_); // tested: 595.0 out of 4993 medians correct

    /*
    make sure the main file can actually convert the test file first.
    however, do not actually print the resulting vector. 
    just pass the vector thru each of the instructions
    
    for (int num : vector_of_test_instructions_) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    */ 

}