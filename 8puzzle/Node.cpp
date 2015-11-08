/*
 * 344083 ITALO PEREIRA DE SOUSA
 * 354086 PAULO BRUNO DE SOUSA SERAFIM
 * 333491 RAPHAELL DYEGO CRUZ VAZ
 *
 * October, 2015, Fortaleza - CE, Brasil
 */


#include "Node.h"


Node::Node()
{}


Node::Node(const Node& n)
{	
    for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
    {
        tile[i] = n.tile[i];
    }

    buildStateNumber();
    height = n.height;
    //cost = height + distanceToGoal();
    cost = height + tilesOutOfPlace();
}


Node::~Node()
{
    for (unsigned int i = 0; i < child.size(); ++i)
    {
        delete child[i];
    }

    child.clear();
}


bool Node::initialize(unsigned h, unsigned* tiles)
{
    if (tiles)
    {
        // verifica se contem valores > 8 ou < 0
        for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
        {
            if ((*(tiles+i) > NUM_OF_TILES-1) || (*(tiles+i) < 0))
            {
                std::cout << "Estado incorreto, numero maior ou menor que o intervalo permitido: [0.." << NUM_OF_TILES-1 << "]\n";
                return false;
            }

            tile[i] = *(tiles+i);
        }


        // verifica se contem numeros de 0 a 8
        bool verification[NUM_OF_TILES] = {0};

        for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
        {
            if (verification[tile[i]])
            {
                std::cout << "Valores de estado incorretos, ha valores repetidos: " << tile[i] << ".\n";
                return false;
            }

            verification[tile[i]] = true;
        }


        if (isNotSolvable())
        {
            std::cout << "Estado inicial incorreto: nao resolvivel\n";
            return false;
        }


        buildStateNumber();
        height = h;
        //cost = height + distanceToGoal();
        cost = height + tilesOutOfPlace();


        return true;
    }


    std::cout << "Valores do estado nao especificados.\n";

    return false;
}


// returns true if this node or a descendent is the goal
bool Node::depthVisit(std::vector<Node*>* vector, std::vector<bool>* visitedNodes)
{
    visitedNodes->at(stateNumber) = true;
    //showFile();


    if (gameWon())
    {
        vector->pop_back();
        return true;
    }



    if (Node* n = shiftLeft())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            vector->push_back(n);
            //n->setHeight(height+1);

            // if this child or a descendant is the goal stop returns true
            if (vector->back()->depthVisit(vector, visitedNodes))
            {
                vector->pop_back();
                return true;
            }
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftUp())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            vector->push_back(n);
            //n->setHeight(height+1);

            // if this child or a descendant is the goal stop returns true
            if (vector->back()->depthVisit(vector, visitedNodes))
            {
                vector->pop_back();
                return true;
            }
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftRight())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            vector->push_back(n);
            //n->setHeight(height+1);

            // if this child or a descendant is the goal stop returns true
            if (vector->back()->depthVisit(vector, visitedNodes))
            {
                vector->pop_back();
                return true;
            }
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftDown())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            vector->push_back(n);
            //n->setHeight(height+1);

            // if this child or a descendant is the goal stop returns true
            if (vector->back()->depthVisit(vector, visitedNodes))
            {
                vector->pop_back();
                return true;
            }
        }
        else
        {
            delete n;
        }
    }


    vector->pop_back();
    return false;
}


bool Node::breadthVisit(std::deque<Node*>* deque, std::vector<bool>* visitedNodes)
{
    visitedNodes->at(stateNumber) = true;
    showFile();


    if (gameWon())
    {
        return true;
    }


    if (Node* n = shiftLeft())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            deque->push_back(n);
            //n->setHeight(height+1);
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftUp())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            deque->push_back(n);
            //n->setHeight(height+1);
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftRight())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            deque->push_back(n);
            //n->setHeight(height+1);
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftDown())
    {
        if (n->notVisited(visitedNodes))
        {
            child.push_back(n);
            deque->push_back(n);
            //n->setHeight(height+1);
        }
        else
        {
            delete n;
        }
    }


    return false;
}


bool Node::aStarVisit(std::deque<Node*>* deque, std::vector<bool>* visitedNodes)
{
    visitedNodes->at(stateNumber) = true;
    showFile();


    if (gameWon())
    {
        return true;
    }
    

    if (Node* n = shiftLeft())
    {
        if (n->notVisited(visitedNodes))
        {
            //n->setHeight(height+1);
            deque->push_back(n);
            child.push_back(n);
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftUp())
    {
        if (n->notVisited(visitedNodes))
        {
            //n->setHeight(height+1);
            deque->push_back(n);
            child.push_back(n);
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftRight())
    {
        if (n->notVisited(visitedNodes))
        {
            //n->setHeight(height+1);
            deque->push_back(n);
            child.push_back(n);
        }
        else
        {
            delete n;
        }
    }

    if (Node* n = shiftDown())
    {
        if (n->notVisited(visitedNodes))
        {
            //n->setHeight(height+1);
            deque->push_back(n);
            child.push_back(n);
        }
        else
        {
            delete n;
        }
    }
	
	
    return false;
}


bool Node::notVisited(std::vector<bool>* visitedNodes)
{
    if (visitedNodes->at(stateNumber))
    {
        return false;
    }

    return true;
}


void Node::showFile()
{
    FILE *fp;

    fp = fopen("saida.txt", "a");

    for (int i = 0; i < 3; ++i)
    {
        for (unsigned h = 0; h < height; ++h)
        {
            fprintf(fp,"\t");
        }

        for (int j = 0; j < 3; ++j)
        {
            fprintf(fp,"%d ", tile[i*3+j]);
        }

        fprintf(fp,"  %u+%u=%u \n",distanceToGoal(), height,  cost);
    }

    fprintf(fp,"\n");

    fclose(fp);
}


void Node::showScreen()
{
    for (int i = 0; i < 3; ++i)
    {
        for (unsigned h = 0; h < height; ++h)
        {
            printf("\t");
        }

        for (int j = 0; j < 3; ++j)
        {
            printf("%d ", tile[i*3+j]);
        }

        printf(" %u\n", cost);
    }

    printf("\n");
}


void Node::update()
{
    ++height;
    //cost = height + distanceToGoal();
    cost = height + tilesOutOfPlace();
}


Node* Node::shiftUp()
{
    // if zero is at bottom return null
    if (tile[BOTTOM_LEFT] * tile[BOTTOM_CENTER] * tile[BOTTOM_RIGHT])
    {
        Node n(*this);


        n.rotateClockwise();
        n.moveRight();
        n.rotateCounterClockwise();

        n.update();

        return new Node(n);
    }


    return NULL;
}


Node* Node::shiftDown()
{
    // if zero is at top return null
    if (tile[TOP_LEFT] * tile[TOP_CENTER] * tile[TOP_RIGHT])
    {
        Node n(*this);


        n.rotateCounterClockwise();
        n.moveRight();
        n.rotateClockwise();

        n.update();

        return new Node(n);
    }


    return NULL;
}


Node* Node::shiftLeft()
{
    // if zero is at right return null
    if (tile[TOP_RIGHT] * tile[MIDDLE_RIGHT] * tile[BOTTOM_RIGHT])
    {
        Node n(*this);


        n.rotateClockwise();
        n.rotateClockwise();
        n.moveRight();
        n.rotateCounterClockwise();
        n.rotateCounterClockwise();

        n.update();

        return new Node(n);
    }


    return NULL;
}


Node* Node::shiftRight()
{
    // if zero is at left return null
    if (tile[TOP_LEFT] * tile[MIDDLE_LEFT] * tile[BOTTOM_LEFT])
    {
        Node n(*this);


        n.moveRight();

        n.update();

        return new Node(n);
    }


    return NULL;
}


void Node::rotateClockwise()
{
    unsigned int aux = 0;

    aux = tile[TOP_LEFT];
    tile[TOP_LEFT] = tile[BOTTOM_LEFT];
    tile[BOTTOM_LEFT] = tile[BOTTOM_RIGHT];
    tile[BOTTOM_RIGHT] = tile[TOP_RIGHT];
    tile[TOP_RIGHT] = aux;

    aux = tile[MIDDLE_LEFT];
    tile[MIDDLE_LEFT] = tile[BOTTOM_CENTER];
    tile[BOTTOM_CENTER] = tile[MIDDLE_RIGHT];
    tile[MIDDLE_RIGHT] = tile[TOP_CENTER];
    tile[TOP_CENTER] = aux;
}


void Node::rotateCounterClockwise()
{
    unsigned int aux = 0;

    aux = tile[TOP_LEFT];
    tile[TOP_LEFT] = tile[TOP_RIGHT];
    tile[TOP_RIGHT] = tile[BOTTOM_RIGHT];
    tile[BOTTOM_RIGHT] = tile[BOTTOM_LEFT];
    tile[BOTTOM_LEFT] = aux;

    aux = tile[MIDDLE_LEFT];
    tile[MIDDLE_LEFT] = tile[TOP_CENTER];
    tile[TOP_CENTER] = tile[MIDDLE_RIGHT];
    tile[MIDDLE_RIGHT] = tile[BOTTOM_CENTER];
    tile[BOTTOM_CENTER] = aux;
}


unsigned int Node::getZeroPosition()
{
    for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
    {
        if (tile[i] == 0)
        {
            return i;
        }
    }

    std::cout << "ERROR: 0 not found, returning 0 by default\n";

    return 0;
}	


void Node::moveRight()
{
    unsigned int zeroPosition = getZeroPosition();

    switch (zeroPosition)
    {
        case TOP_CENTER:
            tile[TOP_CENTER] = tile[TOP_LEFT];
            tile[TOP_LEFT] = 0;
        break;

        case TOP_RIGHT:
            tile[TOP_RIGHT] = tile[TOP_CENTER];
            tile[TOP_CENTER] = 0;
        break;

        case MIDDLE_CENTER:
            tile[MIDDLE_CENTER] = tile[MIDDLE_LEFT];
            tile[MIDDLE_LEFT] = 0;
        break;

        case MIDDLE_RIGHT:
            tile[MIDDLE_RIGHT] = tile[MIDDLE_CENTER];
            tile[MIDDLE_CENTER] = 0;
        break;

        case BOTTOM_CENTER:
            tile[BOTTOM_CENTER] = tile[BOTTOM_LEFT];
            tile[BOTTOM_LEFT] = 0;
        break;

        case BOTTOM_RIGHT:
            tile[BOTTOM_RIGHT] = tile[BOTTOM_CENTER];
            tile[BOTTOM_CENTER] = 0;
        break;

        default:
        break;
    }
}


bool Node::gameWon()
{
    if (tile[TOP_LEFT] != 1)
    {
        return false;
    }

    if (tile[TOP_CENTER] != 2)
    {
        return false;
    }

    if (tile[TOP_RIGHT] != 3)
    {
        return false;
    }

    if (tile[MIDDLE_LEFT] != 4)
    {
        return false;
    }

    if (tile[MIDDLE_CENTER] != 5)
    {
        return false;
    }

    if (tile[MIDDLE_RIGHT] != 6)
    {
        return false;
    }

    if (tile[BOTTOM_LEFT] != 7)
    {
        return false;
    }

    if (tile[BOTTOM_CENTER] != 8)
    {
        return false;
    }

    if (tile[BOTTOM_RIGHT] != 0)
    {
        return false;
    }

    return true;
}


void Node::buildStateNumber()
{
    unsigned lessers[NUM_OF_TILES];


    for (unsigned i = 0; i < NUM_OF_TILES; ++i)
    {
        lessers[i] = i;
    }


    stateNumber = buildNumber(tile, NUM_OF_TILES, lessers);
}


unsigned Node::buildNumber(unsigned* A, unsigned n, unsigned lessers[])
{
    if (!n)
    {
        return 0;
    }


    unsigned i;


    for (i = *A + 1; i < NUM_OF_TILES; ++i)
    {
        --lessers[i];
    }


    return ((lessers[*A] * factorial(n - 1)) + buildNumber((A + 1), (n - 1), lessers));
}


unsigned Node::factorial(unsigned n)
{
    if (n == 0)
    {
        return 1;
    }


    return (n * factorial(n - 1));
}


bool Node::isNotSolvable()
{	
    unsigned int count = 0;


    for (unsigned int i = 0; i < NUM_OF_TILES-1 ; ++i)
    {
        for (unsigned int j = i + 1; j < NUM_OF_TILES; ++j)
        {
            if ((tile[i] != 0) && (tile[j] != 0) && (tile[i] > tile[j]))
            {
                ++count;
            }
        }
    }


    if (!(count % 2))
    {
        // is solvable
        return false;
    }
    else
    {
        // not solvable
        return true;
    }
}


unsigned int Node::distanceToGoal()
{
    int status[9][9] = 
    {
        {0, 1, 2, 1, 2, 3, 2, 3, 4},
        {1, 0, 1, 2, 1, 2, 3, 2, 3},
        {2, 1, 0, 3, 2, 1, 4, 3, 2},
        {1, 2, 3, 0, 1, 2, 1, 2, 3},
        {2, 1, 2, 1, 0, 1, 2, 1, 2},
        {3, 2, 1, 2, 1, 0, 3, 2, 1},
        {2, 3, 4, 1, 2, 3, 0, 1, 2},
        {3, 2, 3, 2, 1, 2, 1, 0, 1},
        {4, 3, 2, 3, 2, 1, 2, 1, 0}
    };
    
    
    unsigned int count = 0;
    
    
    for (unsigned int i = 0; i < NUM_OF_TILES-1; ++i)
    {
        if (tile[i] != i+1)
        {
            if (tile[i] == 0)
            {
                count = count + status[NUM_OF_TILES-1][i];
            }
            else
            {
                count = count + status[tile[i]-1][i];
            }
        }
    }
    
    if (tile[NUM_OF_TILES-1] != 0)
    {
    	count = count + status[tile[NUM_OF_TILES-1]-1][NUM_OF_TILES-1];
    }
    
    
    return count;
}


unsigned int Node::tilesOutOfPlace()
{
    unsigned int count = 0;
    
    
    for (unsigned int i = 0; i < NUM_OF_TILES-1; ++i)
    {
        if (tile[i] != i+1)
        {
            ++count;
        }
    }
    
    if (tile[NUM_OF_TILES-1] != 0)
    {
        ++count;
    }


    return count;
}

