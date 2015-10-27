// PAULO BRUNO DE SOUSA SERAFIM
// October, 2015, Fortaleza - CE, Brasil


#ifndef NODE_H
#define NODE_H


#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <deque>
#include <queue>


#define NUM_OF_TILES 9


enum POSITIONS
{
    TOP_LEFT = 0,
    TOP_CENTER = 1,
    TOP_RIGHT = 2,

    MIDDLE_LEFT = 3,
    MIDDLE_CENTER = 4,
    MIDDLE_RIGHT = 5,

    BOTTOM_LEFT = 6,
    BOTTOM_CENTER = 7,
    BOTTOM_RIGHT = 8
};


class Node
{
    public:

        Node();
        Node(const Node& n);
        ~Node();

        bool initialize(unsigned* tiles);

        bool depthVisit(std::vector<Node*>* vector, std::vector<bool>* visitedNodes);
        bool breadthVisit(std::deque<Node*>* deque, std::vector<bool>* visitedNodes);
        bool aStarVisit(std::deque<Node*>* deque, std::vector<bool>* visitedNodes);
//        bool aStarVisit(std::priority_queue<Node*, std::deque<Node*>, NodeCompare>* queue, std::vector<bool>* visitedNodes);


        void show();
        void showScreen();

        Node* shiftUp();
        Node* shiftDown();
        Node* shiftLeft();
        Node* shiftRight();

        unsigned getStateNumber() {return stateNumber;}

        unsigned getHeight() {return height;}
        void setHeight(unsigned h) {height = h;}
        unsigned getCost() const {return cost;}
        void setCost(unsigned c) {cost = c;}


        Node& operator= (const Node& n2)
        {
            if (this != &n2)
            {
                tile[TOP_LEFT]   = n2.tile[TOP_LEFT];
                tile[TOP_CENTER] = n2.tile[TOP_CENTER];
                tile[TOP_RIGHT]  = n2.tile[TOP_RIGHT];

                tile[MIDDLE_LEFT]   = n2.tile[MIDDLE_LEFT];
                tile[MIDDLE_CENTER] = n2.tile[MIDDLE_CENTER];
                tile[MIDDLE_RIGHT]  = n2.tile[MIDDLE_RIGHT];

                tile[BOTTOM_LEFT]   = n2.tile[BOTTOM_LEFT];
                tile[BOTTOM_CENTER] = n2.tile[BOTTOM_CENTER];
                tile[BOTTOM_RIGHT]  = n2.tile[BOTTOM_RIGHT];

                buildStateNumber();
            }

            return *this;
        }

        bool operator!= (const Node& n2)
        {
            if (this != &n2)
            {
                if (stateNumber != n2.stateNumber)
                {
                    return true;
                }
            }

            return false;
        }

        bool operator== (const Node& n2)
        {
            if (this != &n2)
            {
                if (stateNumber == n2.stateNumber)
                {
                    return true;
                }
            }

            return false;
        }

        bool operator< (const Node& n2)
        {
                return (this->getCost() < n2.getCost());
        }


    private:
	
        unsigned int tile[NUM_OF_TILES];
        unsigned int stateNumber;
        unsigned height;
        unsigned cost;

        std::vector<Node*> child;


        unsigned int getZeroPosition();

        void rotateClockwise();
        void rotateCounterClockwise();
        void moveRight();

        bool gameWon();

        bool notVisited(std::vector<bool>* visitedNodes);

        void buildStateNumber();
        unsigned buildNumber(unsigned* A, unsigned n, unsigned lessers[]);
        unsigned factorial(unsigned n);
        bool isNotSolvable();
        
		unsigned int distanceToGoal();
		unsigned int tilesOutOfPlace();
};

		
#endif // NODE_H
