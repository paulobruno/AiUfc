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
        void aStarSearch();


    private:

        Node* root;

        //std::vector<Node*> visitedNodes;
        std::vector<bool> visitedNodes;

        std::vector<Node*> nodes;
        std::deque<Node*> breadthNodes;
        std::deque<Node*> aStarNodes;


        void printVisitedNodes();
};


#endif // TREE_H
