#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct grafo {
  int num_v;
  int num_a;
  int **matriz;
};

struct fila{
  int v;
  struct fila *prox;
};
typedef struct fila Fila;

void FILAimprime(Fila *f)
{
	Fila *aux = malloc(sizeof(Fila));
	for(aux = f; aux != NULL; aux = aux ->prox)
	{
		printf(" %d", aux->v);
	}
	printf("\n");
}

Fila * FILAinsere(Fila *f, int x) {
	
  Fila *new = malloc(sizeof(Fila));
  new->v = x;
  new->prox = NULL;
	if(f == NULL)
	{
		return new;
	}
	Fila *aux  = malloc(sizeof(Fila));
  for (aux = f; aux != NULL; aux = aux->prox) {
    if (aux->prox == NULL) {
      aux->prox = new;
			break;
    }
  }
	return f;
  
}

Fila * FILAremove(Fila *f) {
  Fila *aux = malloc(sizeof(Fila));
  aux = f->prox;
	int x = f->v;
	free(f);
	f = malloc(sizeof(Fila));
	f = aux;

  return f;
}

Grafo *GRAFOconstroi(int num_v) {
  Grafo *g;

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

void GRAFOinsere_aresta(Grafo *g, Aresta a) {
  if(g->matriz[a.v1][a.v2] == 0 && a.v1 != a.v2){
      g->matriz[a.v1][a.v2] = 1;
      g->matriz[a.v2][a.v1] = 1;
      g->num_a++;
  }
}

void GRAFOremove_aresta(Grafo *g, Aresta a) {
    if(g->matriz[a.v1][a.v2] == 1){
        g->matriz[a.v1][a.v2] = 0;
        g->matriz[a.v2][a.v1] = 0;
        g->num_a--;
    }
}

int GRAFOget_num_aresta(Grafo *g){ 
  return g->num_a;
}

int GRAFOget_num_vertice(Grafo *g){ 
  return g->num_v; 
}

void GRAFOimprime(Grafo *g) {
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

static bool caminho(Grafo *g, int v, int w, int marcado[], int indent) {
  for (int i = 0; i < indent; i++) {
    printf(" ");
  }
  printf("caminho (%d, %d)\n", v, w);

  if (v == w) {
    return true;
  }

  marcado[v] = 1;

  for (int u = 0; u < g->num_v; u++) {
    if (g->matriz[v][u] != 0) {
      if (marcado[u] == 0) {
        if (caminho(g, u, w, marcado, (indent + 4))) {
          return true;
        }
      }
    }
  }

  return false;
}

bool GRAFOcaminho(Grafo *g, int v, int w) {
  int marcado[g->num_v];

  for (int i = 0; i < g->num_v; i++) {
    marcado[i] = 0;
  }

  return caminho(g, v, w, marcado, 0);
}

void GRAFOdestroi(Grafo *g) {

  for (int i = 0; i < g->num_v; i++) {
    free(g->matriz[i]);
  }

  free(g->matriz);
  free(g);
}

void GRAFOimprime_distancia(Grafo *g, int x){
int marcado[g->num_v];
  int pai[g->num_v];
  int dist[g->num_v];

  for (int i = 0; i < g->num_v; i++)
    marcado[i] = 0;
  Fila *f = malloc(sizeof(Fila));
	f->v = x;
	f->prox = NULL;
  pai[x] = -1;
  dist[x] = 0;
  marcado[x] = 1;
  while (f != NULL) {
    int w = f->v;
    f = FILAremove(f);
		
		// if(f == NULL)
		// {
		// 	printf("F really was NULL\n");
		// }
    // printf("%d\n", w);
    for (int u = 0; u < g->num_v; u++) {
      if (g->matriz[w][u] != 0) {
        if (marcado[u] == 0) {
          marcado[u] = 1;
          pai[u] = w;
          dist[u] = dist[w] + 1;
          f = FILAinsere(f, u);
        }
      }
    }
  }
	int c = g->num_v;
  for (int i = 0; i < g->num_v; i++){
    if (marcado[i] == 0) {
      printf("%d: infinita, sem caminho ate %d\n", i, x);
			c --;
    } 
    else if (i == x){
      printf("%d: 0, %d\n", i, i);
    } 
    else{
      printf("%d: %d,", i, dist[i]);

      int aux = i;

      while(pai[aux] != -1){
        printf(" %d", aux);
        aux = pai[aux];
      }

      printf(" %d\n", x);
    }
  }

	int max = 0;
	for(int i= 0; i<g->num_v; i++)
	{
			if(marcado[i] == 1 && dist[i] > max){
				max = dist[i];
			}
	}
	printf("%d\n", c);
	printf("%d\n", max);
	
}
