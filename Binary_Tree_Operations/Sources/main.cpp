//-------------------------------------------------------------------
/**
 * @file main.cpp
 * @brief The file contains the main function of the project
 * @details This file lists all the operations that can be performed on a binary tree.
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

/**
 * @brief Displays the list of all the operations of binary tree
 * @return Option number chosen by user w.r.t. the operation
 */
int RetrieveUserOperation();

/**
 * @brief Perform the operation on binary tree base on user selected option
 * @param[in] ipBinaryTree Binary tree on which operation will be performed
 * @param[in] inOption An option selected by user
 */
void PerformOperation(BinaryTree *ipBinaryTree, int inOption);

//-------------------------------------------------------------------
int main()
{
    BinaryTree *pBinaryTree = RetrieveInitialisedTree();

    int nOption = RetrieveUserOperation();

    PerformOperation(pBinaryTree, nOption);

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
int RetrieveUserOperation()
{
    std::cout
        << "List of operations:\
                  01. Insert a node in the binary tree\
                  02. Insert a node in the binary search tree\
                  03. Delete a node from the binary tree[Not yet impl'd]\
                  04. Search for a node in the binary tree\
                  05. Search for a node in the binary search tree[Not yet impl'd]\
                  06. Traverse the binary tree: Pre-order\
                  06. Traverse the binary tree: In-order\
                  07. Traverse the binary tree: Post-order\
                  08. Traverse the binary tree: Level-order\
                  09. Traverse the binary tree: Reverse-Level-order[Not yet impl'd]\
                  10. Traverse the binary tree: Spiral-order[Not yet impl'd]\
                  11. Print all the leaf nodes in the binary tree\
                  12. Print all the non-leaf nodes in the binary tree\
                  13. Print all the full nodes in the binary tree\
                  14. Print all the half nodes in the binary tree\
                  15. Print all the siblings of a node in the binary tree\
                  16. Print all the ancestors of a node in the binary tree\
                  17. Print all the descendants of a node in the binary tree\
                  18. Find the height of the binary tree\
                  19. Find the depth of a node in the binary tree[Not yet impl'd]\
                  20. Find the level of a node in the binary tree\
                  21. Find the all the nodes at the border of the binary tree"
        << std::endl;

    int nOption(0);

    std::cin >> nOption;

    return nOption;
}

//-------------------------------------------------------------------
void PerformOperation(BinaryTree *ipBinaryTree, int inOption)
{
    if ((nullptr == ipBinaryTree) || (1 > inOption) || (21 < inOption))
    {
        return;
    }

    switch (inOption)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    }
}
