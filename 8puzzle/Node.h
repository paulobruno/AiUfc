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

		bool depthVisit(std::vector<Node*> vector, std::vector<Node*>* visitedNodes);
		bool breadthVisit(std::deque<Node*>* deque, std::vector<Node*>* visitedNodes);

		void addChild(Node* c);
		
		int getValue() {return value;}


	private:
	
		int value;
		
		Node* parent;
		std::vector<Node*> child;


		bool notVisited(std::vector<Node*>* visitedNodes);
		bool gameWon();
};


#endif // NODE_H
