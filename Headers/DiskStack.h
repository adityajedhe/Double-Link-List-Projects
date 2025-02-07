//===================================================================
// Name         : DiskStack.h
// Description  : Header file for the DiskStack class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/01/30
//===================================================================

#ifndef _DISKSTACK_H_
#define _DISKSTACK_H_

// Forward declaration
// -------------------
class DiskNode;

//------------------------------------------------------------------------
/**
 * @class DiskStack
 * @brief Represents a stack of disks in the Tower of Hanoi game.
 *
 * The DiskStack class is used to model the stacks of disks in the Tower of Hanoi game. Each stack contains a
 * linked list of disks, with the top disk being the most recently added disk.
 *
 * @note This class does not manage memory for the disk nodes. It is the responsibility of the user to ensure
 * that the disk nodes remain valid for the lifetime of the DiskStack instance.
 *
 * @fn DiskStack::DiskStack()
 * @brief Constructor for DiskStack
 *
 * @fn DiskStack::~DiskStack()
 * @brief Destructor for DiskStack
 *
 * @fn void DiskStack::PushToStack(DiskNode* ipDiskNode)
 * @brief Pushes a disk node onto the stack.
 * @param ipDiskNode Pointer to the disk node to be pushed onto the stack.
 *
 * @fn DiskNode* DiskStack::PopFromStack()
 * @brief Pops the top disk node from the stack.
 *
 * @fn void DiskStack::PrintStack()
 * @brief Prints the contents of the stack.
 *
 * @fn DiskNode* DiskStack::GetTopDisk() const
 * @brief Returns the top disk node from the stack.
 *
 */
class DiskStack
{
public:

    /**
     *  @brief Constructor for DiskStack
     */
    DiskStack();

    /**
     *  @brief Destructor for DiskStack
     */
    virtual ~DiskStack();

    /**
     * @brief Pushes a disk node onto the stack.
     * @param ipDiskNode Pointer to the disk node to be pushed onto the stack.
     */
    void PushToStack(DiskNode* ipDiskNode);

    /**
     * @brief Pops the top disk node from the stack.
     * @return Pointer to the disk node that was popped from the stack.
     */
    DiskNode* PopFromStack();

    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool IsStackEmpty() const;

    /**
     * @brief Prints the contents of the stack.
     */
    void PrintStack();

    /**
     *  @brief Returns the top disk node from the stack.
     * @return Pointer to the top disk node in the stack.
     */
    DiskNode* GetTopDisk() const;


private:

    /**
     *  @brief Pointer to the top disk in the stack.
     */
    DiskNode* _pTopDisk;

};

#endif // _DISKSTACK_H_
