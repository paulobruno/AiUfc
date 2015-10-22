#include "Node.h"


Node::Node(Node* parent, int value)
	: parent(parent)
	, value(value)
{
	if (parent)
	{
		parent->addChild(this);
	}
}


Node::~Node()
{}


void Node::addChild(Node* c)
{
	child.push_back(c);
}


// returns true if this node or a descendent is the goal
bool Node::depthVisit(std::vector<Node*> vector, std::vector<Node*>* visitedNodes)
{
	std::cout << value << '\n';
	
	visitedNodes->push_back(this);
			
	
	if (gameWon())
	{		
		return true;
	}
	
	
	for (unsigned int i = 0; i < child.size(); ++i)
	{		
		if (child[i]->notVisited(visitedNodes))
		{		
			vector.push_back(child[i]);
			
			// if this child is the goal stop
			if (vector.back()->depthVisit(vector, visitedNodes))
			{
				return true;
			}
		}
	}
	
	vector.pop_back();
	
	return false;
}


// returns true if this node is the goal
bool Node::breadthVisit(std::deque<Node*>* deque, std::vector<Node*>* visitedNodes)
{
	std::cout << value << '\n';
	
	visitedNodes->push_back(this);

		
	if (gameWon())
	{
		return true;
	}
	
	
	for (unsigned int i = 0; i < child.size(); ++i)
	{	
		if (child[i]->notVisited(visitedNodes))
		{		
			deque->push_back(child[i]);
		}
	}
	
	return false;
}


bool Node::notVisited(std::vector<Node*>* visitedNodes)
{
	for (unsigned int i = 0; i < visitedNodes->size(); ++i)
	{
		if (value == visitedNodes->at(i)->getValue())
		{
			return false;
		}
	}
	
	return true;
}


bool Node::gameWon()
{
	if (value == 9)
	{
		return true;
	}
	
	return false;
}
