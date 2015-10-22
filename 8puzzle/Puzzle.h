// PAULO BRUNO DE SOUSA SERAFIM
// October, 2015, Fortaleza - CE, Brasil


#ifndef PUZZLE_H
#define PUZZLE_H


#include <stdint.h>
#include <stdio.h>

#include <iostream>


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


class Puzzle
{
	public:
	
		Puzzle(unsigned int* tiles);
		~Puzzle();

		void show();
		
		void shiftUp();
		void shiftDown();
		void shiftLeft();
		void shiftRight();
		

	private:
	
		unsigned int tile[NUM_OF_TILES];

		
		unsigned int getZeroPosition();
		
		void rotateClockwise();
		void rotateCounterClockwise();
		void moveRight();
};


#endif // PUZZLE_H
