//===================================================================
// Name         : BinaryTree.cpp
// Description  : Implementation file for the BinaryTree class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/05
//===================================================================

#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

//-------------------------------------------------------------------
/**
 * @brief Constructor for BinaryTree
 */
BinaryTree::BinaryTree() :
    _pRootNode(nullptr)
{
}

//-------------------------------------------------------------------
/**
 * @brief Destructor for BinaryTree
 *
 * Deletes all nodes in the binary tree.
 *
 */
BinaryTree::~BinaryTree()
{
    RemoveChildren(_pRootNode);

    _pRootNode = nullptr;
}

//-------------------------------------------------------------------
/**
 * @brief Removes all children of a given node
 * @param pParentNode Parent node whose children are to be removed
 * @return True if the children are removed, false otherwise
 */
void BinaryTree::RemoveChildren(Node* pParentNode)
{
    if (nullptr == pParentNode)    return;

    RemoveChildren(pParentNode->GetLeftChild());
    RemoveChildren(pParentNode->GetRightChild());

    delete pParentNode;
    pParentNode = nullptr;
}

//-------------------------------------------------------------------
/**
 * @brief Checks if the binary tree is empty
 * @return True if the binary tree is empty, false otherwise
 */
bool BinaryTree::IsEmpty()
{
    return (nullptr == _pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Inserts a new data element into the binary search tree
 *
 * The binary search tree is a data structure in which each node has at most two children, referred to as the left child and the right child. Also no two nodes have the same data element. The left child of a node has a value less than the parent node, and the right child has a value greater than the parent node.
 *
 * @param inData Data element to insert
 */
void BinaryTree::InsertInBinarySearchTree(int inData)
{
    /**
     * Create a new node with the data element
     * and insert it into the binary search tree
     */
    Node* pNewNode = new Node(inData);

    if (nullptr != _pRootNode)
    {
        Node* pCurrentNode = _pRootNode;
        Node* pParentNode = nullptr;

        while (nullptr != pCurrentNode)
        {
            pParentNode = pCurrentNode;

            if (inData < pCurrentNode->GetData())
            {
                pCurrentNode = pCurrentNode->GetLeftChild();
            }
            else
            {
                pCurrentNode = pCurrentNode->GetRightChild();
            }
        }

        if (inData < pParentNode->GetData())
        {
            pParentNode->SetLeftChild(pNewNode);
        }
        else
        {
            pParentNode->SetRightChild(pNewNode);
        }
    }
    else
    {
        _pRootNode = pNewNode;
    }
}

//-------------------------------------------------------------------
/**
 * @brief Deletes a data element from the binary tree
 * @param inData Data element to delete
 */
void BinaryTree::Delete(int inData)
{
    std::cout << "Deleting data element: " << inData << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Returns the height of the binary tree
 *
 * The height of a binary tree is the number of edges on the longest path between the root node and a leaf node.
 *
 * @return Height of the binary tree
 */
int BinaryTree::HeightOfBinaryTree()
{
    return HeightOfBinaryTreeNode(_pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Performs an in-order traversal of the binary tree
 *
 * Prints all elements in the binary tree in in-order sequence.
 *
 */
void BinaryTree::InOrderTraversal()
{
    InOrderTraversalOfBinaryTreeNode(_pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Returns the height of the given binary tree node
 *
 * The height of a given binary tree node is the number of edges on the longest path between the given node and a leaf node.
 *
 * @param pNode Node whose height is to be calculated
 * @return Height of the binary tree
 */
int BinaryTree::HeightOfBinaryTreeNode(Node* pNode)
{
    int nHeight(-1);

    if (nullptr != pNode)
    {
        int nLeftHeight = HeightOfBinaryTreeNode(pNode->GetLeftChild());
        int nRightHeight = HeightOfBinaryTreeNode(pNode->GetRightChild());

        nHeight = (nLeftHeight > nRightHeight) ? (nLeftHeight + 1) : (nRightHeight + 1);
    }

    return nHeight;
}

//-------------------------------------------------------------------
/**
 * @brief Performs an in-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in in-order sequence.
 *
 * @param pNode Node to traverse
 */
void BinaryTree::InOrderTraversalOfBinaryTreeNode(Node* pNode)
{
    if (nullptr == pNode)    return;

    InOrderTraversalOfBinaryTreeNode(pNode->GetLeftChild());

    // Print the data element
    // ----------------------------------
    std::cout << pNode->GetData() << " ";

    InOrderTraversalOfBinaryTreeNode(pNode->GetRightChild());
}

//-------------------------------------------------------------------
/**
 * @brief Performs an pre-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in pre-order sequence.
 *
 * @param pNode Node to traverse
 */
void BinaryTree::PreOrderTraversalOfBinaryTreeNode(Node* pNode)
{
    if (nullptr == pNode)    return;

    // Print the data element
    // ----------------------------------
    std::cout << pNode->GetData() << " ";

    PreOrderTraversalOfBinaryTreeNode(pNode->GetLeftChild());

    PreOrderTraversalOfBinaryTreeNode(pNode->GetRightChild());
}

//-------------------------------------------------------------------
/**
 * @brief Performs an post-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in post-order sequence.
 *
 * @param pNode Node to traverse
 */
void BinaryTree::PostOrderTraversalOfBinaryTreeNode(Node* pNode)
{
    if (nullptr == pNode)    return;

    PostOrderTraversalOfBinaryTreeNode(pNode->GetLeftChild());

    PostOrderTraversalOfBinaryTreeNode(pNode->GetRightChild());

    // Print the data element
    // ----------------------------------
    std::cout << pNode->GetData() << " ";
}

//-------------------------------------------------------------------
