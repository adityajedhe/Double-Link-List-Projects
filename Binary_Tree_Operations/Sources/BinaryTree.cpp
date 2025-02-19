//-------------------------------------------------------------------
/**
 * @file BinaryTree.cpp
 * @brief Implementation file for the BinaryTree class.
 * @author Aditya Jedhe
 * @date 2025-02-06
 */
//-------------------------------------------------------------------

// ---------------------------------------------- Local Headers
#include "BinaryTree.h"

// ---------------------------------------------- Project Headers
#include "Node.h"

// ---------------------------------------------- System Headers
#include <iostream>
#include <queue>
#include <thread>

//-------------------------------------------------------------------
BinaryTree *BinaryTree::CreateBinaryTree()
{
    return new BinaryTree;
}

//-------------------------------------------------------------------
void BinaryTree::RemoveBinaryTree(BinaryTree *&ipBinaryTree)
{
    if ((nullptr == ipBinaryTree) || (ipBinaryTree->IsEmpty()))
    {
        return;
    }

    Node *pRootNode = ipBinaryTree->_pRootNode;

    ipBinaryTree->RemoveChildren(pRootNode);

    delete pRootNode;
    pRootNode = nullptr;

    delete ipBinaryTree;
    ipBinaryTree = nullptr;
}

//-------------------------------------------------------------------
bool BinaryTree::IsEmpty()
{
    bool bEmpty(false);

    if (nullptr == _pRootNode)
    {
        std::cout << "ERR<<Tree is empty.>>" << std::endl;
        bEmpty = true;
    }

    return bEmpty;
}

//-------------------------------------------------------------------
void BinaryTree::InsertInBinaryTree(int inData)
{
    /**
     * Create a new node with the data element and
     * insert it into the complete binary tree
     * if root node exists, otherwise make it as a root node
     */
    Node *pNewNode = new Node(inData);

    if (nullptr == pNewNode)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return;
    }

    if (nullptr != _pRootNode)
    {
        InsertNodeInBinaryTree(_pRootNode, pNewNode);
    }
    else
    {
        _pRootNode = pNewNode;
    }
}

//-------------------------------------------------------------------
void BinaryTree::InsertInBinarySearchTree(int inData)
{
    /**
     * Create a new node with the data element
     * and insert it into the binary search tree
     */
    Node *pNewNode = new Node(inData);

    if (nullptr == pNewNode)
    {
        return;
    }

    if (nullptr != _pRootNode)
    {
        Node *pCurrentNode = _pRootNode;
        Node *pParentNode = nullptr;

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
void BinaryTree::DeleteBinaryTreeNode(int inData)
{
    if (IsEmpty())
    {
        return;
    }

    std::cout << "Deleting data element: " << inData << std::endl;
}

//-------------------------------------------------------------------
int BinaryTree::SearchInBinaryTree(int inData)
{
    std::stack<int> sNodePath;

    return FindDistanceFromNode(_pRootNode, inData, sNodePath);
}

//-------------------------------------------------------------------
void BinaryTree::PreOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::cout << "Pre order traversal: ";

    PreOrderTraversalOfBinaryTreeNode(_pRootNode);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::InOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::cout << "In order traversal: ";

    InOrderTraversalOfBinaryTreeNode(_pRootNode);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::PostOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::cout << "Post order traversal: ";

    PostOrderTraversalOfBinaryTreeNode(_pRootNode);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::LevelOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    LevelOrderTraversal(vNodes);

    std::cout << "Level order traversal: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::LevelOrderTraversal(std::vector<Node *> &ovNodes)
{
    Node *pNode = nullptr;

    ovNodes.push_back(_pRootNode);

    for (int nIdx = 0; nIdx < (int)(ovNodes.size()); ++nIdx)
    {
        pNode = ovNodes[nIdx];

        if (nullptr == pNode)
        {
            continue;
        }

        Node *pLNode = pNode->GetLeftNode();
        Node *pRNode = pNode->GetRightNode();

        if (nullptr != pLNode)
        {
            ovNodes.push_back(pLNode);
        }

        if (nullptr != pRNode)
        {
            ovNodes.push_back(pRNode);
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::ReverseLevelOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }
}

//-------------------------------------------------------------------
void BinaryTree::SpiralOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }
}

//-------------------------------------------------------------------
void BinaryTree::PrintLeafNodes()
{
    if (IsEmpty())
    {
        return;
    }

    std::cout << "Leaf nodes: ";

    PrintLeafNodes(_pRootNode);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::PrintNonLeafNodes()
{
    if (IsEmpty())
    {
        return;
    }

    std::cout << "Non-leaf nodes: ";

    PrintNonLeafNodes(_pRootNode);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::PrintBoundaryNodes()
{
    if (IsEmpty())
    {
        return;
    }

    PrintLeftBoundaryNodes(_pRootNode->GetLeftNode());
    PrintLeafNodes(_pRootNode);
    PrintRightBoundaryNodes(_pRootNode->GetRightNode());
}

//-------------------------------------------------------------------
void BinaryTree::PrintAllFullNodes()
{
}

//-------------------------------------------------------------------
void BinaryTree::PrintAllHalfNodes()
{
}

//-------------------------------------------------------------------
void BinaryTree::PrintAllNodesAtKDistance(int inKDistance)
{
    std::cout << "All nodes at 'k' distance: ";

    PrintAllNodesAtKDistance(_pRootNode, inKDistance);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::PrintSibling(int inData)
{
    std::cout << "Sibling of " << inData << ": ";

    // int nDistance = SearchInBinaryTree(inData);

    PrintSibling(_pRootNode, inData /*, nDistance*/);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::PrintCousins(int inData)
{
    std::cout << "Cousins of " << inData << ": ";

    int nDistance = SearchInBinaryTree(inData);

    PrintCousins(_pRootNode, inData, nDistance);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
void BinaryTree::PrintAncestors(int inData)
{
    std::cout << "Ancestors of " << inData << ": ";

    if (IsEmpty())
    {
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

    if (IsEmpty())
    {
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
void BinaryTree::PrintDecendants(int inData)
{
    std::cout << inData;
}

//-------------------------------------------------------------------
void BinaryTree::PrintAncestor(int inData)
{
    std::cout << "Ancestor of " << inData << ": ";

    PrintAncestor(_pRootNode, inData);

    std::cout << std::endl;
}

//-------------------------------------------------------------------
int BinaryTree::HeightOfBinaryTree()
{
    return HeightOfSubBinaryTree(_pRootNode);
}

//-------------------------------------------------------------------
int BinaryTree::FindLevelOfNode(int inData)
{
    return inData;
}

//===================================================================
// Private Methods: Implementation
//===================================================================

//-------------------------------------------------------------------
BinaryTree::BinaryTree() : _pRootNode(nullptr)
{
}

//-------------------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-------------------------------------------------------------------
void BinaryTree::RemoveChildren(Node *ipParentNode)
{
    if (nullptr == ipParentNode)
    {
        return;
    }

    Node *pLNode = ipParentNode->GetLeftNode();
    Node *pRNode = ipParentNode->GetRightNode();

    std::thread objThread1(&BinaryTree::RemoveChildren, this, pLNode);
    std::thread objThread2(&BinaryTree::RemoveChildren, this, pRNode);

    objThread1.join();
    objThread2.join();

    delete pLNode;
    delete pRNode;

    pLNode = nullptr;
    pRNode = nullptr;
}

//-------------------------------------------------------------------
bool BinaryTree::InsertNodeInBinaryTree(Node *ipNode, Node *ipNewNode)
{
    if ((nullptr == ipNode) && (nullptr == ipNewNode))
    {
        return false;
    }

    bool bNodeInserted(true);

    Node *pLNode = ipNode->GetLeftNode();
    Node *pRNode = ipNode->GetRightNode();

    if (nullptr == pLNode)
    {
        ipNode->SetLeftNode(ipNewNode);
    }
    else if (nullptr == pRNode)
    {
        ipNode->SetRightNode(ipNewNode);
    }
    else
    {
        bNodeInserted = InsertNodeInBinaryTree(pLNode, ipNewNode);

        if (!bNodeInserted)
        {
            bNodeInserted = InsertNodeInBinaryTree(pRNode, ipNewNode);
        }
    }

    return bNodeInserted;
}

//-------------------------------------------------------------------
int BinaryTree::FindDistanceFromNode(Node *ipNode, int inData, std::stack<int> &iosNodePath)
{
    int nDistance(-1);

    if (nullptr == ipNode)
    {
        return nDistance;
    }

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
void BinaryTree::PreOrderTraversalOfBinaryTreeNode(Node *ipNode)
{
    if (nullptr == ipNode)
    {
        return;
    }

    /**
     * Print the data element
     */
    std::cout << ipNode->GetData() << " ";

    PreOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode());

    PreOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode());
}

//-------------------------------------------------------------------
void BinaryTree::InOrderTraversalOfBinaryTreeNode(Node *ipNode)
{
    if (nullptr == ipNode)
    {
        return;
    }

    InOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode());

    /**
     * Print the data element
     */
    std::cout << ipNode->GetData() << " ";

    InOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode());
}

//-------------------------------------------------------------------
void BinaryTree::PostOrderTraversalOfBinaryTreeNode(Node *ipNode)
{
    if (nullptr == ipNode)
    {
        return;
    }

    PostOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode());

    PostOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode());

    /**
     * Print the data element
     */
    std::cout << ipNode->GetData() << " ";
}

//-------------------------------------------------------------------
int BinaryTree::HeightOfSubBinaryTree(Node *ipNode)
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
void BinaryTree::PrintLeafNodes(Node *ipNode)
{
    if (nullptr == ipNode)
    {
        return;
    }

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
void BinaryTree::PrintNonLeafNodes(Node *ipNode)
{
    if (nullptr == ipNode)
    {
        return;
    }

    if ((nullptr != ipNode->GetLeftNode()) || (nullptr != ipNode->GetRightNode()))
    {
        std::cout << ipNode->GetData() << " ";

        PrintNonLeafNodes(ipNode->GetLeftNode());
        PrintNonLeafNodes(ipNode->GetRightNode());
    }
}

//-------------------------------------------------------------------
void BinaryTree::PrintLeftBoundaryNodes(Node *ipNode)
{
    if (nullptr == ipNode)
    {
        return;
    }

    Node *pNode = ipNode->GetLeftNode();

    if (nullptr == pNode)
    {
        pNode = ipNode->GetRightNode();
    }

    if (nullptr != pNode)
    {
        std::cout << ipNode->GetData() << " ";
        PrintLeftBoundaryNodes(ipNode);
    }
}

//-------------------------------------------------------------------
void BinaryTree::PrintRightBoundaryNodes(Node *ipNode)
{
    if (nullptr == ipNode)
    {
        return;
    }

    Node *pNextNode = ipNode->GetRightNode();

    if (nullptr == pNextNode)
    {
        pNextNode = ipNode->GetLeftNode();
    }

    if (nullptr != pNextNode)
    {
        std::cout << ipNode->GetData() << " ";
        PrintRightBoundaryNodes(pNextNode);
    }
}

//-------------------------------------------------------------------
void BinaryTree::PrintAllNodesAtKDistance(Node *ipNode, int inKDistance)
{
    if (nullptr == ipNode)
    {
        return;
    }

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
bool BinaryTree::PrintSibling(Node *ipNode, int inData)
{
    bool bFound(false);

    if (nullptr == ipNode)
    {
        return bFound;
    }

    Node *pNode = nullptr;
    Node *pLNode = ipNode->GetLeftNode();
    Node *pRNode = ipNode->GetRightNode();

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

//-------------------------------------------------------------------
void BinaryTree::PrintCousins(Node *ipNode, int inData, int inNodeHeight)
{
    if (nullptr == ipNode)
    {
        return;
    }

    if (0 == inNodeHeight)
    {
        std::cout << ipNode->GetData() << " ";
    }
    else
    {
        Node *pLNode = ipNode->GetLeftNode();
        Node *pRNode = ipNode->GetRightNode();

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

//-------------------------------------------------------------------
void BinaryTree::PrintAncestors(Node *ipNode, std::stack<int> &iosNodePath)
{
    if (nullptr == ipNode)
    {
        return;
    }

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
bool BinaryTree::PrintAncestor(Node *ipNode, int inData)
{
    bool bFound(false);

    if (nullptr == ipNode)
    {
        return bFound;
    }

    Node *pLNode = ipNode->GetLeftNode();
    Node *pRNode = ipNode->GetRightNode();

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
