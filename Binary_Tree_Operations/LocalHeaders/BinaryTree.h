//===================================================================
// Name         : BinaryTree.h
// Description  : Header file for the BinaryTree class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/06
//===================================================================

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
 * @fn void BinaryTree::PrintAncestors(int inData)
 * @brief Prints all ancestor nodes of a given data element
 * @param inData Data element whose ancestors are to be printed
 *
 * @fn void BinaryTree::PrintCousins(int inData)
 * @brief Prints all cousin nodes of a given data element
 * @param inData Data element whose cousins are to be printed
 *
 * @fn void BinaryTree::PrintSiblings(int inData)
 * @brief Prints all sibling nodes of a given data element
 * @param inData Data element whose siblings are to be printed
 *
 * @fn void BinaryTree::PrintLevel(int inData)
 * @brief Prints the level of a given data element in the binary tree
 * @param inData Data element whose level is to be printed
 *
 * @fn void BinaryTree::PrintLevelOrderTraversal()
 * @brief Prints the level-order traversal of the binary tree
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
     * @param pParentNode Parent node whose children are to be removed
     * @return True if the children are removed, false otherwise
     */
    void RemoveChildren(Node* pParentNode);

    /**
     * @brief Checks if the binary tree is empty
     * @return True if the binary tree is empty, false otherwise
     */
    bool IsEmpty();

    /**
     * @brief Inserts a new data element into the binary search tree
     *
     * The binary search tree is a data structure in which each node has at most two children, referred to as the left child and the right child. Also no two nodes have the same data element. The left child of a node has a value less than the parent node, and the right child has a value greater than the parent node.
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
     * Prints all elements in the binary tree in reverse level-order sequence.
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
     * @param k Distance from the root node
     */
    void PrintAllNodesAtKDistance(int k);

    void PrintAncestors(int inData);

    void PrintCousins(int inData);

    void PrintSiblings(int inData);

    void PrintLevel(int inData);

    void PrintLevelOrderTraversal();


private:

    /**
     * @brief Returns the height of the given binary tree node
     *
     * The height of a given binary tree node is the number of edges on the longest path between the given node and a leaf node.
     *
     * @param pNode Node whose height is to be calculated
     * @return Height of the binary tree
     */
    int HeightOfBinaryTreeNode(Node* pNode);

    /**
     * @brief Performs an in-order traversal of the binary tree node
     *
     * Prints all elements under the binary tree node in in-order sequence.
     *
     * @param pNode Node to traverse
     */
    void InOrderTraversalOfBinaryTreeNode(Node* pNode);

    /**
     * @brief Performs an pre-order traversal of the binary tree node
     *
     * Prints all elements under the binary tree node in pre-order sequence.
     *
     * @param pNode Node to traverse
     */
    void PreOrderTraversalOfBinaryTreeNode(Node* pNode);

    /**
     * @brief Performs an post-order traversal of the binary tree node
     *
     * Prints all elements under the binary tree node in post-order sequence.
     *
     * @param pNode Node to traverse
     */
    void PostOrderTraversalOfBinaryTreeNode(Node* pNode);


    //---------------------------------------------------------------
    // Member variables
    //---------------------------------------------------------------
    /**
     * @brief Represents the root node of the binary tree
     * The root node is the starting point of the tree.
     * It is the topmost node in the tree.
     */
    Node* _pRootNode;

};
