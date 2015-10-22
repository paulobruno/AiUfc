// PAULO BRUNO DE SOUSA SERAFIM
// October, 2015, Fortaleza - CE, Brasil


#ifndef TREE_H
#define TREE_H

#include <vector>
#include <deque>

#include "Node.h"


class Tree
{
	public:
	
		Tree(Node* root);
		~Tree();

		void breadthSearch();
		void depthSearch();
		

	private:
	
		Node* root;
		
		std::vector<Node*> nodes;
		std::deque<Node*> breadthNodes;
};


#endif // TREE_H
