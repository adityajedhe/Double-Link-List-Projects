//===================================================================
// Name         : DiskStack.cpp
// Description  : Implementation file for the DiskStack class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/01/30
//===================================================================

// ---------------------------------------------- Local headers
#include "DiskStack.h"

// ---------------------------------------------- Project headers
#include "Node.h"

// ---------------------------------------------- System headers
#include <iostream>

//-------------------------------------------------------------------
/**
 * @brief Constructor for DiskStack
 */
DiskStack::DiskStack() : _pTopDisk(nullptr)
{
}

//-------------------------------------------------------------------
/**
 * @brief Destructor for DiskStack
 * @note Deletes all the nodes which are stacked onto the disk.
 */
DiskStack::~DiskStack()
{
    Node *pNode = PopFromStack();

    while (nullptr != pNode)
    {
        delete pNode;

        pNode = PopFromStack();
    }
}

//-------------------------------------------------------------------
/**
 * @brief Pushes a disk node onto the stack.
 * @param[in] ipNode Pointer to the disk node to be pushed onto the stack.
 */
void DiskStack::PushToStack(Node *ipNode)
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
Node *DiskStack::PopFromStack()
{
    Node *pNode = _pTopDisk;

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
 * @return Returns True if the stack is empty, false otherwise.
 */
bool DiskStack::IsStackEmpty() const
{
    bool bEmpty(false);

    if (nullptr == _pTopDisk)
    {
        std::cout << "ERR<<Stack is empty.>>" << std::endl;
        bEmpty = true;
    }

    return bEmpty;
}

//-------------------------------------------------------------------
/**
 * @brief Prints the contents of the stack.
 */
void DiskStack::PrintStack() const
{
    Node *pNode = _pTopDisk;

    while (nullptr != pNode)
    {
        std::cout << "Disk " << pNode->GetData();

        pNode = pNode->GetRightNode();

        if (nullptr != pNode)
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Returns the top disk node from the stack.
 */
Node *DiskStack::GetTopDisk() const
{
    return _pTopDisk;
}
