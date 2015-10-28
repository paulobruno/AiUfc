/*
 * 344083 ITALO PEREIRA DE SOUSA
 * 354086 PAULO BRUNO DE SOUSA SERAFIM
 * 333491 RAPHAELL DYEGO CRUZ VAZ
 *
 * October, 2015, Fortaleza - CE, Brasil
 */


#ifndef TREE_H
#define TREE_H

#include <vector>
#include <deque>
#include <algorithm>

#include "Node.h"


// template used to sort the A star nodes deque
// but can be used to sort every container of pointers
template<class T>
struct ptr_comparison
{
   bool operator()(T* a, T* b) { return *a < *b; }
};


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

        std::vector<bool> visitedNodes;

        std::vector<Node*> depthNodes;
        std::deque<Node*> breadthNodes;
        std::deque<Node*> aStarNodes;


        // print one of the nodes vector/deque, used for debug
        void printNodes();
};


#endif // TREE_H
