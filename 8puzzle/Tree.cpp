#include "Tree.h"


Tree::Tree(Node* root)
    : root(root)
{
    visitedNodes.reserve(362880);

    for (unsigned i = 0; i < 362880; ++i)
    {
        visitedNodes.push_back(false);
    }
}


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
			//aStarNodes.front()->showScreen();
			
            // se chegou no objetivo para
            if (aStarNodes.front()->aStarVisit(&aStarNodes, &visitedNodes))
            {
                break;
            }

                //printVisitedNodes();
            aStarNodes.pop_front();
                        std::sort(aStarNodes.begin(), aStarNodes.end(), ptr_comparison<Node>());
        }

        //printVisitedNodes();
    }
    else
    {
        std::cout << "ERROR: no root defined\n";
    }
}


void Tree::printVisitedNodes()
{
    for (unsigned int i = 0; i < aStarNodes.size(); ++i)
    {
        aStarNodes[i]->showScreen();
    }
        printf("\n\n");
}
