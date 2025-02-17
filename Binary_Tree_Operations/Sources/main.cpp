//-------------------------------------------------------------------
/**
 * @file main.cpp
 * @brief This file contains the main function that lists all the operations that can be performed on a binary tree.
 * @details It contains the algorithm to solve Tower of Hanoi problem.
 * @author Aditya Jedhe
 * @date 2025-02-10
 */
//-------------------------------------------------------------------

// ---------------------------------------------- Local Headers
#include "BinaryTree.h"

// ---------------------------------------------- System Headers
#include <iostream>
#include <vector>

/**
 * @brief Main function to perform the operations that can be performed on a binary tree
 */
int main();

/**
 * @brief Creates and initialises the tree
 * @details A binary tree is constructed by inserting each node sequentially at the current level. Once all nodes at that level are filled, the insertion continues at the next level, and this process repeats.
 * @return Pointer to created BinaryTree instance
 * @note Delete the pointer returned by the method
 */
BinaryTree *RetrieveInitialisedTree();

/**
 * @brief Creates and initialises the binary search tree
 * @details A BinaryTree is constructed by inserting each Node sequentially at the current level. Once all Nodes at that level are filled, the insertion continues at the next level, and this process repeats.
 * @return Pointer to created BinaryTree instance
 * @note Delete the pointer returned by the method
 * @warning Failing to delete the pointer will result in a memory leak.
 */
BinaryTree *RetrieveInitialisedSearchTree();

//-------------------------------------------------------------------
int main()
{
    BinaryTree *pBinaryTree = RetrieveInitialisedTree();

    BinaryTree::RemoveBinaryTree(pBinaryTree);

    return 0;
}

//-------------------------------------------------------------------
BinaryTree *RetrieveInitialisedTree()
{
    BinaryTree *pBinaryTree = BinaryTree::CreateBinaryTree();

    std::vector<int> vValues = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

    for (auto nValue : vValues)
    {
        pBinaryTree->InsertInBinaryTree(nValue);
    }

    return pBinaryTree;
}

//-------------------------------------------------------------------
{
    std::cout
        << "List of operations:\
                  01. Insert a node in the binary tree\
                  02. Delete a node from the binary tree[Not yet impl'd]\
                  03. Search for a node in the binary tree[Not yet impl'd]\
                  03. Search for a node in the binary search tree[Not yet impl'd]\
                  04. Traverse the binary tree: Pre-order\
                  05. Traverse the binary tree: In-order\
                  06. Traverse the binary tree: Post-order\
                  07. Traverse the binary tree: Level-order\
                  07. Traverse the binary tree: Reverse-Level-order[Not yet impl'd]\
                  07. Traverse the binary tree: Spiral-order[Not yet impl'd]\
                  08. Print all the leaf nodes in the binary tree\
                  09. Print all the non-leaf nodes in the binary tree\
                  11. Print all the full nodes in the binary tree\
                  12. Print all the half nodes in the binary tree\
                  13. Print all the siblings of a node in the binary tree\
                  14. Print all the ancestors of a node in the binary tree\
                  15. Print all the descendants of a node in the binary tree\
                  07. Find the height of the binary tree\
                  08. Find the depth of a node in the binary tree[Not yet impl'd]\
                  16. Find the level of a node in the binary tree\
                  17. Find the all the nodes at the border of the binary tree"
        << std::endl;
}