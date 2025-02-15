//===================================================================
// Name         : main.cpp
// Description  : This file contains the main function that lists
// all the operations that can be performed on a binary tree.
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/10
//===================================================================

// ---------------------------------------------- Local Headers
#include "BinaryTree.h"

// ---------------------------------------------- System Headers
#include <iostream>
#include <vector>

/**
 * @brief Main function to list all the operations that can be performed on a binary tree
 * List of operations:
 */
int main()
{
    std::vector<int> vValues = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

    BinaryTree *pBinaryTree_1 = BinaryTree::CreateBinaryTree();

    if (nullptr == pBinaryTree_1)
        return 0;

    for (auto nValue : vValues)
    {
        pBinaryTree_1->InsertInBinaryTree(nValue);
    }

    std::cout << "List of operations:\
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

    BinaryTree::RemoveBinaryTree(pBinaryTree_1);

    return 0;
}
