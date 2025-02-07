//===================================================================
// Class: BinaryTreeNode
// @author Aditya Jedhe
// @date   2025/01/30
//===================================================================

#ifndef _DISKNODE_H_
#define _DISKNODE_H_

//------------------------------------------------------------------------
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
 */
class DiskNode
{
public:

    /**
     * @brief Constructor for DiskNode
     * @param inDiskNumber Disk number
     */
    DiskNode(const int inDiskNumber = 0);

    /**
     * @brief Destructor for DiskNode
     */
    virtual ~DiskNode();

    /**
     * @brief This identifies the disk number
     * @return Disk number
     */
    int GetDiskNumber() const;

    /**
     * @brief Returns the previous disk node
     * @return Previous disk node
     */
    DiskNode* GetPreviousDiskNode() const;

    /**
     * @brief Retrieves the next DiskNode in the sequence.
     * @return DiskNode* Pointer to the next DiskNode.
     */
    DiskNode* GetNextDiskNode() const;

    /**
     * @brief Sets the next disk node in the sequence.
     * @param ipPreviousDiskNode Pointer to the previous disk node in the sequence.
     */
    void SetPreviousDiskNode(DiskNode* ipPreviousDiskNode);

    /**
     * @brief Sets the next disk node in the sequence.
     * @param ipNextDiskNode Pointer to the next disk node in the sequence.
     */
    void SetNextDiskNode(DiskNode* ipNextDiskNode);


private:

    /**
     * @brief Represents the disk number in the Tower of Hanoi game.
     */
    int _nDiskNumber;

    /**
     * @brief Pointer to the previous disk node in the Tower of Hanoi structure.
     */
    DiskNode* _pPreviousDiskNode;

    /**
     * @brief Pointer to the next DiskNode in the sequence.
     */
    DiskNode* _pNextDiskNode;

};

#endif // _DISKNODE_H_
