#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "grafo.c"

int main() {
    Grafo *grafo;
    int v1, v2, v, e, p;
    

    scanf("%d %d", &v, &e);

    grafo = GRAFOconstroi(v);

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &v1, &v2, &p);
        GRAFOinsere_aresta(grafo, ARESTA(v1, v2, p));
        
    }
    scanf("%d %d", &v1, &v2);
    GRAFOremove_aresta(grafo, ARESTA(v1, v2, 0));
    GRAFOimprime(grafo);
   /*
   scanf("%d", &c);
    for(int i = 0; i < c; i++){
        scanf("%d %d", &v1, &v2);
        GRAFOdij(grafo, ARESTA(v1, v2));
    }
   */ 
    GRAFOdestroi(grafo);

    return 0;
}
