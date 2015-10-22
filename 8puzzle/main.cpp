#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

#include "Puzzle.h"
#include "Node.h"
#include "Tree.h"


int main(const int argc, const char* argv[])
{
	unsigned int tiles[9] = {1, 2, 0, 4, 5, 3, 7, 8, 6};
	

	Puzzle p(tiles);
	
	p.show();
	p.shiftLeft();
	p.show();
	p.shiftUp();
	p.show();
	p.shiftLeft();
	p.show();
	p.shiftDown();
	p.show();
	/*
	
	
	Node root(NULL, 1);
	Node n2(&root, 2);
	Node n7(&root, 7);
	Node n8(&root, 8);
	Node n3(&n2, 3);
	Node n6(&n2, 6);
	Node n9(&n8, 9);
	Node n12(&n8, 12);
	Node n4(&n3, 4);
	Node n5(&n3, 5);
	Node n10(&n9, 10);
	Node n11(&n9, 11);
		
	Tree tree(&root);
	
	
	if (argc > 1)
	{
		if (!strcmp(argv[1], "depth"))
		{
			tree.depthSearch();
		}
		else if (!strcmp(argv[1], "breadth"))
		{
			tree.breadthSearch();
		}
		else
		{
			std::cout << "erro: argumento invalido, use 'breadth' ou 'depth'\n";
		}
	}
	else
	{
		std::cout << "erro: argumento em branco use 'breadth' ou 'depth'\n";
	}
*/

	return EXIT_SUCCESS;
}
