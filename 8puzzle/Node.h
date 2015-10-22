// PAULO BRUNO DE SOUSA SERAFIM
// October, 2015, Fortaleza - CE, Brasil


#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <deque>


class Node
{
	public:
	
		Node(Node* parent, int value);
		~Node();

		void depthVisit(std::vector<Node*> vector);
		void breadthVisit(std::deque<Node*>* deque);

		void addChild(Node* c);
		
		int getValue() {return value;}


	private:
	
		int value;
		
		Node* parent;
		std::vector<Node*> child;
};


#endif // NODE_H
