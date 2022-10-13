#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct elemLista {
    int viz;
    struct elemLista *prox;
};
typedef struct elemLista ElemLista;

struct grafo{
    int num_v;
    int num_a;
    ElemLista **lista_adj;
};

typedef struct grafo Grafo;




Grafo *GRAFOconstroi(int num_v){
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



ElemLista* NOconstroi(int v)
{
    ElemLista* no = (struct ElemLista *)malloc(sizeof(no));
    no->viz = v;    
    no->prox = NULL;
    return no;
}



void GRAFOinsere_aresta(Grafo *g, Aresta e){
    if(e.v1 != e.v2){
        ElemLista* no = NOconstroi(e.v2);
        no->prox = g->lista_adj[e.v1];
        g->lista_adj[e.v1] = no;
 
        no = NOconstroi(e.v1);
        no->prox = g->lista_adj[e.v2];
        g->lista_adj[e.v2] = no;
    }
    else{
        printf("Lacos nao sao permitidos!\n");
        return;
    }
   g->num_a++;
}



int GRAFOnum_arestas(Grafo *g){
    return g->num_a;
}




void GRAFOremove_aresta(Grafo *g, Aresta e){
    for (int i = 0; i < g->num_v; i++)
    {
        free(g->lista_adj[i]);
    }
    free(g->lista_adj);
    free(g);
}



int GRAFOgrau_maximo(Grafo *g){

}



void GRAFOimprime(Grafo *g){
   int v;
   printf("Numero de arestas: %d Numero de Vertices: %d\n", g->num_a, g->num_v);
    for (v = 0; v < g->num_v; v++)
    {
        ElemLista* temp = g->lista_adj[v];
        printf("%d: ", v);
        while (temp)
        {
            printf("%d ", temp->viz);
            temp = temp->prox;
        }
        printf("\n");
    }
}

