#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


struct graph {
    int num_v;
    int num_a;
    int **matriz;
};

Graph *GRAPHconstroi(int num_v) {
    Graph *g;

    g = malloc(sizeof(*g));

    g->num_v = num_v;
    g->num_a = 0;

    g->matriz = malloc(num_v * sizeof(int*));

    for (int i = 0; i < num_v; i++)
    {
        g->matriz[i] = malloc(num_v * sizeof(int));
    }
    
    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            g->matriz[i][j] = 0;
        }
    }

    return g;
}

void GRAPHdestroi(Graph *g) {
    
    for (int i = 0; i < g->num_v; i++)
    {
        free(g->matriz[i]);
    }
    
    free(g->matriz);
    free(g);
}

void GRAPHinsere_aresta(Graph *g, Aresta a){
    if(g->matriz[a.v1][a.v2] == 0 && a.v1 != a.v2){
        g->matriz[a.v1][a.v2] = 1;
        g->matriz[a.v2][a.v1] = 1;
        g->num_a++;
    }
    
}
void GRAPHremove_aresta(Graph *g, Aresta a){
    if(g->matriz[a.v1][a.v2] == 1){
        g->matriz[a.v1][a.v2] = 0;
        g->matriz[a.v2][a.v1] = 0;
        g->num_a--;
    }
}
int GRAPHget_num_aresta(Graph *g){
    return g->num_a;
}

int GRAPHget_num_vertice(Graph *g){
    return g->num_v;
}
void GRAPHimprime(Graph *g){
    for (int i = 0; i < g->num_v; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < g->num_v; j++){
           if(g->matriz[i][j] == 1){
            printf(" %d", j);
            }
        }
        printf("\n");
    }
   
}