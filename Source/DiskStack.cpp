//===================================================================
// This file contains the implementation of the DiskStack class.
//===================================================================

#include "DiskStack.h"
#include "DiskNode.h"
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
 * @brief Returns the top disk node from the stack.
 * @return DiskNode* Pointer to the top disk node in the stack.
 *         Returns nullptr if the stack is empty.
 */
void DiskStack::PushToStack(DiskNode* ipDiskNode)
{
    if (nullptr != ipDiskNode)
    {
        ipDiskNode->SetNextDiskNode(_pTopDisk);
        _pTopDisk = ipDiskNode;
    }
}

//-------------------------------------------------------------------
/**
 * @brief Removes the top disk from the stack and returns it.
 * @return DiskNode* Pointer to the disk node that was removed from the stack.
 *         Returns nullptr if the stack is empty.
 */
DiskNode* DiskStack::PopFromStack()
{
    DiskNode* pDiskNode = _pTopDisk;

    if (nullptr != pDiskNode)
    {
        _pTopDisk = pDiskNode->GetNextDiskNode();

        pDiskNode->SetNextDiskNode(nullptr);
    }

    return pDiskNode;
}

//-------------------------------------------------------------------
/**
 * @brief Prints the contents of the stack.
 */
void DiskStack::PrintStack()
{
    DiskNode* pDiskNode = _pTopDisk;

    while (nullptr != pDiskNode)
    {
        std::cout << "Disk " << pDiskNode->GetDiskNumber();

        pDiskNode = pDiskNode->GetNextDiskNode();

        if (nullptr != pDiskNode)
            std::cout << ", ";
    }

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Returns the top disk node from the stack.
 */
DiskNode* DiskStack::GetTopDisk() const
{
    return _pTopDisk;
}
