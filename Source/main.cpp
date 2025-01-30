//===================================================================
// This file contains the main function that solves the Tower of
// Hanoi problem.
// @author Aditya Jedhe
// @date   2025/01/30
//===================================================================

#include <iostream>
#include "DiskNode.h"
#include "DiskStack.h"


// 
// --------------------------------------------
int nbIterations = 0;

/**
 * @brief Global variables to represent the three rods
 *        Pointer to the DiskStack object representing stack A.
 *        Pointer to the DiskStack object representing stack B.
 *        Pointer to the DiskStack object representing stack C.
 */
DiskStack* pStackA = nullptr;
DiskStack* pStackB = nullptr;
DiskStack* pStackC = nullptr;


//-------------------------------------------------------------------
/**
 * @brief Function to print the contents of the three rods
 */
void PrintStacks()
{
    std::cout << "Iteration: " << nbIterations++ << std::endl;

    std::cout << "       [TOP]" << std::endl;

    std::cout << "Rod A: ";
    pStackA->PrintStack();

    std::cout << "Rod B: ";
    pStackB->PrintStack();

    std::cout << "Rod C: ";
    pStackC->PrintStack();

    std::cout << std::endl << "-----------------------------" << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Function to solve the Tower of Hanoi problem
 * @param ipCurrentDiskNode Pointer to the current disk node
 * @param ipSourceRod Pointer to the source rod
 * @param ipDestinationRod Pointer to the destination rod
 * @param ipHelperRod Pointer to the helper rod
 *
 * @note This function is a recursive function that solves the Tower of Hanoi problem.
 */
void TowerOfHanoi(DiskNode* ipCurrentDiskNode, DiskStack* ipSourceRod, DiskStack* ipDestinationRod, DiskStack* ipHelperRod)
{
    if ((nullptr == ipCurrentDiskNode) || (nullptr == ipSourceRod) || (nullptr == ipDestinationRod) || (nullptr == ipHelperRod))
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    DiskNode* pDiskNode = ipCurrentDiskNode->GetPreviousDiskNode();

    if (nullptr == pDiskNode)
    {
        ipDestinationRod->PushToStack(ipSourceRod->PopFromStack());

        PrintStacks();
    }
    else
    {
        TowerOfHanoi(pDiskNode, ipSourceRod, ipHelperRod, ipDestinationRod);

        ipDestinationRod->PushToStack(ipSourceRod->PopFromStack());

        PrintStacks();

        TowerOfHanoi(pDiskNode, ipHelperRod, ipDestinationRod, ipSourceRod);
    }
}

//-------------------------------------------------------------------
/**
 * @brief Function to delete the stack and its all nodes
 * @param ipStack Pointer to the stack to be deleted
 */
void DeleteStack(DiskStack*& ipStack)
{
    if (nullptr != ipStack)
    {
        DiskNode* pDiskNode = ipStack->PopFromStack();

        while (nullptr != pDiskNode)
        {
            delete pDiskNode;

            pDiskNode = ipStack->PopFromStack();
        }

        delete ipStack;
        ipStack = nullptr;
    }
}

//-------------------------------------------------------------------
/**
 * @brief Main function to solve the Tower of Hanoi problem
 */
int main()
{
    // Number of disks
    // ---------------
    int nbDisks = 0;

    std::cout << "Tower of Hanoi" << std::endl;
    std::cout << "Enter number of disks: ";
    std::cin >> nbDisks;

    // Create three stacks for the three rods
    // DiskStack A is the source rod,
    // DiskStack B is the helper rod, and
    // DiskStack C is the destination rod
    // --------------------------------------
    pStackA = new DiskStack();
    pStackB = new DiskStack();
    pStackC = new DiskStack();

    if ((nullptr == pStackA) || (nullptr == pStackB) || (nullptr == pStackC))
    {
        std::cout << "Memory allocation failed" << std::endl;

        DeleteStack(pStackA);
        DeleteStack(pStackB);
        DeleteStack(pStackC);

        return -1;
    }

    DiskNode* pDiskNode = nullptr;
    DiskNode* pFirstDiskNode = nullptr;

    // Push the disks onto the source rod
    // ----------------------------------
    for (int nDiskIndex = nbDisks; nDiskIndex > 0; --nDiskIndex)
    {
        pDiskNode = new DiskNode(nDiskIndex);

        if (nullptr == pDiskNode)
        {
            std::cout << "Memory allocation failed" << std::endl;

            DeleteStack(pStackA);
            DeleteStack(pStackB);
            DeleteStack(pStackC);

            return -1;
        }

        if (nullptr == pFirstDiskNode)
            pFirstDiskNode = pDiskNode;

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

    PrintStacks();

    TowerOfHanoi(pFirstDiskNode, pStackA, pStackC, pStackB);

    DeleteStack(pStackA);
    DeleteStack(pStackB);
    DeleteStack(pStackC);

    return 0;
}