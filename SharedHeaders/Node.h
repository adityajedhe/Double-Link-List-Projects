//-------------------------------------------------------------------
/**
 * @file Node.h
 * @brief Header file for the Node class
 * @author Aditya Jedhe
 * @date 2025-02-05
 */
//-------------------------------------------------------------------

#ifndef _NODE_H_
#define _NODE_H_

/**
 * @class Node
 * @brief Represents a node, encapsulating a data element and pointers to two nodes.
 */
class Node
{
public:
    /**
     * @brief Constructor for Node
     * @param[in] inData Data element to store in the node
     * @note By default, both the pointers to the nodes (left and right) are set to null
     */
    Node(const int inData = 0);

    /**
     * @brief Destructor for Node
     */
    virtual ~Node();

    /**
     * @brief Retrieves the data element stored in the node
     * @return Data element stored in the node
     * @note It is a constant member function.
     */
    int GetData() const;

    /**
     * @brief Retrieves the left node
     * @return Pointer to the left node
     * @note It is a constant member function.
     */
    Node *GetLeftNode() const;

    /**
     * @brief Retrieves the right node
     * @return Pointer to the right node
     * @note It is a constant member function.
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
