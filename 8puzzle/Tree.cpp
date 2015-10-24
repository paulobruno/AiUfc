#include "Tree.h"


Tree::Tree(Node* root)
    : root(root)
{}


Tree::~Tree()
{
    root = NULL;
}


void Tree::breadthSearch()
{
    if (root)
    {
        breadthNodes.push_back(root);

        while (!breadthNodes.empty())
        {
            // se chegou no objetivo para
            if (breadthNodes.front()->breadthVisit(&breadthNodes, &visitedNodes))
            {
                break;
            }

            breadthNodes.pop_front();
        }

        printVisitedNodes();
    }
    else
    {
        std::cout << "ERROR: no root defined\n";
    }
}


void Tree::depthSearch()
{	
    if (root)
    {
        nodes.push_back(root);

        while (!nodes.empty())
        {
            nodes.back()->depthVisit(&nodes, &visitedNodes);
        }

        printVisitedNodes();
    }
    else
    {
        std::cout << "ERROR: no root defined\n";
    }
}


void Tree::aStarSearch()
{
    if (root)
    {
        aStarNodes.push_back(root);

        while (!aStarNodes.empty())
        {
            // se chegou no objetivo para
            if (aStarNodes.front()->aStarVisit(&aStarNodes, &visitedNodes))
            {
                break;
            }

            aStarNodes.pop_front();
        }

        printVisitedNodes();
    }
    else
    {
        std::cout << "ERROR: no root defined\n";
    }
}


void Tree::printVisitedNodes()
{
    for (unsigned int i = 0; i < visitedNodes.size(); ++i)
    {
        visitedNodes[i]->show();
    }
}
