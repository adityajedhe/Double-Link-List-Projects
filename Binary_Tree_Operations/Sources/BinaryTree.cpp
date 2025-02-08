//===================================================================
// Name         : BinaryTree.cpp
// Description  : Implementation file for the BinaryTree class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/05
//===================================================================

#include <iostream>
#include <queue>
#include "BinaryTree.h"
#include "Node.h"

//-------------------------------------------------------------------
/**
 * @brief Constructor for BinaryTree
 */
BinaryTree::BinaryTree() :
    _pRootNode(nullptr)
{
}

//-------------------------------------------------------------------
/**
 * @brief Destructor for BinaryTree
 *
 * Deletes all nodes in the binary tree.
 *
 */
BinaryTree::~BinaryTree()
{
    RemoveChildren(_pRootNode);

    _pRootNode = nullptr;
}

//-------------------------------------------------------------------
/**
 * @brief Removes all children of a given node
 * @param pParentNode Parent node whose children are to be removed
 * @return True if the children are removed, false otherwise
 */
void BinaryTree::RemoveChildren(Node* pParentNode)
{
    if (nullptr == pParentNode)    return;

    RemoveChildren(pParentNode->GetLeftNode());
    RemoveChildren(pParentNode->GetRightNode());

    delete pParentNode;
    pParentNode = nullptr;
}

//-------------------------------------------------------------------
/**
 * @brief Checks if the binary tree is empty
 * @return True if the binary tree is empty, false otherwise
 */
bool BinaryTree::IsEmpty()
{
    return (nullptr == _pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Inserts a new data element into the binary search tree
 *
 * The binary search tree is a data structure in which each node has at most two children, referred to as the left child and the right child. Also no two nodes have the same data element. The left child of a node has a value less than the parent node, and the right child has a value greater than the parent node.
 *
 * @param inData Data element to insert
 */
void BinaryTree::InsertInBinarySearchTree(int inData)
{
    /**
     * Create a new node with the data element
     * and insert it into the binary search tree
     */
    Node* pNewNode = new Node(inData);

    if (nullptr != _pRootNode)
    {
        Node* pCurrentNode = _pRootNode;
        Node* pParentNode = nullptr;

        while (nullptr != pCurrentNode)
        {
            pParentNode = pCurrentNode;

            if (inData < pCurrentNode->GetData())
            {
                pCurrentNode = pCurrentNode->GetLeftNode();
            }
            else
            {
                pCurrentNode = pCurrentNode->GetRightNode();
            }
        }

        if (inData < pParentNode->GetData())
        {
            pParentNode->SetLeftNode(pNewNode);
        }
        else
        {
            pParentNode->SetRightNode(pNewNode);
        }
    }
    else
    {
        _pRootNode = pNewNode;
    }
}

//-------------------------------------------------------------------
/**
 * @brief Deletes a data element from the binary tree
 * @param inData Data element to delete
 */
void BinaryTree::Delete(int inData)
{
    std::cout << "Deleting data element: " << inData << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Returns the height of the binary tree
 *
 * The height of a binary tree is the number of edges on the longest path between the root node and a leaf node.
 *
 * @return Height of the binary tree
 */
int BinaryTree::HeightOfBinaryTree()
{
    return HeightOfBinaryTreeNode(_pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Performs an in-order traversal of the binary tree
 *
 * Prints all elements in the binary tree in in-order sequence.
 *
 */
void BinaryTree::InOrderTraversal()
{
    InOrderTraversalOfBinaryTreeNode(_pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Performs an pre-order traversal of the binary tree
 *
 * Prints all elements in the binary tree in pre-order sequence.
 *
 */
void BinaryTree::PreOrderTraversal()
{
    PreOrderTraversalOfBinaryTreeNode(_pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Performs an post-order traversal of the binary tree
 *
 * Prints all elements in the binary tree in post-order sequence.
 *
 */
void BinaryTree::PostOrderTraversal()
{
    PostOrderTraversalOfBinaryTreeNode(_pRootNode);
}

//-------------------------------------------------------------------
/**
 * @brief Returns the height of the given binary tree node
 *
 * The height of a given binary tree node is the number of edges on the longest path between the given node and a leaf node.
 *
 * @param pNode Node whose height is to be calculated
 * @return Height of the binary tree
 */
int BinaryTree::HeightOfBinaryTreeNode(Node* pNode)
{
    int nHeight(-1);

    if (nullptr != pNode)
    {
        int nLeftHeight = HeightOfBinaryTreeNode(pNode->GetLeftNode());
        int nRightHeight = HeightOfBinaryTreeNode(pNode->GetRightNode());

        nHeight = (nLeftHeight > nRightHeight) ? (nLeftHeight + 1) : (nRightHeight + 1);
    }

    return nHeight;
}

//-------------------------------------------------------------------
/**
 * @brief Performs a level-order traversal of the binary tree
 *
 * Prints all elements in the binary tree in level-order sequence.
 *
 */
void BinaryTree::LevelOrderTraversal()
{
    if (nullptr == _pRootNode)    return;

    std::cout << "Level order traversal: ";

    std::queue<Node*> qNodes;

    qNodes.push(_pRootNode);

    Node* pNode = nullptr;

    while (!qNodes.empty())
    {
        pNode = qNodes.front();

        qNodes.pop();

        if (nullptr == pNode)    continue;

        std::cout << pNode->GetData() << " ";

        if (nullptr != pNode->GetLeftNode())
        {
            qNodes.push(pNode->GetLeftNode());
        }

        if (nullptr != pNode->GetRightNode())
        {
            qNodes.push(pNode->GetRightNode());
        }
    }

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Prints all leaf nodes of the binary tree
 */
void BinaryTree::PrintLeafNodes()
{
    std::cout << "Leaf nodes: ";

    PrintLeafNodes(_pRootNode);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Prints all non-leaf nodes of the binary tree
 */
void BinaryTree::PrintNonLeafNodes()
{
    std::cout << "Leaf nodes: ";

    PrintNonLeafNodes(_pRootNode);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Prints all nodes at a distance k from the root node
 * @param k Distance from the root node
 */
void BinaryTree::PrintAllNodesAtKDistance(int k)
{
    PrintAllNodesAtKDistance(_pRootNode, k);
}

//-------------------------------------------------------------------
/**
 * @brief Performs an in-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in in-order sequence.
 *
 * @param pNode Node to traverse
 */
void BinaryTree::InOrderTraversalOfBinaryTreeNode(Node* pNode)
{
    if (nullptr == pNode)    return;

    InOrderTraversalOfBinaryTreeNode(pNode->GetLeftNode());

    // Print the data element
    // ----------------------------------
    std::cout << pNode->GetData() << " ";

    InOrderTraversalOfBinaryTreeNode(pNode->GetRightNode());
}

//-------------------------------------------------------------------
/**
 * @brief Performs an pre-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in pre-order sequence.
 *
 * @param pNode Node to traverse
 */
void BinaryTree::PreOrderTraversalOfBinaryTreeNode(Node* pNode)
{
    if (nullptr == pNode)    return;

    // Print the data element
    // ----------------------------------
    std::cout << pNode->GetData() << " ";

    PreOrderTraversalOfBinaryTreeNode(pNode->GetLeftNode());

    PreOrderTraversalOfBinaryTreeNode(pNode->GetRightNode());
}

//-------------------------------------------------------------------
/**
 * @brief Performs an post-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in post-order sequence.
 *
 * @param pNode Node to traverse
 */
void BinaryTree::PostOrderTraversalOfBinaryTreeNode(Node* pNode)
{
    if (nullptr == pNode)    return;

    PostOrderTraversalOfBinaryTreeNode(pNode->GetLeftNode());

    PostOrderTraversalOfBinaryTreeNode(pNode->GetRightNode());

    // Print the data element
    // ----------------------------------
    std::cout << pNode->GetData() << " ";
}

//-------------------------------------------------------------------
/**
 * @brief Prints all leaf nodes of the binary tree
 * @param pNode Node to traverse
 */
void BinaryTree::PrintLeafNodes(Node* pNode)
{
    if (nullptr == pNode)    return;

    if ((nullptr == pNode->GetLeftNode()) && (nullptr == pNode->GetRightNode()))
    {
        std::cout << pNode->GetData() << " ";
    }
    else
    {
        PrintLeafNodes(pNode->GetLeftNode());
        PrintLeafNodes(pNode->GetRightNode());
    }
}

//-------------------------------------------------------------------
/**
 * @brief Prints all non-leaf nodes of the binary tree
 * @param pNode Node to traverse
 */
void BinaryTree::PrintNonLeafNodes(Node* pNode)
{
    if (nullptr == pNode)    return;

    if ((nullptr != pNode->GetLeftNode()) || (nullptr != pNode->GetRightNode()))
    {
        std::cout << pNode->GetData() << " ";

        PrintLeafNodes(pNode->GetLeftNode());
        PrintLeafNodes(pNode->GetRightNode());
    }
}

//-------------------------------------------------------------------
/**
 * @brief Prints all nodes at a distance k from the root node
 * @param pNode Node to traverse
 * @param k Distance from the root node
 */
void BinaryTree::PrintAllNodesAtKDistance(Node* pNode, int k)
{
    if (nullptr == pNode)    return;

    if (0 == k)
    {
        std::cout << pNode->GetData() << " ";
    }
    else
    {
        PrintAllNodesAtKDistance(pNode->GetLeftNode(), k - 1);
        PrintAllNodesAtKDistance(pNode->GetRightNode(), k - 1);
    }
}
