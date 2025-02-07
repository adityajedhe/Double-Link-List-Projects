//===================================================================
// Name         : BinaryTreeNode.h
// Description  : Header file for the BinaryTreeNode class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/05
//===================================================================

#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_


//-------------------------------------------------------------------
/**
 * @class BinaryTreeNode
 * @brief Represents a node in a binary tree,
 * encapsulating a data element and pointers to child nodes.
 *
 * The BinaryTreeNode class is used to model the nodes in a binary tree.
 * Each node contains a data element and pointers to the left and right child nodes.
 *
 * @fn BinaryTreeNode::BinaryTreeNode(const int inData)
 * @brief Constructor for BinaryTreeNode
 * @param inData Data element to store in the node
 *
 * @fn BinaryTreeNode::~BinaryTreeNode()
 * @brief Destructor for BinaryTreeNode
 *
 * @fn int BinaryTreeNode::GetData() const
 * @brief Retrieves the data element stored in the node
 * @return Data element stored in the node
 *
 * @fn BinaryTreeNode* BinaryTreeNode::GetLeftChild() const
 * @brief Retrieves the left child node
 * @return Pointer to the left child node
 *
 * @fn BinaryTreeNode* BinaryTreeNode::GetRightChild() const
 * @brief Retrieves the right child node
 * @return Pointer to the right child node
 *
 * @fn void BinaryTreeNode::SetLeftChild(BinaryTreeNode* ipLeftChild)
 * @brief Sets the left child node
 * @param ipLeftChild Pointer to the left child node
 *
 * @fn void BinaryTreeNode::SetRightChild(BinaryTreeNode* ipRightChild)
 * @brief Sets the right child node
 * @param ipRightChild Pointer to the right child node
 *
 */
class BinaryTreeNode
{
public:

    /**
     * @brief Constructor for BinaryTreeNode
     * @param inData Data element to store in the node
     */
    BinaryTreeNode(const int inData = 0);

    virtual ~BinaryTreeNode();

    /**
     * @brief Retrieves the data element stored in the node
     * It is a constant member function, meaning it does not modify any member variables.
     *
     * @return Data element stored in the node
     */
    int GetData() const;

    /**
     * @brief Retrieves the left child node
     * It is a constant member function, meaning it does not modify any member variables.
     *
     * @return Pointer to the left child node
     */
    BinaryTreeNode* GetLeftChild() const;

    /**
     * @brief Retrieves the right child node
     * It is a constant member function, meaning it does not modify any member variables.
     *
     * @return Pointer to the right child node
     */
    BinaryTreeNode* GetRightChild() const;

    /**
     * @brief Sets the left child node
     * @param ipLeftChild Pointer to the left child node
     */
    void SetLeftChild(BinaryTreeNode* ipLeftChild);

    /**
     * @brief Sets the right child node
     * @param ipRightChild Pointer to the right child node
     */
    void SetRightChild(BinaryTreeNode* ipRightChild);


private:

    //---------------------------------------------------------------
    // Member variables
    //---------------------------------------------------------------
    /**
     * @brief Data element stored in the node
     */
    int _nData;

    /**
     * @brief Pointer to the left child node
     */
    BinaryTreeNode* _pLeftChild;

    /**
     * @brief Pointer to the right child node of the binary tree.
     */
    BinaryTreeNode* _pRightChild;

};

#endif // _BINARYTREENODE_H_
