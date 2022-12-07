#ifndef GRAFO_H

#define GRAFO_H

#include <stdbool.h>
#include "aresta.h"

typedef struct grafo Grafo;

Grafo *GRAFOconstroi(int N);

void GRAFOinsere_aresta(Grafo *g, Aresta a);

void GRAFOremove_aresta(Grafo *g, Aresta a);

int GRAFOget_num_aresta(Grafo *g);

int GRAFOget_num_vertice(Grafo *g);

void GRAFOimprime(Grafo *g);

bool GRAFOcaminho(Grafo *g, int v, int w);

void GRAFOdestroi(Grafo *g);

void GRAFOimprime_distancia(Grafo *g, int x);

#endif /* GRAFO_H */
