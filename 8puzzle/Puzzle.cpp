#include "Puzzle.h"


Puzzle::Puzzle(unsigned int* tiles)
{
	for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
	{
		tile[i] = *(tiles+i);
	}
}


Puzzle::~Puzzle()
{}


void Puzzle::show()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", tile[i*3+j]);
		}
		
		printf("\n");
	}
	
	printf("\n");
}


void Puzzle::shiftUp()
{
	// if zero is at bottom do nothing	
	if (tile[BOTTOM_LEFT] * tile[BOTTOM_CENTER] * tile[BOTTOM_RIGHT])
	{
		rotateClockwise();

		moveRight();

		rotateCounterClockwise();
	}	
}


void Puzzle::shiftDown()
{
	// if zero is at top do nothing
	if (tile[TOP_LEFT] * tile[TOP_CENTER] * tile[TOP_RIGHT])
	{
		rotateCounterClockwise();
	
		moveRight();

		rotateClockwise();	
	}
}


void Puzzle::shiftLeft()
{
	// if zero is at right do nothing
	if (tile[TOP_RIGHT] * tile[MIDDLE_RIGHT] * tile[BOTTOM_RIGHT])
	{
		rotateClockwise();
		rotateClockwise();
	
		moveRight();

		rotateCounterClockwise();
		rotateCounterClockwise();
	}
}


void Puzzle::shiftRight()
{
	// if zero is at left do nothing
	if (tile[TOP_LEFT] * tile[MIDDLE_LEFT] * tile[BOTTOM_LEFT])
	{
		moveRight();
	}
}


void Puzzle::rotateClockwise()
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


void Puzzle::rotateCounterClockwise()
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


unsigned int Puzzle::getZeroPosition()
{
	for (unsigned int i = 0; i < NUM_OF_TILES; ++i)
	{
		if (tile[i] == 0)
		{
			return i;
		}
	}
}	


void Puzzle::moveRight()
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


bool Puzzle::gameWon()
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
