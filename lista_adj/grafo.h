#ifndef GRAFO_H

#define GRAFO_H

#include "aresta.h"

typedef struct grafo Grafo;

Grafo *GRAFOconstroi(int N);//ok

void GRAFOinsere_aresta(Grafo *g, Aresta a);//ok

void GRAFOremove_aresta(Grafo *g, Aresta a);

int GRAFOget_num_aresta(Grafo *g);//ok

int GRAFOget_num_vertice(Grafo *g);//ok

void GRAFOimprime(Grafo *g);//ok

int GRAFOgrau_maximo(Grafo *g);

void GRAFOdestroi(Grafo *g);//ok

#endif /* GRAFO_H */
