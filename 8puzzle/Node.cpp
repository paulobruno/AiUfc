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


void Node::depthVisit(std::vector<Node*> vector)
{
	std::cout << value << '\n';
	
	for (unsigned int i = 0; i < child.size(); ++i)
	{
		vector.push_back(child[i]);
		vector.back()->depthVisit(vector);
	}
	
	vector.pop_back();
}


void Node::breadthVisit(std::deque<Node*>* deque)
{
	std::cout << value << '\n';
	
	for (unsigned int i = 0; i < child.size(); ++i)
	{
		deque->push_back(child[i]);
	}
}
