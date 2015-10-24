#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

//#include "Puzzle.h"
#include "Node.h"
#include "Tree.h"


int main(const int argc, const char* argv[])
{
	unsigned int tiles[9] = {1, 2, 0, 4, 5, 3, 7, 8, 6};
//	unsigned int tiles[9] = {0, 1, 3, 4, 2, 5, 7, 8, 6};

	Node root(tiles);
	
	Tree tree(&root);
        //tree.breadthSearch();
        tree.depthSearch();


	return EXIT_SUCCESS;
}
