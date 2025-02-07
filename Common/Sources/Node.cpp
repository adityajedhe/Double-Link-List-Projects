//===================================================================
// Name         : Node.cpp
// Description  : Implementation file for the Node class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/05
//===================================================================

#include "Node.h"

//-------------------------------------------------------------------
/**
 * @brief Constructor for Node
 * @param inData Data element to store in the node
 */
Node::Node(const int inData) :
    _nData(inData),
    _pLeftChild(nullptr),
    _pRightChild(nullptr)
{
}

//-------------------------------------------------------------------
/**
 * @brief Destructor for Node
 */
Node::~Node()
{
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the data element stored in the node
 * @return Data element stored in the node
 */
int Node::GetData() const
{
    return _nData;
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the left child node
 * @return Pointer to the left child node
 */
Node* Node::GetLeftChild() const
{
    return _pLeftChild;
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the right child node
 * @return Pointer to the right child node
 */
Node* Node::GetRightChild() const
{
    return _pRightChild;
}

//-------------------------------------------------------------------
/**
 * @brief Sets the left child node
 * @param ipLeftChild Pointer to the left child node
 */
void Node::SetLeftChild(Node* ipLeftChild)
{
    _pLeftChild = ipLeftChild;
}

//-------------------------------------------------------------------
/**
 * @brief Sets the right child node
 * @param ipRightChild Pointer to the right child node
 */
void Node::SetRightChild(Node* ipRightChild)
{
    _pRightChild = ipRightChild;
}
