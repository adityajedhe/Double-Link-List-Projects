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
 * @param ipParentNode Parent node whose children are to be removed
 * @return True if the children are removed, false otherwise
 */
void BinaryTree::RemoveChildren(Node* ipParentNode)
{
    if (nullptr == ipParentNode)    return;

    RemoveChildren(ipParentNode->GetLeftNode());
    RemoveChildren(ipParentNode->GetRightNode());

    delete ipParentNode;
    ipParentNode = nullptr;
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
 * @param ipNode Node whose height is to be calculated
 * @return Height of the binary tree
 */
int BinaryTree::HeightOfBinaryTreeNode(Node* ipNode)
{
    int nHeight(-1);

    if (nullptr != ipNode)
    {
        int nLHeight = HeightOfBinaryTreeNode(ipNode->GetLeftNode());
        int nRHeight = HeightOfBinaryTreeNode(ipNode->GetRightNode());

        nHeight = (nLHeight > nRHeight) ? (nLHeight + 1) : (nRHeight + 1);
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
 * @param inKDistance Distance from the root node
 */
void BinaryTree::PrintAllNodesAtKDistance(int inKDistance)
{
    PrintAllNodesAtKDistance(_pRootNode, inKDistance);
}

//-------------------------------------------------------------------
/**
 * @brief Prints all ancestor nodes of a given data element
 * @param inData Data element whose ancestors are to be printed
 */
void BinaryTree::PrintAncestor(int inData)
{
    std::cout << "Ancestors of " << inData << ": ";

    PrintAncestor(_pRootNode, inData);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Performs an in-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in in-order sequence.
 *
 * @param ipNode Node to traverse
 */
void BinaryTree::InOrderTraversalOfBinaryTreeNode(Node* ipNode)
{
    if (nullptr == ipNode)    return;

    InOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode());

    // Print the data element
    // ----------------------------------
    std::cout << ipNode->GetData() << " ";

    InOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode());
}

//-------------------------------------------------------------------
/**
 * @brief Performs an pre-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in pre-order sequence.
 *
 * @param ipNode Node to traverse
 */
void BinaryTree::PreOrderTraversalOfBinaryTreeNode(Node* ipNode)
{
    if (nullptr == ipNode)    return;

    // Print the data element
    // ----------------------------------
    std::cout << ipNode->GetData() << " ";

    PreOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode());

    PreOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode());
}

//-------------------------------------------------------------------
/**
 * @brief Performs an post-order traversal of the binary tree node
 *
 * Prints all elements under the binary tree node in post-order sequence.
 *
 * @param ipNode Node to traverse
 */
void BinaryTree::PostOrderTraversalOfBinaryTreeNode(Node* ipNode)
{
    if (nullptr == ipNode)    return;

    PostOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode());

    PostOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode());

    // Print the data element
    // ----------------------------------
    std::cout << ipNode->GetData() << " ";
}

//-------------------------------------------------------------------
/**
 * @brief Prints all leaf nodes of the binary tree
 * @param ipNode Node to traverse
 */
void BinaryTree::PrintLeafNodes(Node* ipNode)
{
    if (nullptr == ipNode)    return;

    if ((nullptr == ipNode->GetLeftNode()) && (nullptr == ipNode->GetRightNode()))
    {
        std::cout << ipNode->GetData() << " ";
    }
    else
    {
        PrintLeafNodes(ipNode->GetLeftNode());
        PrintLeafNodes(ipNode->GetRightNode());
    }
}

//-------------------------------------------------------------------
/**
 * @brief Prints all non-leaf nodes of the binary tree
 * @param ipNode Node to traverse
 */
void BinaryTree::PrintNonLeafNodes(Node* ipNode)
{
    if (nullptr == ipNode)    return;

    if ((nullptr != ipNode->GetLeftNode()) || (nullptr != ipNode->GetRightNode()))
    {
        std::cout << ipNode->GetData() << " ";

        PrintLeafNodes(ipNode->GetLeftNode());
        PrintLeafNodes(ipNode->GetRightNode());
    }
}

//-------------------------------------------------------------------
/**
 * @brief Prints all nodes at a distance k from the root node
 * @param ipNode Node to traverse
 * @param inKDistance Distance from the root node
 */
void BinaryTree::PrintAllNodesAtKDistance(Node* ipNode, int inKDistance)
{
    if (nullptr == ipNode)    return;

    if (0 == inKDistance)
    {
        std::cout << ipNode->GetData() << " ";
    }
    else
    {
        PrintAllNodesAtKDistance(ipNode->GetLeftNode(), inKDistance - 1);
        PrintAllNodesAtKDistance(ipNode->GetRightNode(), inKDistance - 1);
    }
}

//-------------------------------------------------------------------
/**
 * @brief Prints all ancestor nodes of a given data element
 * @param ipNode Node to traverse
 * @param inData Data element whose ancestors are to be printed
 */
void BinaryTree::PrintAncestor(Node* ipNode, int inData)
{
    if (nullptr == ipNode)    return;

    Node* pLNode = ipNode->GetLeftNode();
    Node* pRNode = ipNode->GetRightNode();

    if ((nullptr != pLNode) && (inData == pLNode->GetData()))
    {
        std::cout << ipNode->GetData() << " ";
    }
    else if ((nullptr != pRNode) && (inData == pRNode->GetData()))
    {
        std::cout << ipNode->GetData() << " ";
    }
    else
    {
        PrintAncestor(pLNode, inData);
        PrintAncestor(pRNode, inData);
    }
}
