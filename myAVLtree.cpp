/**
 * @file myAVLTree.cpp
 * @author Raitah Jinnat
 * @brief containing the function void treeMedian (const std::vector<int> * instructions)
 * @version 0.1
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "myAVLtree.hpp"

// AVL Tree Implementation Sourced from Textbook with Mods
/**
 * insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void insert( const int & x, AvlNode * & t )
{
    if( t == nullptr ) 
        t = new AvlNode{ x, nullptr, nullptr };
    else if (x == t->element)   
        t->duplicates++;   // AVL Tree structure modified to account for dupes     
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    balance( t );
}

/**
 * remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void remove( const int & x, AvlNode * & t )
{
    if( t == nullptr )
    return;   // Item not found; do nothing

    if ((x == t->element) && (t->duplicates > 0))    
        t->duplicates--;   // modified: decrement dupes of x if in tree t
    else if( x < t->element )
        remove( x, t->left );
    else if( t->element < x )
        remove( x, t->right );
    else if( t->left != nullptr && t->right != nullptr ) // Two children
    {
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
    }
    else
    {
        AvlNode *oldNode = t;
        t = ( t->left != nullptr ) ? t->left : t->right;
        delete oldNode;
        oldNode = nullptr;  
    }
    
    balance( t );
}

static const int ALLOWED_IMBALANCE = 1;

// Assume t is balanced or within one of being balanced
void balance( AvlNode * & t )
{
    if( t == nullptr )
        return;
    
    if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
        if( height( t->left->left ) >= height( t->left->right ) )
            rotateWithLeftChild( t );
        else
            doubleWithLeftChild( t );
    else
    if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
        if( height( t->right->right ) >= height( t->right->left ) )
            rotateWithRightChild( t );
        else
            doubleWithRightChild( t );
            
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

/**
 * find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
AvlNode * findMin( AvlNode *t )
{
    if( t == nullptr )
        return nullptr;
    if( t->left == nullptr )
        return t;
    return findMin( t->left );
}

/**
 * find the largest item in a subtree t.
 * Return node containing the largest item.
 */
AvlNode * findMax( AvlNode *t )
{
    if( t != nullptr )
        while( t->right != nullptr )
            t = t->right;
    return t;
}

 /**
 * Return the height of node t or -1 if nullptr.
 */
int height( AvlNode *t )
{
    return t == nullptr ? -1 : t->height;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
void rotateWithLeftChild( AvlNode * & k2 )
{
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}

/**
 * Rotate binary tree node with right child.
 * For AVL trees, this is a single rotation for case 4.
 * Update heights, then set new root.
 */
void rotateWithRightChild( AvlNode * & k1 )
{
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;
    k1 = k2;
}

/**
 * Double rotate binary tree node: first left child.
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
void doubleWithLeftChild( AvlNode * & k3 )
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

/**
 * Double rotate binary tree node: first right child.
 * with its left child; then node k1 with new right child.
 * For AVL trees, this is a double rotation for case 3.
 * Update heights, then set new root.
 */
void doubleWithRightChild( AvlNode * & k1 )
{
    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );
}

void treeMedian (const vector<int> * instructions) {
    AvlNode * small = nullptr; // for elements <= median
    int size_of_small = 0; // track size of small tree
    AvlNode * large = nullptr; // for elements > median
    int size_of_large = 0; // track size of large tree
    std::vector<int> medians;   // set up empty vector of medians to print later

    // auto start = std::chrono::high_resolution_clock::now(); // start time
    
    for (int num : *instructions) { 
         if(num > -1) {    
            // insert number into appropriate AVL 
           if (small == nullptr) {  // insert the first number
            insert(num,small);  
            size_of_small++;   
           } 
           else {
                if (num > findMax(small)->element) {  
                    insert(num,large);  // insert the number into the large tree if it's greater than the median
                    size_of_large++;   
                    // rebalance tree if needed
                    if (size_of_large > size_of_small) {  
                        insert(findMin(large)->element,small);    // place the lowest value of the large to become part of the small tree
                        size_of_small++;   
                        remove(findMin(large)->element,large);    
                        size_of_large--;   
                    }
                } 
                else {    // existing tree 
                    insert(num,small);  
                    size_of_small++;   
                    // rebalance tree if needed
                    if (size_of_small > (size_of_large + 1)) { // if the small tree is too big 
                        insert(findMax(small)->element,large);    
                        size_of_large++;  
                        remove(findMax(small)->element,small);    
                        size_of_small--;   
                    }
                }
           }
        }
        else {  
           medians.push_back(findMax(small)->element);    // add the median to the resulting vector
           remove(findMax(small)->element,small);   // remove the median from the small tree
           size_of_small--;    
           // rebalance tree after if necessary
           if (size_of_large > size_of_small) {  
                insert(findMin(large)->element,small);   
                size_of_small++;   
                remove(findMin(large)->element,large);    
                size_of_large--;   
            }
        }
    } 

    // auto end = std::chrono::high_resolution_clock::now(); // end time

    // std::chrono::duration<double, std::micro> elapsed = end - start;

    // std::cout << "Execution time: " << elapsed.count() << " microseconds" << std::endl;

    for (int mid : medians) {  
        cout << mid << " ";     // print the current medians
    }
}


