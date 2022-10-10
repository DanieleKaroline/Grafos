#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef int Viz;

typedef struct lista{
    int vert;
    Viz viz;
    struct lista *prox;
} Lista;

typedef struct vertice{
    Lista *head; //inicio da lista head (vertice): v0 v1 v2
} Vertice;

typedef struct grafo{
    int num_vert;
    int num_a;
    Vertice *adj; //ponteiro para o arranjo/nó
} Grafo;

Grafo *GRAFOconstroi(int num_vertices){
    //reserva espaco da estrutura head para a quantidade de vertices
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->num_vert = num_vertices;
    g->num_a = 0;
    g->adj = (Vertice*)malloc(num_vertices*sizeof(Vertice));

    for(int i = 0; i < num_vertices; i++){
        g->adj[i].head = NULL;
    }
    return g;
}

Lista *LISTAconstroi(int v, int d){
    Lista *aux = (Lista*)malloc(sizeof(Lista));
    aux->vert = v;
    aux->viz = d;
    
    
    aux->prox = NULL;
    return aux;
}
void GRAFOinsere_aresta(Grafo *g, Aresta e){
    if(e.v1 < 0 || (e.v1 >= g->num_vert)){
        return;
    }
    if(e.v2 < 0 || (e.v2 >= g->num_vert)){
        return;
    }
    Lista *new = LISTAconstroi(e.v1, e.v2);
    new->prox = g->adj[e.v1].head;
    g->adj[e.v1].head = new;
    g->num_a++;
}
void GRAFOimprime(Grafo *g){
   printf("V: %d e A: %d \n",g->num_vert, g->num_a);
    for(int i = 0; i < g->num_vert; i++){
        printf("%d: ", i);
        Lista *ad = g->adj[i].head;
        while (ad)
        {
            printf("%d ", ad->viz);
            ad = ad->prox;
        }
        printf("\n");
    }
}