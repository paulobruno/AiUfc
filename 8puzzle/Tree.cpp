/*
 * 344083 ITALO PEREIRA DE SOUSA
 * 354086 PAULO BRUNO DE SOUSA SERAFIM
 * 333491 RAPHAELL DYEGO CRUZ VAZ
 *
 * October, 2015, Fortaleza - CE, Brasil
 */


#include "Tree.h"


Tree::Tree(Node* root)
    : root(root)
{
    // 9! = 362880, number of combinations for a 0..8 set, the 8 puzzle
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
            if (breadthNodes.front()->breadthVisit(&breadthNodes, &visitedNodes))
            {
                break;
            }

            breadthNodes.pop_front();
        }
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
        depthNodes.push_back(root);


        while (!depthNodes.empty())
        {
            depthNodes.back()->depthVisit(&depthNodes, &visitedNodes);
        }
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
            if (aStarNodes.front()->aStarVisit(&aStarNodes, &visitedNodes))
            {
                break;
            }


            //printNodes();
            aStarNodes.pop_front();
            std::sort(aStarNodes.begin(), aStarNodes.end(), ptr_comparison<Node>());
        }
    }
    else
    {
        std::cout << "ERROR: no root defined\n";
    }
}


void Tree::printNodes()
{
    // print the content of xNodes, where x = depth | breadth | aStar
    for (unsigned int i = 0; i < aStarNodes.size(); ++i)
    {
        aStarNodes[i]->showScreen();
    }

    printf("\n\n");
}
