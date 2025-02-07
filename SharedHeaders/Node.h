//===================================================================
// Name         : Node.h
// Description  : Header file for the Node class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/05
//===================================================================

#ifndef _NODE_H_
#define _NODE_H_


//-------------------------------------------------------------------
/**
 * @class Node
 * @brief Represents a node, encapsulating a data element and two
 * pointers to child nodes.
 *
 * @fn Node::Node(const int inData)
 * @brief Constructor for Node
 * @param inData Data element to store in the node
 *
 * @fn Node::~Node()
 * @brief Destructor for Node
 *
 * @fn int Node::GetData() const
 * @brief Retrieves the data element stored in the node
 * @return Data element stored in the node
 *
 * @fn Node* Node::GetLeftChild() const
 * @brief Retrieves the left child node
 * @return Pointer to the left child node
 *
 * @fn Node* Node::GetRightChild() const
 * @brief Retrieves the right child node
 * @return Pointer to the right child node
 *
 * @fn void Node::SetLeftChild(Node* ipLeftChild)
 * @brief Sets the left child node
 * @param ipLeftChild Pointer to the left child node
 *
 * @fn void Node::SetRightChild(Node* ipRightChild)
 * @brief Sets the right child node
 * @param ipRightChild Pointer to the right child node
 *
 */
class Node
{
public:

    /**
     * @brief Constructor for Node
     * @param inData Data element to store in the node
     */
    Node(const int inData = 0);

    virtual ~Node();

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
    Node* GetLeftChild() const;

    /**
     * @brief Retrieves the right child node
     * It is a constant member function, meaning it does not modify any member variables.
     *
     * @return Pointer to the right child node
     */
    Node* GetRightChild() const;

    /**
     * @brief Sets the left child node
     * @param ipLeftChild Pointer to the left child node
     */
    void SetLeftChild(Node* ipLeftChild);

    /**
     * @brief Sets the right child node
     * @param ipRightChild Pointer to the right child node
     */
    void SetRightChild(Node* ipRightChild);


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
    Node* _pLeftChild;

    /**
     * @brief Pointer to the right child node
     */
    Node* _pRightChild;

};

#endif // _NODE_H_
