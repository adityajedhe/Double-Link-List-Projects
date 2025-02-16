/**
 * @file    Node.cpp
 * @brief   Implementation file for the Node class
 * @author  Aditya Jedhe
 * @date    2025-02-05
 */

// ---------------------------------------------- Project Headers
#include "Node.h"

//===================================================================
// Public member functions
//===================================================================

//-------------------------------------------------------------------
Node::Node(const int inData) : _nData(inData),
                               _pLeftNode(nullptr),
                               _pRightNode(nullptr)
{
}

//-------------------------------------------------------------------
Node::~Node()
{
    _pLeftNode = nullptr;
    _pRightNode = nullptr;
}

//-------------------------------------------------------------------
int Node::GetData() const
{
    return _nData;
}

//-------------------------------------------------------------------
Node *Node::GetLeftNode() const
{
    return _pLeftNode;
}

//-------------------------------------------------------------------
Node *Node::GetRightNode() const
{
    return _pRightNode;
}

//-------------------------------------------------------------------
void Node::SetLeftNode(Node *ipLeftNode)
{
    _pLeftNode = ipLeftNode;
}

//-------------------------------------------------------------------
void Node::SetRightNode(Node *ipRightNode)
{
    _pRightNode = ipRightNode;
}
