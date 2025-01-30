#include <iostream>
#include "DiskNode.h"
#include "DiskStack.h"

//-------------------------------------------------------------------
/**
 * @brief Function to solve the Tower of Hanoi problem
 * @param inDisk Number of disks
 * @param ipSourceRod Pointer to the source rod
 * @param ipDestinationRod Pointer to the destination rod
 * @param ipHelperRod Pointer to the helper rod
 *
 * @note This function is a recursive function that solves the Tower of Hanoi problem.
 */
void TowerOfHanoi(const int inDisk, DiskStack* ipSourceRod, DiskStack* ipDestinationRod, DiskStack* ipHelperRod)
{
    DiskNode* pDiskNode = nullptr;

    if (1 == inDisk)
    {
        pDiskNode = ipSourceRod->PopFromStack();
        ipDestinationRod->PushToStack(pDiskNode);
    }
    else
    {
        TowerOfHanoi(inDisk - 1, ipSourceRod, ipHelperRod, ipDestinationRod);

        pDiskNode = ipSourceRod->PopFromStack();
        ipDestinationRod->PushToStack(pDiskNode);

        TowerOfHanoi(inDisk - 1, ipHelperRod, ipDestinationRod, ipSourceRod);
    }
}

//-------------------------------------------------------------------
/**
 * @brief Main function
 */
int main()
{
    // Number of disks
    // ---------------
    int nbDisks = 6;

    // Create three stacks for the three rods
    // DiskStack A is the source rod,
    // DiskStack B is the auxiliary rod, and
    // DiskStack C is the destination rod
    // --------------------------------------
    DiskStack* pStackA = new DiskStack();
    DiskStack* pStackB = new DiskStack();
    DiskStack* pStackC = new DiskStack();

    if (nullptr == pStackA || nullptr == pStackB || nullptr == pStackC)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return -1;
    }

    DiskNode* pDiskNode = nullptr;

    // Push the disks onto the source rod
    // ----------------------------------
    for (int nDiskIndex = nbDisks; nDiskIndex > 0; --nDiskIndex)
    {
        pDiskNode = new DiskNode(nDiskIndex);

        if (nullptr == pDiskNode)
        {
            std::cout << "Memory allocation failed" << std::endl;
            return -1;
        }

        // Set the previous disk node to the top disk node
        // This has to be done only once i.e. while initializing the stack
        // ---------------------------------------------------------------
        DiskNode* pTopDisk = pStackA->GetTopDisk();

        if (nullptr != pTopDisk)
            pTopDisk->SetPreviousDiskNode(pDiskNode);

        // Push the disk onto the source rod
        // ---------------------------------
        pStackA->PushToStack(pDiskNode);
    }

    TowerOfHanoi(nbDisks, pStackA, pStackC, pStackB);

    return 0;
}