//===================================================================
// Name         : DiskStack.cpp
// Description  : Implementation file for the DiskStack class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/01/30
//===================================================================

#include "DiskStack.h"
#include "Node.h"
#include <iostream>

//-------------------------------------------------------------------
/**
 * @brief Constructor for DiskStack
 */
DiskStack::DiskStack() :
    _pTopDisk(nullptr)
{
}

//-------------------------------------------------------------------
/**
 * @brief Destructor for DiskStack
 *
 * Deletes all disk nodes in the stack.
 *
 */
DiskStack::~DiskStack()
{
    Node* pNode = PopFromStack();

    while (nullptr != pNode)
    {
        delete pNode;

        pNode = PopFromStack();
    }
}

//-------------------------------------------------------------------
/**
 * @brief Pushes a disk node onto the stack.
 * @return Node* Pointer to the top disk node in the stack.
 *         Returns nullptr if the stack is empty.
 */
void DiskStack::PushToStack(Node* ipNode)
{
    if (nullptr != ipNode)
    {
        ipNode->SetRightNode(_pTopDisk);
        _pTopDisk = ipNode;
    }
}

//-------------------------------------------------------------------
/**
 * @brief Removes the top disk from the stack and returns it.
 * @return Node* Pointer to the disk node that was removed from the stack.
 *         Returns nullptr if the stack is empty.
 */
Node* DiskStack::PopFromStack()
{
    Node* pNode = _pTopDisk;

    if (nullptr != pNode)
    {
        _pTopDisk = pNode->GetRightNode();

        pNode->SetRightNode(nullptr);
    }

    return pNode;
}

//-------------------------------------------------------------------
/**
 * @brief Checks if the stack is empty.
 * @return True if the stack is empty, false otherwise.
 */
bool DiskStack::IsStackEmpty() const
{
    return (nullptr == _pTopDisk);
}

//-------------------------------------------------------------------
/**
 * @brief Prints the contents of the stack.
 */
void DiskStack::PrintStack()
{
    Node* pNode = _pTopDisk;

    while (nullptr != pNode)
    {
        std::cout << "Disk " << pNode->GetData();

        pNode = pNode->GetRightNode();

        if (nullptr != pNode)
            std::cout << ", ";
    }

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Returns the top disk node from the stack.
 */
Node* DiskStack::GetTopDisk() const
{
    return _pTopDisk;
}
