#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "grafo.h"


int main() {
  Grafo *grafo;

	int v, e;
	scanf("%d%d\n", &v, &e);
	grafo = GRAFOconstroi(v);
	
	for(int i = 0; i < e; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		GRAFOinsere_aresta(grafo, ARESTA(x, y));
	}
	int times;
	scanf("%d", &times);
	for(int i=0; i < times; i++)
	{
		int ver;
		scanf("%d", &ver);
		GRAFOimprime_distancia(grafo, ver);
	}
		
    return 0;
}
