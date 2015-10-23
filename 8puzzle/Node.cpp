#include "Node.h"


Node::Node(unsigned int* tiles)
{	
	if (tiles)
	{
		for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
		{
			tile[i] = *(tiles+i);
		}
		
		// verifica se contem numeros de 0a8
		unsigned sum = 0;
		
		for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
		{
			sum += tile[i];
		}
		
		if (sum != 36)
		{
			std::cout << "Valores de estado incorretos, possivelmente ha valores repetidos.\n";
		}
		
			
		buildStateNumber();
	}
	else
	{
		std::cout << "Valores do estado nao especificados.\n";
	}
	
	height = 0;
}


Node::Node(const Node& n)
{	
	for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
	{
		tile[i] = n.tile[i];
	}
	
	buildStateNumber();
}


Node::~Node()
{
	for (unsigned int i = 0; i < child.size(); ++i)
	{
		delete child[i];
	}
	
	child.clear();
}


// returns true if this node or a descendent is the goal
bool Node::depthVisit(std::vector<Node*> vector, std::vector<Node*>* visitedNodes)
{
	visitedNodes->push_back(this);
	show();		
	
	if (gameWon())
	{		
		return true;
	}
	
	/*
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
	}*/
	
	vector.pop_back();
	
	return false;
}


// returns true if this node is the goal
bool Node::breadthVisit(std::deque<Node*>* deque, std::vector<Node*>* visitedNodes)
{
	visitedNodes->push_back(this);
	show();

		
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
			n->setHeight(height+1);
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
			n->setHeight(height+1);
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
			n->setHeight(height+1);
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
			n->setHeight(height+1);
		}
		else
		{
			delete n;
		}
	}
	
	
	return false;
}


bool Node::notVisited(std::vector<Node*>* visitedNodes)
{
	for (unsigned int i = 0; i < visitedNodes->size(); ++i)
	{
		if (this == visitedNodes->at(i))
		{
			return false;
		}
	}
	
	return true;
}


void Node::show()
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
		
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	
	fclose(fp);
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
    static unsigned results[NUM_OF_TILES + 1] = {1};


    if (results[n])
    {
        return results[n];
    }

    return (results[n] = n * factorial(n - 1));
}
