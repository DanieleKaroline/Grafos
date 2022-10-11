#ifndef GRAFO_H
#define GRAFO_H
#include "aresta.h"

typedef struct grafo Grafo;

Grafo GRAFOconstroi(int num_vertices);

int GRAFOnum_arestas(Grafo *g);

void GRAFOinsere_aresta(Grafo *g, Aresta e);

void GRAFOremove_aresta(Grafo *g, Aresta e);

int GRAFOgrau_maximo(Grafo *g);

void GRAFOimprime(Grafo *g);

void GRAFOdestroi(Grafo *g);

#endif /* GRAFO_H */
