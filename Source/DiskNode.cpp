//===================================================================
// This file contains the implementation of the DiskNode class.
//===================================================================

#include "DiskNode.h"
#include <iostream>

//-------------------------------------------------------------------
/**
 * @brief Constructor for DiskNode
 * @param inDiskNumber Disk number
 */
DiskNode::DiskNode(const int inDiskNumber) :
    _nDiskNumber(inDiskNumber),
    _pPreviousDiskNode(nullptr),
    _pNextDiskNode(nullptr)
{
}

//-------------------------------------------------------------------
/**
 * @brief This identifies the disk number
 * @return Disk number
 */
int DiskNode::GetDiskNumber() const
{
    return _nDiskNumber;
}

//-------------------------------------------------------------------
/**
 * @brief Returns the previous disk node
 * @return Previous disk node
 */
DiskNode* DiskNode::GetPreviousDiskNode() const
{
    return _pPreviousDiskNode;
}

//-------------------------------------------------------------------
/**
 * @brief Retrieves the next DiskNode in the sequence.
 *
 * This function returns a pointer to the next DiskNode in the sequence.
 * It is a constant member function, meaning it does not modify any member variables.
 *
 * @return DiskNode* Pointer to the next DiskNode.
 */
DiskNode* DiskNode::GetNextDiskNode() const
{
    return _pNextDiskNode;
}

//-------------------------------------------------------------------
/**
 * @brief Sets the next disk node in the sequence.
 * @param ipNextDiskNode Pointer to the next disk node in the sequence.
 */
void DiskNode::SetNextDiskNode(DiskNode* ipNextDiskNode)
{
    _pNextDiskNode = ipNextDiskNode;
}
