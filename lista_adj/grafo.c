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
    int num_a;
    int gr;
    ElemListaAdj **listas_adj;
};


int edge(Grafo *g, Aresta e)
{
	ElemListaAdj *aux = malloc(sizeof(ElemListaAdj));
	for(aux = g->listas_adj[e.v1]; aux != NULL; aux = aux->proximo)
	{
		if(aux->v == e.v2){
            return 1;
        }
	}
	return 0;
}

Grafo *GRAFOconstroi(int num_v) {
    Grafo *g;

    g = malloc(sizeof(*g));

    g->num_v = num_v;
    g->num_a = 0;
    g->gr = 0;

    g->listas_adj = malloc(num_v * sizeof(*(g->listas_adj)));

    for (int i = 0; i < num_v; i++) {
        g->listas_adj[i] = NULL;
    }

    return g;
}

ElemListaAdj* NOconstroi(int v)
{
    ElemListaAdj* no = (ElemListaAdj*)malloc(sizeof(no));
    no->v = v;    
    no->proximo = NULL;
    return no;
}

void GRAFOinsere_aresta(Grafo *g, Aresta e){
    if(edge(g, e) || e.v1 == e.v2){
       return;
    }
    else{
        ElemListaAdj* no = NOconstroi(e.v2);
        no->proximo = g->listas_adj[e.v1];
        g->listas_adj[e.v1] = no;
 
        no = NOconstroi(e.v1);
        no->proximo = g->listas_adj[e.v2];
        g->listas_adj[e.v2] = no;
    }
    
   g->num_a++;
}

void GRAFOdestroi(Grafo *g){
    for (int i = 0; i < g->num_v; i++)
    {
        free(g->listas_adj[i]);
        free(g->listas_adj[i]->proximo);
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

Grafo *GRAFOremove_aresta(Grafo *g, Aresta e){
    if(edge(g, e) == 0){
        return;
    }
    ElemListaAdj *i = malloc(sizeof(ElemListaAdj));
	
    ElemListaAdj *aux = malloc(sizeof(ElemListaAdj));
	aux = NULL;
	
	for(i = g->listas_adj[e.v1]; i != NULL; i = i->proximo)
	{
		if(i->v == e.v2)
		{
			if(aux != NULL){
				aux->proximo = i->proximo;
			}else
			{
				g->listas_adj[e.v1] = i->proximo;
			}
			free(i);
			break; //pra não entrar em loop
		}
		aux = i;
	}

	aux = NULL;
	for(i = g->listas_adj[e.v2]; i != NULL; i = i->proximo)
	{
		if(i->v == e.v1)
		{
			if(aux != NULL){
				aux->proximo = i->proximo;
			}else
			{
				g->listas_adj[e.v2] = i->proximo;
			}
			free(i);
			break;
		}
		aux = i;
	}
	g->num_a -= 1;
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
    g->gr = c;
    return c;
}

void GRAFOimprime(Grafo *g){
   int v;
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