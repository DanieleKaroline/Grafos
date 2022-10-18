#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct elemListaAdj {
    int v;
    struct elemListaAdj *proximo;
};
typedef struct elemListaAdj ElemListaAdj;

struct grafo {
    int num_v;
    int grau;
    int num_a;
    ElemListaAdj **listas_adj;
};

Grafo *GRAFOconstroi(int num_v) {
    Grafo *g;

    g = malloc(sizeof(*g));

    g->num_v = num_v;
    g->num_a = 0;
    g->grau = 0;

    g->listas_adj = malloc(num_v * sizeof(*(g->listas_adj)));

    for (int i = 0; i < num_v; i++) {
        g->listas_adj[i] = NULL;
    }

    return g;
}

void GRAFOimprime(Grafo *g){
   int v;
   printf("Numero de arestas: %d Numero de Vertices: %d\n", g->num_a, g->num_v);
   for (v = 0; v < g->num_v; v++)
    {
        ElemListaAdj *temp = g->listas_adj[v];
        printf("%d: ", v);
        while (temp)
        {
            printf("%d ", temp->v);
            temp = temp->proximo;
        }
        printf("\n");
    }
}

ElemListaAdj* NOconstroi(int v)
{
    ElemListaAdj* no = (struct ElemListaAdj *)malloc(sizeof(no));
    no->v = v;    
    no->proximo = NULL;
    return no;
}


void GRAFOinsere_aresta(Grafo *g, Aresta e){
    if(e.v1 != e.v2){
        ElemListaAdj* no = NOconstroi(e.v2);
        no->proximo = g->listas_adj[e.v1];
        g->listas_adj[e.v1] = no;
 
        no = NOconstroi(e.v1);
        no->proximo = g->listas_adj[e.v2];
        g->listas_adj[e.v2] = no;
    }
    else{
        printf("Lacos nao sao permitidos!\n");
        return;
    }
   g->num_a++;
}

void GRAFOdestroi(Grafo *g){
    for (int i = 0; i < g->num_v; i++)
    {
        free(g->listas_adj[i]);
        free(g->listas_adj[i]->proximo);
        printf("*\n");
    }
    
    free(g->listas_adj);
    free(g);

}

int GRAFOget_num_aresta(Grafo *g){
    return g->num_a;
}

int GRAFOget_num_vertice(Grafo *g){
    return g->num_v;
}

void GRAFOremove_aresta(Grafo *g, Aresta e){
    ElemListaAdj **k = &g->listas_adj[e.v1];
    ElemListaAdj **l = &g->listas_adj[e.v2];
    while (*l != NULL && (*l)->v < e.v2){
        l = &(*l)->proximo;

        while (*k != NULL && (*k)->v < e.v1){
            k = &(*k)->proximo;
        }
  }
   
  if (*k != NULL && (*k)->v == e.v2) {
        ElemListaAdj* r = *k;
        *k = (*k)->proximo;
        free(r);
  }
    if (*l != NULL && (*l)->v == e.v1) {
        ElemListaAdj* r = *l;
        *l = (*l)->proximo;
        free(r);
  }
}


int GRAFOgrau_maximo(Grafo *g){
    ElemListaAdj *aux;
    int c = 0;
    for(int i = 0; i < g->num_v; i++){
        int a = 0;
        aux = g->listas_adj[i];
        while(aux != NULL){
            a++;
            aux = aux->proximo;
        }
        if(a > c)
            c = a;
    }
    return c;
}