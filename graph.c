#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


struct elemLista {
    int viz;
    struct elemLista *proximo;
};
typedef struct elemLista ElemLista;

struct grafo{
    int num_v;
    int num_a;
    ElemLista **lista_adj;
};

typedef struct grafo Grafo;

Grafo GRAFOconstroi(int num_v){
    Grafo *g;

    g = malloc(sizeof(*g));

    g->num_v = num_v;
    g->num_a = 0;

    g->lista_adj = malloc(num_v * sizeof(*(g->lista_adj)));

    for (int i = 0; i < num_v; i++)
    {
        g->lista_adj[i] = NULL;
    }

    return g;
}

void GRAFOdestroi(Grafo *g){
    for (int i = 0; i < g->num_v; i++)
    {
        free(g->lista_adj[i]);
    }
    
    free(g->lista_adj);
    free(g);
}

