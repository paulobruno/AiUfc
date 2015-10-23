#include "Tree.h"


Tree::Tree(Node* root)
	: root(root)
{}


Tree::~Tree()
{}


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
		
		// print states		
		/*for (unsigned int i = 0; i < visitedNodes.size(); ++i)
		{
			visitedNodes[i]->show();
			printf("\n");
		}*/
	}
}


void Tree::depthSearch()
{	
	if (root)
	{
		nodes.push_back(root);
	
		while (!nodes.empty())
		{			
			nodes.back()->depthVisit(nodes, &visitedNodes);
			nodes.pop_back();
		}
		
		// print states
		/*for (unsigned int i = 0; i < visitedNodes.size(); ++i)
		{
			visitedNodes[i]->show();
			printf("\n");
		}*/
	}
}
