/*
 * 344083 ITALO PEREIRA DE SOUSA
 * 354086 PAULO BRUNO DE SOUSA SERAFIM
 * 333491 RAPHAELL DYEGO CRUZ VAZ
 *
 * October, 2015, Fortaleza - CE, Brasil
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include <iostream>

#include "Node.h"
#include "Tree.h"


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
        //unsigned int tiles[9] = {1, 8, 2, 0, 4, 3, 7, 6, 5};
        //unsigned int tiles[9] = {6, 5, 7, 4, 3, 8, 0, 1, 2};
        //unsigned int tiles[9] = {1, 2, 3, 4, 5, 6, 8, 0, 7}; // invalido
        //unsigned tiles[9] = {8, 1, 2, 0, 4, 3, 7, 6, 5}; // invalido
        unsigned int tiles[9] = {1, 0, 6, 3, 2, 5, 7, 8, 4}; // a* dist = 3, a* tile = 8, b = 30, d = 54


        Node root;


        if (root.initialize(0, tiles))
        {
            timestamp_t inicio, fim;
            inicio = get_timestamp();


            Tree tree(&root);

            //tree.depthSearch();
            tree.breadthSearch();
            //tree.aStarSearch();


            fim = get_timestamp();

            std::cout << "tempo: " << (fim - inicio)/1000.0L << " milissegundos.\n";
        }
        else
        {
            std::cout << "Programa abortado.\n";
        }


	return EXIT_SUCCESS;
}
