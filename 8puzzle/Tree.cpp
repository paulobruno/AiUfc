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
			breadthNodes.front()->breadthVisit(&breadthNodes);
			breadthNodes.pop_front();
		}
	}
}


void Tree::depthSearch()
{	
	if (root)
	{
		nodes.push_back(root);
	
		while (!nodes.empty())
		{
			nodes.back()->depthVisit(nodes);
			nodes.pop_back();
		}
	}
}
