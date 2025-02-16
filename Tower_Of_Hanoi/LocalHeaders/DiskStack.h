//===================================================================
// Name         : DiskStack.h
// Description  : Header file for the DiskStack class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/01/30
//===================================================================

#ifndef _DISKSTACK_H_
#define _DISKSTACK_H_

// ---------------------------------------------- Forward declaration
class Node;

//------------------------------------------------------------------------
/**
 * @class DiskStack
 * @brief Represents a stack of disks in the Tower of Hanoi game.
 *
 * The DiskStack class is used to model the stacks of disks in the Tower of Hanoi game. Each stack contains a
 * linked list of disks, with the top disk being the most recently added disk.
 *
 * @note This class manages memory for the disk nodes. All the disk nodes are deleted when stack is deleted.
 * It is the responsibility of the user to ensure that the disk nodes
 * remain valid for the lifetime of the DiskStack instance.
 */
class DiskStack
{
public:
    /**
     * @brief Constructor for DiskStack
     */
    DiskStack();

    /**
     * @brief Destructor for DiskStack
     * @note Deletes all the nodes which are stacked onto the disk.
     */
    virtual ~DiskStack();

    /**
     * @brief Pushes a disk node onto the stack.
     * @param ipNode Pointer to the disk node to be pushed onto the stack.
     */
    void PushToStack(Node *ipNode);

    /**
     * @brief Pops the top disk node from the stack.
     * @return Pointer to the disk node that was popped from the stack.
     *         Returns nullptr if the stack is empty.
     */
    Node *PopFromStack();

    /**
     * @brief Checks if the stack is empty.
     * @return Returns True if the stack is empty, false otherwise.
     */
    bool IsStackEmpty() const;

    /**
     * @brief Prints the contents of the stack.
     */
    void PrintStack() const;

    /**
     *  @brief Returns the top disk node from the stack.
     * @return Pointer to the top disk node in the stack.
     */
    Node *GetTopDisk() const;

private:
    /**
     *  @brief Pointer to the top disk in the stack.
     */
    Node *_pTopDisk;
};

#endif // _DISKSTACK_H_
