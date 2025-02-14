//===================================================================
// Name         : BinaryTree.h
// Description  : Header file for the BinaryTree class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/06
//===================================================================

// ---------------------------------------------- STL Headers
#include <stack>

// ---------------------------------------------- Forward declaration
class Node;

//-------------------------------------------------------------------
/**
 * @class BinaryTree
 * @brief A class representing a binary tree data structure.
 *
 * This class provides functionalities to insert, delete, and search for data elements
 * in a binary tree. It also includes various traversal methods and functions to print
 * specific nodes or levels of the tree.
 *
 * @note The binary tree is represented by a root node, which is the topmost node in the tree.
 *
 * @fn BinaryTree::BinaryTree()
 * @brief Constructor for BinaryTree
 *
 * @fn BinaryTree::~BinaryTree()
 * @brief Destructor for BinaryTree
 *
 * @fn void BinaryTree::InsertInBinaryTree(int inData)
 * @brief Inserts a new value into the complete binary tree
 * @param inData The integer value to be inserted into the binary tree.
 *
 * @fn void BinaryTree::InsertInBinarySearchTree(int inData)
 * @brief Inserts a new data element into the binary search tree
 * @param inData Data element to insert
 *
 * @fn void BinaryTree::Delete(int inData)
 * @brief Deletes a data element from the binary tree
 * @param inData Data element to delete
 *
 * @fn void BinaryTree::InOrderTraversal()
 * @brief Performs an in-order traversal of the binary tree
 *
 * @fn void BinaryTree::PreOrderTraversal()
 * @brief Performs a pre-order traversal of the binary tree
 *
 * @fn void BinaryTree::PostOrderTraversal()
 * @brief Performs a post-order traversal of the binary tree
 *
 * @fn void BinaryTree::LevelOrderTraversal()
 * @brief Performs a level-order traversal of the binary tree
 *
 * @fn void BinaryTree::ReverseLevelOrderTraversal()
 * @brief Performs a reverse level-order traversal of the binary tree
 *
 * @fn void BinaryTree::SpiralOrderTraversal()
 * @brief Performs a spiral order traversal of the binary tree
 *
 * @fn void BinaryTree::PrintLeafNodes()
 * @brief Prints all leaf nodes of the binary tree
 *
 * @fn void BinaryTree::PrintNonLeafNodes()
 * @brief Prints all non-leaf nodes of the binary tree
 *
 * @fn void BinaryTree::PrintAllNodesAtKDistance(int k)
 * @brief Prints all nodes at a distance k from the root node
 * @param k Distance from the root node
 *
 * @fn int BinaryTree::FindDistanceFromRootNode(int inData)
 * @brief Finds the distanc of a node with the given data element from the root node
 * @param inData Data element to find
 *
 * @fn void BinaryTree::PrintAncestor(int inData)
 * @brief Prints all ancestor nodes of a given data element
 * @param inData Data element whose ancestors are to be printed
 *
 * @fn void BinaryTree::PrintAncestors(int inData)
 * @brief Prints all ancestor nodes of a given data element
 * @param inData Data element whose ancestors are to be printed
 *
 * @fn void BinaryTree::PrintCousins(int inData)
 * @brief Prints all cousin nodes of a given data element
 * @param inData Data element whose cousins are to be printed
 *
 * @fn void BinaryTree::PrintSibling(int inData)
 * @brief Prints all sibling nodes of a given data element
 * @param inData Data element whose siblings are to be printed
 */
class BinaryTree
{
public:
    /**
     * @brief Constructor for BinaryTree
     */
    BinaryTree();

    /**
     * @brief Destructor for BinaryTree
     */
    virtual ~BinaryTree();

    /**
     * @brief Removes all children of a given node
     * @param ipParentNode Parent node whose children are to be removed
     * @return True if the children are removed, false otherwise
     */
    void RemoveChildren(Node *ipParentNode);

    /**
     * @brief Checks if the binary tree is empty
     * @return True if the binary tree is empty, false otherwise
     */
    bool IsEmpty();

    /**
     * @brief Inserts a new value into the binary tree while maintaining
     *        the properties of a complete binary tree.
     *
     * This function inserts a new value into the binary tree while maintaining the properties of a complete binary tree.
     * It inserts the node at each level.
     * Once the level is full, the node is inserted at the next level.
     *
     * @param inData The integer value to be inserted into the binary tree.
     */
    void InsertInBinaryTree(int inData);

    /**
     * @brief Inserts a new data element into the binary search tree
     *
     * The binary search tree is a data structure in which each node has at
     * most two children, referred to as the left child and the right
     * child. Also no two nodes have the same data element. The left child
     * of a node has a value less than the parent node, and the right child
     * has a value greater than the parent node.
     *
     * @param inData Data element to insert
     */
    void InsertInBinarySearchTree(int inData);

    /**
     * @brief Deletes a data element from the binary tree
     * @param inData Data element to delete
     */
    void Delete(int inData);

    /**
     * @brief Returns the height of the binary tree
     *
     * The height of a binary tree is the number of edges on the longest path between the root node and a leaf node.
     *
     * @return Height of the binary tree
     */
    int HeightOfBinaryTree();

    /**
     * @brief Performs an in-order traversal of the binary tree
     *
     * Prints all elements in the binary tree in in-order sequence.
     *
     */
    void InOrderTraversal();

    /**
     * @brief Performs an pre-order traversal of the binary tree
     *
     * Prints all elements in the binary tree in pre-order sequence.
     *
     */
    void PreOrderTraversal();

    /**
     * @brief Performs a post-order traversal of the binary tree
     *
     * Prints all elements in the binary tree in post-order sequence.
     *
     */
    void PostOrderTraversal();

    /**
     * @brief Performs a level-order traversal of the binary tree
     *
     * Prints all elements in the binary tree in level-order sequence.
     *
     */
    void LevelOrderTraversal();

    /**
     * @brief Performs a reverse level-order traversal of the binary tree
     *
     * Prints all elements in the binary tree in level-order sequence in reverse manner.
     *
     */
    void ReverseLevelOrderTraversal();

    /**
     * @brief Performs a spiral order traversal of the binary tree
     *
     * Prints all elements in the binary tree in spiral order sequence.
     *
     */
    void SpiralOrderTraversal();

    /**
     * @brief Prints all leaf nodes of the binary tree
     */
    void PrintLeafNodes();

    /**
     * @brief Prints all non-leaf nodes of the binary tree
     */
    void PrintNonLeafNodes();

    /**
     * @brief Prints all nodes at a distance k from the root node
     * @param inKDistance Distance from the root node
     */
    void PrintAllNodesAtKDistance(int inKDistance);

    /**
     * @brief Finds the distance of node with the given data element from the root node
     * @param inData Data element to find
     * @return Distance from the given node, if found. Otherwise -1
     */
    int FindDistanceFromRootNode(int inData);

    /**
     * @brief Prints immidiate ancestor node of a given data element
     * @param inData Data element whose ancestor is to be printed
     */
    void PrintAncestor(int inData);

    /**
     * @brief Prints all ancestor nodes of a given data element
     * @param inData Data element whose ancestors are to be printed
     */
    void PrintAncestors(int inData);

    /**
     * @brief Prints all cousin nodes of a given data element
     * @param inData Data element whose cousins are to be printed
     */
    void PrintCousins(int inData);

    /**
     * @brief Prints all sibling nodes of a given data element
     * @param inData Data element whose siblings are to be printed
     */
    void PrintSibling(int inData);

private:
    /**
     * @brief Inserts a new node into a binary tree.
     *
     * This function inserts the specified new node into the binary tree at the appropriate
     * position based on the binary search tree properties.
     *
     * @param[in] ipNode Pointer to the current node in the binary tree where the new node
     *                   will be inserted. If this is null, the new node will become the root.
     * @param[in] ipNewNode Pointer to the new node that needs to be inserted into the tree.
     *
     * @see DeleteNodeInBinaryTree() for removing a node from the binary tree.
     */
    bool InsertNodeInBinaryTree(Node *ipNode, Node *ipNewNode);
    /**
     * @brief Returns the height of sub binary tree having root node as given node
     *
     * The height of a given binary tree node is the number of edges on the longest path between the given node and a leaf node.
     *
     * @param ipNode Node whose height is to be calculated
     * @return Height of the binary tree
     */
    int HeightOfSubBinaryTree(Node *ipNode);

    /**
     * @brief Performs an in-order traversal of the binary tree node
     *
     * Prints all elements under the binary tree node in in-order sequence.
     *
     * @param ipNode Node to traverse
     */
    void InOrderTraversalOfBinaryTreeNode(Node *ipNode);

    /**
     * @brief Performs an pre-order traversal of the binary tree node
     *
     * Prints all elements under the binary tree node in pre-order sequence.
     *
     * @param ipNode Node to traverse
     */
    void PreOrderTraversalOfBinaryTreeNode(Node *ipNode);

    /**
     * @brief Performs an post-order traversal of the binary tree node
     *
     * Prints all elements under the binary tree node in post-order sequence.
     *
     * @param ipNode Node to traverse
     */
    void PostOrderTraversalOfBinaryTreeNode(Node *ipNode);

    /**
     * @brief Prints all leaf nodes of sub binary tree having root node as given node
     * @param ipNode Node to traverse
     */
    void PrintLeafNodes(Node *ipNode);

    /**
     * @brief Prints all non-leaf nodes of sub binary tree having root node as given node
     * @param ipNode Node to traverse
     */
    void PrintNonLeafNodes(Node *ipNode);

    /**
     * @brief Prints all nodes at a distance k from the root node
     * @param ipNode Node to traverse
     * @param inKDistance Distance from the root node
     */
    void PrintAllNodesAtKDistance(Node *ipNode, int inKDistance);

    /**
     * @brief Finds the node with the given data element
     * @param ipNode Node to traverse
     * @param inData Data element to find
     * @param iosNodePath Stack to store the path of the node
     * @return Distance from the given node, if found. Otherwise -1
     */
    int FindDistanceFromNode(Node *ipNode, int inData, std::stack<int> &iosNodePath);

    /**
     * @brief Prints all ancestor nodes of a given data element
     * @param ipNode Node to traverse
     * @param inData Data element whose ancestors are to be printed
     * @return True if ancestor is found, false otherwise
     */
    bool PrintAncestor(Node *ipNode, int inData);

    /**
     * @brief Prints all ancestor nodes of a given data element by traversing the path and printing the nodes
     * @param ipNode Node to traverse
     * @param iosNodePath Stack to store the path of the node
     */
    void PrintAncestors(Node *ipNode, std::stack<int> &iosNodePath);

    /**
     * @brief Prints all cousin nodes of a given data element
     * @param ipNode Node to traverse
     * @param inData Data element whose cousins are to be printed
     * @param inNodeHeight Height of the node
     */
    void PrintCousins(Node *ipNode, int inData, int inNodeHeight);

    /**
     * @brief Prints sibling node of a given data element
     * @param ipNode Node to traverse
     * @param inData Data element whose cousins are to be printed
     * @return True if sibling is found, false otherwise
     */
    bool PrintSibling(Node *ipNode, int inData);

    //---------------------------------------------------------------
    // Member variables
    //---------------------------------------------------------------
    /**
     * @brief Represents the root node of the binary tree
     *
     * The root node is the starting point of the tree.
     * It is the topmost node in the tree.
     */
    Node *_pRootNode;
};
