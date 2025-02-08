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
    _pLeftNode(nullptr),
    _pRightNode(nullptr)
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
 * @brief Retrieves the left node
 * @return Pointer to the left node
 */
Node* Node::GetLeftNode() const
{
    return _pLeftNode;
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the right node
 * @return Pointer to the right node
 */
Node* Node::GetRightNode() const
{
    return _pRightNode;
}

//-------------------------------------------------------------------
/**
 * @brief Sets the left node
 * @param ipLeftNode Pointer to the left node
 */
void Node::SetLeftNode(Node* ipLeftNode)
{
    _pLeftNode = ipLeftNode;
}

//-------------------------------------------------------------------
/**
 * @brief Sets the right node
 * @param ipRightNode Pointer to the right node
 */
void Node::SetRightNode(Node* ipRightNode)
{
    _pRightNode = ipRightNode;
}
