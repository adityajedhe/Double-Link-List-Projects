//===================================================================
// Name         : BinaryTree.cpp
// Description  : Implementation file for the BinaryTree class
// @author      : Aditya Jedhe [@adityajedhe]
// @date        : 2025/02/06
//===================================================================

// ---------------------------------------------- Local Headers
#include "BinaryTree.h"

// ---------------------------------------------- Project Headers
#include "Node.h"

// ---------------------------------------------- System Headers
#include <iostream>

// ---------------------------------------------- STL Headers
#include <queue>


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

    delete _pRootNode;
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

    Node* pLNode = ipParentNode->GetLeftNode();
    Node* pRNode = ipParentNode->GetRightNode();

    RemoveChildren(pLNode);
    RemoveChildren(pRNode);

    delete pLNode;
    delete pRNode;

    pLNode = nullptr;
    pRNode = nullptr;
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
    return HeightOfSubBinaryTree(_pRootNode);
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
    std::cout << "In order traversal: ";

    InOrderTraversalOfBinaryTreeNode(_pRootNode);

    std::cout << std::endl;
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
    std::cout << "Pre order traversal: ";

    PreOrderTraversalOfBinaryTreeNode(_pRootNode);

    std::cout << std::endl;
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
    std::cout << "Post order traversal: ";

    PostOrderTraversalOfBinaryTreeNode(_pRootNode);

    std::cout << std::endl;
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
/*
void BinaryTree::LevelOrderTraversal(std::queue<Node*>& ioqNodes)
{
    if (ioqNodes.empty())    return;

    Node* pNode = ioqNodes.front();

    ioqNodes.pop();

    if (nullptr == pNode)    return;

    std::cout << pNode->GetData() << " ";

    if (nullptr != pNode->GetLeftNode())
    {
        ioqNodes.push(pNode->GetLeftNode());
    }

    if (nullptr != pNode->GetRightNode())
    {
        ioqNodes.push(pNode->GetRightNode());
    }
}
//*/

//-------------------------------------------------------------------
/**
 * @brief Performs a reverse level-order traversal of the binary tree
 *
 * Prints all elements in the binary tree in level-order sequence in reverse manner.
 *
 */
void BinaryTree::ReverseLevelOrderTraversal()
{
}

//-------------------------------------------------------------------
/**
 * @brief Performs a spiral order traversal of the binary tree
 *
 * Prints all elements in the binary tree in spiral order sequence.
 *
 */
void BinaryTree::SpiralOrderTraversal()
{
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
    std::cout << "Non-leaf nodes: ";

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
    std::cout << "All nodes at 'k' distance: ";

    PrintAllNodesAtKDistance(_pRootNode, inKDistance);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Finds the node with the given data element
 * @param inData Data element to find
 * @return Distance from the given node, if found. Otherwise -1
 */
int BinaryTree::FindDistanceFromRootNode(int inData)
{
    std::stack<int> sNodePath;

    return FindDistanceFromNode(_pRootNode, inData, sNodePath);
}

//-------------------------------------------------------------------
/**
 * @brief Prints all ancestor nodes of a given data element
 * @param inData Data element whose ancestor is to be printed
 */
void BinaryTree::PrintAncestor(int inData)
{
    std::cout << "Ancestor of " << inData << ": ";

    PrintAncestor(_pRootNode, inData);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Prints all ancestor nodes of a given data element
 * @param inData Data element whose ancestors are to be printed
 */
void BinaryTree::PrintAncestors(int inData)
{
    std::cout << "Ancestors of " << inData << ": ";

    if (nullptr == _pRootNode)
    {
        std::cout << "ERR<<Tree is empty.>>" << std::endl;
        return;
    }

    std::stack<int> sNodePath;

    int nDistance = FindDistanceFromNode(_pRootNode, inData, sNodePath);

    if (0 < nDistance)
    {
        PrintAncestors(_pRootNode, sNodePath);
    }
    else
    {
        std::cout << "Node is not found for the given data element." << std::endl;
    }

    std::cout << std::endl;
}
/*
{
    std::cout << "Ancestors of " << inData << ": ";

    if (nullptr == _pRootNode)
    {
        std::cout << "ERR<<Tree is empty.>>" << std::endl;
        return;
    }

    Node* pLNode = _pRootNode->GetLeftNode();
    Node* pRNode = _pRootNode->GetRightNode();

    int nLDistance = FindDistanceFromNode(pLNode, inData);
    int nRDistance = FindDistanceFromNode(pRNode, inData);

    if (0 < nLDistance)
    {
        PrintAncestor(_pRootNode, pLNode->GetData());
    }
    else if (0 < nRDistance)
    {
        PrintAncestor(_pRootNode, pRNode->GetData());
    }
    else
    {
        std::cout << "No ancestors found for the given data element." << std::endl;
    }

    std::cout << std::endl;
}
*/

//-------------------------------------------------------------------
/**
 * @brief Prints all cousin nodes of a given data element
 * @param inData Data element whose cousins are to be printed
 */
void BinaryTree::PrintCousins(int inData)
{
    std::cout << "Cousins of " << inData << ": ";

    int nDistance = FindDistanceFromRootNode(inData);

    PrintCousins(_pRootNode, inData, nDistance);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Prints all sibling nodes of a given data element
 * @param inData Data element whose siblings are to be printed
 */
void BinaryTree::PrintSibling(int inData)
{
    std::cout << "Sibling of " << inData << ": ";

    int nDistance = FindDistanceFromRootNode(inData);

    PrintCousins(_pRootNode, inData, nDistance);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
/**
 * @brief Returns the height of sub binary tree having root node as given node
 *
 * The height of a given binary tree node is the number of edges on the longest path between the given node and a leaf node.
 *
 * @param ipNode Node whose height is to be calculated
 * @return Height of the binary tree
 */
int BinaryTree::HeightOfSubBinaryTree(Node* ipNode)
{
    int nHeight(-1);

    if (nullptr != ipNode)
    {
        int nLHeight = HeightOfSubBinaryTree(ipNode->GetLeftNode());
        int nRHeight = HeightOfSubBinaryTree(ipNode->GetRightNode());

        nHeight = (nLHeight > nRHeight) ? (nLHeight + 1) : (nRHeight + 1);
    }

    return nHeight;
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
 * @brief Prints all leaf nodes of sub binary tree having root node as given node
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
 * @brief Prints all non-leaf nodes of sub binary tree having root node as given node
 * @param ipNode Node to traverse
 */
void BinaryTree::PrintNonLeafNodes(Node* ipNode)
{
    if (nullptr == ipNode)    return;

    if ((nullptr != ipNode->GetLeftNode()) || (nullptr != ipNode->GetRightNode()))
    {
        std::cout << ipNode->GetData() << " ";

        PrintNonLeafNodes(ipNode->GetLeftNode());
        PrintNonLeafNodes(ipNode->GetRightNode());
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
 * @brief Finds the distance of node with the given data element from the given node
 * @param ipNode Node to traverse
 * @param inData Data element to find
 * @param iosNodePath Stack to store the path of the node
 * @return Distance from the given node, if found. Otherwise -1
 */
int BinaryTree::FindDistanceFromNode(Node* ipNode, int inData, std::stack<int>& iosNodePath)
{
    int nDistance(-1);

    if (nullptr == ipNode)    return nDistance;

    if (ipNode->GetData() == inData)
    {
        nDistance = 0;
    }
    else
    {
        nDistance = FindDistanceFromNode(ipNode->GetLeftNode(), inData, iosNodePath);

        if (0 > nDistance)
        {
            nDistance = FindDistanceFromNode(ipNode->GetRightNode(), inData, iosNodePath);

            iosNodePath.push(1);
        }
        else
        {
            iosNodePath.push(0);
        }

        if (0 <= nDistance)
        {
            ++nDistance;
        }
    }

    return nDistance;
}

//-------------------------------------------------------------------
/**
 * @brief Prints immidiate ancestor node of a given data element
 * @param ipNode Node to traverse
 * @param inData Data element whose ancestor is to be printed
 */
bool BinaryTree::PrintAncestor(Node* ipNode, int inData)
{
    bool bFound(false);

    if (nullptr == ipNode)    return bFound;

    Node* pLNode = ipNode->GetLeftNode();
    Node* pRNode = ipNode->GetRightNode();

    if ((nullptr != pLNode) && (pLNode->GetData() == inData))
    {
        std::cout << ipNode->GetData() << " ";
        bFound = true;
    }
    else if ((nullptr != pRNode) && (pRNode->GetData() == inData))
    {
        std::cout << ipNode->GetData() << " ";
        bFound = true;
    }
    else
    {
        bFound = PrintAncestor(pLNode, inData);

        if (!bFound)
        {
            bFound = PrintAncestor(pRNode, inData);
        }
    }

    return bFound;
}

//-------------------------------------------------------------------
/**
 * @brief Prints all ancestor nodes of a given data element by traversing the path and printing the nodes
 * @param ipNode Node to traverse
 * @param inData Data element whose ancestors are to be printed
 * @param iosNodePath stack to store the path of the node
 */
void BinaryTree::PrintAncestors(Node* ipNode, std::stack<int>& iosNodePath)
{
    if (nullptr == ipNode)    return;

    std::cout << ipNode->GetData() << " ";

    if (!iosNodePath.empty())
    {
        int nPathDirection = iosNodePath.top();

        iosNodePath.pop();

        if (0 == nPathDirection)
        {
            PrintAncestors(ipNode->GetLeftNode(), iosNodePath);
        }
        else
        {
            PrintAncestors(ipNode->GetRightNode(), iosNodePath);
        }
    }
}

//-------------------------------------------------------------------
/**
 * @brief Prints all cousin nodes of a given data element
 * @param ipNode Node to traverse
 * @param inData Data element whose cousins are to be printed
 * @param inNodeHeight Height of the node
 */
void BinaryTree::PrintCousins(Node* ipNode, int inData, int inNodeHeight)
{
    if (nullptr == ipNode)    return;

    if (0 == inNodeHeight)
    {
        std::cout << ipNode->GetData() << " ";
    }
    else
    {
        Node* pLNode = ipNode->GetLeftNode();
        Node* pRNode = ipNode->GetRightNode();

        if (((nullptr != pLNode) && (pLNode->GetData() == inData)) ||
            ((nullptr != pRNode) && (pRNode->GetData() == inData)))
        {
        }
        else
        {
            PrintAllNodesAtKDistance(pLNode, inNodeHeight - 1);
            PrintAllNodesAtKDistance(pRNode, inNodeHeight - 1);
        }
    }
}

/*
//-------------------------------------------------------------------
{
    if (nullptr == ipNode || ipNode->GetData() == inData) return;

    std::queue<Node*> qNodes;

    qNodes.push(ipNode);

    Node* pNode = nullptr;
    Node* pLNode = nullptr;
    Node* pRNode = nullptr;

    bool bFound = false;

    while (!qNodes.empty() && !bFound)
    {
        int size = qNodes.size();

        while (size--)
        {
            pNode = qNodes.front();

            qNodes.pop();

            if (nullptr == pNode)    continue;

            pLNode = pNode->GetLeftNode();
            pRNode = pNode->GetRightNode();

            if (((nullptr != pLNode) && (pLNode->GetData() == inData)) ||
                ((nullptr != pRNode) && (pRNode->GetData() == inData)))
            {
                bFound = true;
            }
            else
            {
                if (nullptr != pLNode)
                {
                    qNodes.push(pNode->GetLeftNode());
                }

                if (nullptr != pRNode)
                {
                    qNodes.push(pNode->GetRightNode());
                }
            }
        }
    }

    if (bFound)
    {
        while (!qNodes.empty())
        {
            pNode = qNodes.front();

            qNodes.pop();

            std::cout << pNode->GetData() << " ";
        }
    }
    else
    {
        std::cout << "No cousins found for the given data element." << std::endl;
    }
}
//*/

//-------------------------------------------------------------------
/**
 * @brief Prints sibling node of a given data element
 * @param ipNode Node to traverse
 * @param inData Data element whose cousins are to be printed
 */
bool BinaryTree::PrintSibling(Node* ipNode, int inData)
{
    bool bFound(false);

    if (nullptr == ipNode)    return bFound;

    Node* pNode = nullptr;
    Node* pLNode = ipNode->GetLeftNode();
    Node* pRNode = ipNode->GetRightNode();

    if ((nullptr != pLNode) && (pLNode->GetData() == inData))
    {
        pNode = pRNode;
        bFound = true;
    }
    else if ((nullptr != pRNode) && (pRNode->GetData() == inData))
    {
        pNode = pLNode;
        bFound = true;
    }

    if (bFound)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
        else
        {
            std::cout << "No sibling present for the given data element." << std::endl;
        }
    }
    else
    {
        bFound = PrintSibling(pLNode, inData);

        if (!bFound)
        {
            bFound = PrintSibling(pRNode, inData);
        }
    }

    return bFound;
}
