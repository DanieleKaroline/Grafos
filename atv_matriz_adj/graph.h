#ifndef GRAPH_H
#define GRAPH_H
#include <stdbool.h>
#include "aresta.h"

typedef struct graph Graph;

Graph *GRAPHconstroi(int num_v);

void GRAPHinsere_aresta(Graph *g, Aresta a);

void GRAPHremove_aresta(Graph *g, Aresta a);

int GRAPHget_num_aresta(Graph *g);

int GRAPHget_num_vertice(Graph *g);

void GRAPHimprime(Graph *g);

void GRAPHdestroi(Graph *g);

#endif /* GRAPH_H */
