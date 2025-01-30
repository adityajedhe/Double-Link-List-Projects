
#ifndef _DISKNODE_H_
#define _DISKNODE_H_

/**
 * @class DiskNode
 * @brief Represents a node in the Tower of Hanoi game, encapsulating a disk and its relationship to other disks.
 *
 * The DiskNode class is used to model the disks in the Tower of Hanoi game. Each node contains a disk number
 * and a pointer to the previous disk node, allowing the construction of a linked list of disks.
 *
 * @note This class does not manage memory for the previous disk node. It is the responsibility of the user
 * to ensure that the previous disk node remains valid for the lifetime of the DiskNode instance.
 *
 * @author Aditya Jedhe
 * @date   2025/01/30
 */
class DiskNode
{
public:

    /**
     * @brief Constructor for DiskNode
     * @param inDiskNumber Disk number
     * @param ipPreviousDiskNode Pointer to the previous disk node
     */
    DiskNode(const int inDiskNumber = 0, DiskNode* ipPreviousDiskNode = nullptr);

    /**
     * @brief This identifies the disk number
     * @return Disk number
     */
    int GetDiskNumber() const;

    /**
     * @brief Retrieves the next DiskNode in the sequence.
     *
     * This function returns a pointer to the next DiskNode in the sequence.
     * It is a constant member function, meaning it does not modify any member variables.
     *
     * @return DiskNode* Pointer to the next DiskNode.
     */
    DiskNode* GetNextDiskNode() const;

    /**
     * @brief Returns the previous disk node
     * @return Previous disk node
     */
    DiskNode* GetPreviousDiskNode() const;

    void SetNextDiskNode(DiskNode* ipNextDiskNode);


private:

    /**
     * @brief Represents the disk number in the Tower of Hanoi game.
     * This variable is used to identify and differentiate between different disks.
     */
    int _nDiskNumber;

    /**
     * @brief Pointer to the next DiskNode in the sequence.
     */
    DiskNode* _pNextDiskNode;

    /**
     * @brief Pointer to the previous disk node in the Tower of Hanoi structure.
     */
    DiskNode* _pPreviousDiskNode;

};

#endif // _DISKNODE_H_
