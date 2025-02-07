//===================================================================
// Name         : BinaryTreeNode.cpp
// Description  : Implementation file for the BinaryTreeNode class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/05
//===================================================================

#include "BinaryTreeNode.h"

//-------------------------------------------------------------------
/**
 * @brief Constructor for BinaryTreeNode
 * @param inData Data element to store in the node
 */
BinaryTreeNode::BinaryTreeNode(const int inData) :
    _nData(inData),
    _pLeftChild(nullptr),
    _pRightChild(nullptr)
{
}

//-------------------------------------------------------------------
/**
 * @brief Destructor for BinaryTreeNode
 */
BinaryTreeNode::~BinaryTreeNode()
{
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the data element stored in the node
 * @return Data element stored in the node
 */
int BinaryTreeNode::GetData() const
{
    return _nData;
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the left child node
 * @return Pointer to the left child node
 */
BinaryTreeNode* BinaryTreeNode::GetLeftChild() const
{
    return _pLeftChild;
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the right child node
 * @return Pointer to the right child node
 */
BinaryTreeNode* BinaryTreeNode::GetRightChild() const
{
    return _pRightChild;
}

//-------------------------------------------------------------------
/**
 * @brief Sets the left child node
 * @param ipLeftChild Pointer to the left child node
 */
void BinaryTreeNode::SetLeftChild(BinaryTreeNode* ipLeftChild)
{
    _pLeftChild = ipLeftChild;
}

//-------------------------------------------------------------------
/**
 * @brief Sets the right child node
 * @param ipRightChild Pointer to the right child node
 */
void BinaryTreeNode::SetRightChild(BinaryTreeNode* ipRightChild)
{
    _pRightChild = ipRightChild;
}
