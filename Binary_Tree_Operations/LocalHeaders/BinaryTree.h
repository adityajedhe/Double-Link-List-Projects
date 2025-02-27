//-------------------------------------------------------------------
/**
 * @file BinaryTree.h
 * @brief Header file for the BinaryTree class.
 * @author Aditya Jedhe
 * @date 2025-02-06
 */
//-------------------------------------------------------------------

// ---------------------------------------------- System Headers
#include <stack>
#include <vector>

// ---------------------------------------------- Forward declaration
class Node;

//-------------------------------------------------------------------
/**
 * @class BinaryTree
 * @brief A class representing a binary tree data structure.
 * @details This class provides functionalities to insert, delete, and search for data
 * in a binary tree. It also includes various traversal methods and functions to print
 * specific nodes or levels of the tree.
 * @note The binary tree is represented by a root node, which is the topmost node in the tree.
 */
class BinaryTree
{
public:
    /**
     * @brief Creates the binary tree
     * @return Pointer of created binary tree object
     * @see RemoveBinaryTree() for deleting the binary tree
     * @note This method is static method
     */
    static BinaryTree *CreateBinaryTree();

    /**
     * @brief Deletes the binary tree
     * @param[in, out] iopBinaryTree created binary tree object
     * @note This method is static method
     */
    static void RemoveBinaryTree(BinaryTree *&iopBinaryTree);

    /**
     * @brief Checks if the binary tree is empty
     * @return True if the binary tree is empty, false otherwise
     */
    bool IsEmpty();

    /**
     * @brief Inserts a new node into a binary tree.
     * @details This function inserts a new value into the binary tree while maintaining the properties of a complete binary tree. It inserts the node at each level.
     * Once the level is full, the node is inserted at the next level.
     * @param[in] inData The integer value to be inserted into the binary tree.
     * @see DeleteBinaryTreeNode() for removing a node from the binary tree.
     */
    void InsertNodeInBinaryTree(int inData);

    /**
     * @brief Inserts a new data into the binary search tree
     * @details The binary search tree is a data structure in which each node has at
     * most two children, referred to as the left child and the right
     * child. Also no two nodes have the same data. The left child
     * of a node has a value less than the parent node, and the right child
     * has a value greater than the parent node.
     * @param[in] inData Data to insert
     */
    void InsertNodeInBinarySearchTree(int inData);

    /**
     * @brief Deletes a data from the binary tree
     * @param[in] inData Data to delete
     * @warning not implemented
     */
    void DeleteBinaryTreeNode(int inData);

    /**
     * @brief Searches for the node with the given data from the root node
     * @param[in] inData Data to search for
     * @return Distance from the given node, if found. Otherwise -1
     */
    bool SearchInBinaryTree(int inData);

    /**
     * @brief Performs an pre-order traversal of the binary tree
     * @details Prints all nodes in the binary tree in pre-order sequence.
     */
    void PreOrderTraversal();

    /**
     * @brief Performs and in-order traversal of the binary tree
     * @details Prints all nodes in the binary tree in in-order sequence.
     */
    void InOrderTraversal();

    /**
     * @brief Performs a post-order traversal of the binary tree
     * @details Prints all nodes in the binary tree in post-order sequence.
     */
    void PostOrderTraversal();

    /**
     * @brief Performs a level-order traversal of the binary tree
     * @details Prints all nodes in the binary tree in level-order sequence.
     */
    void LevelOrderTraversal();

    /**
     * @brief Performs a reverse level-order traversal of the binary tree
     * @details Prints all nodes in the binary tree in level-order sequence in reverse manner.
     */
    void ReverseLevelOrderTraversal();

    /**
     * @brief Performs a spiral order traversal of the binary tree
     * @details Prints all nodes in the binary tree in spiral order sequence.
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
     * @brief Prints all boundary nodes of binary tree
     */
    void PrintBoundaryNodes();

    /**
     * @brief Prints all nodes of binary tree which are having 0 or 2 children
     */
    void PrintAllFullNodes();

    /**
     * @brief Prints all nodes of binary tree which are having only one child
     */
    void PrintAllHalfNodes();

    /**
     * @brief Prints all nodes at a distance k from the root node
     * @param[in] inKDistance Distance from the root node
     */
    void PrintAllNodesAtKDistance(int inKDistance);

    /**
     * @brief Prints all sibling nodes of a given data
     * @param[in] inData Data of a node whose siblings are to be printed
     */
    void PrintSibling(int inData);

    /**
     * @brief Prints all cousin nodes of a given data
     * @param[in] inData Data of a node whose cousins are to be printed
     */
    void PrintCousins(int inData);

    /**
     * @brief Prints all ancestor nodes of a given data
     * @param[in] inData Data of a node whose ancestors are to be printed
     */
    void PrintAncestors(int inData);

    /**
     * @brief Prints all decendant nodes of a given data
     * @param[in] inData Data of a node whose ancestors are to be printed
     */
    void PrintDecendants(int inData);

    /**
     * @brief Prints immidiate ancestor node of a given data
     * @param[in] inData Data of a node whose ancestor is to be printed
     */
    void PrintAncestor(int inData);

    /**
     * @brief Returns the height of the binary tree
     * @details The height of a binary tree is the number of edges on the longest path between the root node and a leaf node.
     * @return Height of the binary tree
     */
    int HeightOfBinaryTree();

    /**
     * @brief Returns the level of node in the binary tree
     * @details Level of the node in binary tree is the number of nodes required to traverse from root node
     * @return Level of node in binary tree
     * @warning not implemented
     */
    int FindLevelOfNode(int inData);

private:
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
     * @param[in] ipParentNode Parent node whose children are to be removed
     */
    void RemoveChildren(Node *ipParentNode);

    /**
     * @brief Finds the node with the given data
     * @param[in] ipNode Node to traverse
     * @param[in] inData Data to be searchedin the binary tree
     * @param[in, out] iodqNodes Dequeue to store all the nodes while traversing to the node
     * @return Pointer of node. Otherwise nullptr.
     */
    Node *SearchInBinaryTree(Node *ipNode, int inData, std::deque<Node *> &iodqNodes);

    /**
     * @brief Performs an pre-order traversal of the binary tree node
     * @details Sub-binary tree is traversed in in-order sequence and the nodes are added to the vector.
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void PreOrderTraversalOfBinaryTreeNode(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Performs an in-order traversal of the binary tree node
     * @details Sub-binary tree is traversed in in-order sequence and the nodes are added to the vector.
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void InOrderTraversalOfBinaryTreeNode(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Performs an post-order traversal of the binary tree node
     * @details Sub-binary tree is traversed in post-order sequence and the nodes are added to the vector.
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void PostOrderTraversalOfBinaryTreeNode(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Performs a level-order traversal of the binary tree
     * @details Each level of sub-binary tree is traversed in level-order sequence and the nodes are added to the vector.
     * @param[in] ipRootNode Root node of the binary tree
     * @param[out] ovNodes Vector containing list of pointers of ouput nodes
     */
    void LevelOrderTraversalOfBinaryTreeNode(Node *ipRootNode, std::vector<Node *> &ovNodes);

    /**
     * @brief Performs a reverse level-order traversal of the binary tree
     * @details Each level of sub-binary tree is traversed in reverse level-order sequence and the nodes are added to the vector.
     * @param[in] ipRootNode Root node of the binary tree
     * @param[out] odqNodes Dequeue containing list of pointers of ouput nodes
     */
    void ReverseLevelOrderTraversalOfBinaryTreeNode(Node *ipRootNode, std::deque<Node *> &odqNodes);

    /**
     * @brief Performs a level-order traversal of the binary tree in spiral manner.
     * @details Each level of sub-binary tree is traversed in spiral level-order sequence and the nodes are added to the vector.
     * @param[in] ipRootNode Root node of the binary tree
     * @param[out] ovNodes Vector containing list of pointers of ouput nodes
     */
    void SpiralOrderTraversalOfBinaryTreeNode(Node *ipRootNode, std::vector<Node *> &ovNodes);

    /**
     * @brief Retrieves all leaf nodes of sub binary tree having root node as given node
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void RetrieveLeafNodesOfBinaryTreeNode(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Retrieves all non-leaf nodes of sub binary tree having root node as given node
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void RetrieveNonLeafNodesOfBinaryTreeNode(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Retrieves all boundary nodes of sub-binary tree having root node as given node
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void RetrieveLeftBoundaryNodesOfBinaryTreeNode(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Retrieves all right boundary nodes of sub-binary tree having root node as given node
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void RetrieveRightBoundaryNodesOfBinaryTreeNode(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Retrieves all full nodes of sub-binary tree whose root is ipNode
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void PrintFullNodes(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Retrieves all half nodes of sub-binary tree whose root is ipNode
     * @param[in] ipNode Node to traverse
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void PrintHalfNodes(Node *ipNode, std::vector<Node *> &iovNodes);

    /**
     * @brief Retrieves all nodes at a distance k from the root node
     * @param[in] ipNode Node to traverse
     * @param[in] inKDistance Distance from the root node
     * @param[in, out] iovNodes Vector containing list of pointers of ouput nodes
     */
    void RetrieveAllNodesAtKDistance(Node *ipNode, int inKDistance, std::vector<Node *> &iovNodes);

    /**
     * @brief Retrieves sibling node of a given data
     * @param[in] ipNode Node to traverse
     * @param[in] inData Data of a node whose cousins are to be printed
     * @return True if sibling is found, false otherwise
     */
    Node *RetrieveSibling(Node *ipNode, int inData);

    /**
     * @brief Retrieves all cousin nodes of a given data
     * @param[in] ipRootNode Root node of the binary tree
     * @param[in] inData Data of a node whose cousins are to be printed
     * @param[out] ovNodes Vector containing list of pointers of ouput nodes
     */
    void RetrieveCousins(Node *ipRootNode, int inData, std::vector<Node *> &ovNodes);

    /**
     * @brief Returns the height of sub binary tree having root node as given node
     * @details The height of a given binary tree node is the number of edges on the longest path between the given node and a leaf node.
     * @param[in] ipNode Node whose height is to be calculated
     * @return Height of the binary tree
     */
    int HeightOfSubBinaryTree(Node *ipNode);

    /**
     * @brief Represents the root node of the binary tree
     *
     * The root node is the starting point of the tree.
     * It is the topmost node in the tree.
     */
    Node *_pRootNode;
};
