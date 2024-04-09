/**
 * @file myAVLTree.hpp
 * @author Raitah Jinnat
 * @brief containing your implementation of an AVL tree data structure
 * @version 0.1
 * @date 2024-04-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <iostream> 
#include <string>
#include <vector>
using namespace std;

struct AvlNode {
    int element;
    AvlNode *left;
    AvlNode *right;
    int height;
    int duplicates;
    int size;
    AvlNode(const int & ele, AvlNode *lt, AvlNode *rt, int h = 0, int d = 0, int s = 0)
        : element{ele}, left{lt}, right{rt}, height{h}, duplicates{d}, size{s} {} // copy constructor
    AvlNode(int && ele, AvlNode *lt, AvlNode *rt, int h = 0, int d = 0, int s = 0)
        : element{std::move(ele)}, left{lt}, right{rt}, height{h}, duplicates{d}, size{d} {} // move constructor
};

bool contains(const int & x, AvlNode *t);
void insert(const int & x, AvlNode * &t);
void remove(const int & x, AvlNode * &t);
void balance(AvlNode * &t);
AvlNode * findMin(AvlNode *t);
AvlNode * findMax(AvlNode *t);
int height(AvlNode *t);
void rotateWithLeftChild(AvlNode * & k2);
void rotateWithRightChild(AvlNode * & k1);
void doubleWithLeftChild(AvlNode * & k3);
void doubleWithRightChild(AvlNode * & k1);
void treeMedian(const vector<int> * instructions);

#endif