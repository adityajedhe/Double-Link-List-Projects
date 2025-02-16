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
 * @brief Represents a node, encapsulating a data element and
 * pointers to two nodes.
 */
class Node
{
public:
    /**
     * @brief Constructor for Node
     * @param[in] inData Data element to store in the node
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
     * @brief Retrieves the left node
     * It is a constant member function, meaning it does not modify any member variables.
     *
     * @return Pointer to the left node
     */
    Node *GetLeftNode() const;

    /**
     * @brief Retrieves the right node
     * It is a constant member function, meaning it does not modify any member variables.
     *
     * @return Pointer to the right node
     */
    Node *GetRightNode() const;

    /**
     * @brief Sets the left node
     * @param[in] ipLeftNode Pointer to the left node
     */
    void SetLeftNode(Node *ipLeftNode);

    /**
     * @brief Sets the right node
     * @param[in] ipRightNode Pointer to the right node
     */
    void SetRightNode(Node *ipRightNode);

private:
    /**
     * ----------------
     * Member variables
     * ----------------
     */

    /**
     * @brief Data element stored in the node
     */
    int _nData;

    /**
     * @brief Pointer to the left node
     */
    Node *_pLeftNode;

    /**
     * @brief Pointer to the right node
     */
    Node *_pRightNode;
};

#endif // _NODE_H_
