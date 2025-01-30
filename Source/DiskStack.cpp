#include "DiskStack.h"
#include "DiskNode.h"

//-------------------------------------------------------------------
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
 //-------------------------------------------------------------------
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
 //-------------------------------------------------------------------
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
