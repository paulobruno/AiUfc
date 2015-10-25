#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

//#include "Puzzle.h"
#include "Node.h"
#include "Tree.h"


#include <sys/time.h>

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}


int main(const int argc, const char* argv[])
{
	//unsigned int tiles[9] = {1, 2, 0, 4, 5, 3, 7, 8, 6};
        //unsigned int tiles[9] = {0, 1, 3, 4, 2, 5, 7, 8, 6};
        //unsigned int tiles[9] = {4, 0, 8, 2, 3, 5, 1, 6, 7};
        //unsigned int tiles[9] = {8, 5, 2, 3, 6, 0, 1, 7, 4};
        unsigned int tiles[9] = {1, 2, 3, 4, 5, 6, 8, 0, 7};

	Node root(tiles);
	
	
	
    timestamp_t inicio, fim;
	inicio = get_timestamp();
	
	
	Tree tree(&root);
        tree.breadthSearch();
        //tree.depthSearch();


    fim = get_timestamp();	
	
	std::cout << "tempo: " << (fim - inicio)/1000.0L << " milissegundos.\n";
	

	return EXIT_SUCCESS;
}
