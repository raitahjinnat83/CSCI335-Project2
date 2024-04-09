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

struct AVLNode {
    int element;
    AVLNode *left;
    AVLNode *right;
    int height;
    int duplicates;
    AVLNode(const int & e, AVLNode *leftTree, AVLNode *rightTree, int h = 0, int d = 0)
        : element{e}, left{leftTree}, right{rightTree}, height{h} {} // copy constructor
    AVLNode(int && e, AVLNode *leftTree, AVLNode *rightTree, int h = 0, int d = 0)
        : element{std::move(e)}, left{leftTree}, right{rightTree}, height{h} {} // move constructor
};

bool contains(const int & x, AVLNode *tree);
void insert(const int & x, AVLNode * &tree);
void remove(const int & x, AVLNode * &tree);
void balance(AVLNode * &tree);
AVLNode * findMin(AVLNode *tree);
AVLNode * findMax(AVLNode *tree);
int height(AVLNode *tree);
void rotateWithLeftChild(AVLNode * & k2);
void rotateWithRightChild(AVLNode * & k1);
void doubleWithLeftChild(AVLNode * & k3);
void doubleWithRightChild(AVLNode * & k1);
void treeMedian(const vector<int> * instructions);

#endif