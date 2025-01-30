//===================================================================
// Class: DiskStack
//===================================================================

#ifndef _DISKSTACK_H_
#define _DISKSTACK_H_


class DiskNode;

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
 * @author Aditya Jedhe
 * @date   2025/01/30
 */
class DiskStack
{
public:

    /**
     *  @brief Constructor for DiskStack
     */
    DiskStack();

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
