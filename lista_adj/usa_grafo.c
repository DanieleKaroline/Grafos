#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "aresta.c"
#include "graph.h"
#include "graph.c"

int main() {
    Grafo *grafo;
    
    grafo = GRAFOconstroi(4);

    GRAFOinsere_aresta(grafo, ARESTA(0,2));
    GRAFOinsere_aresta(grafo, ARESTA(0,1));
    GRAFOinsere_aresta(grafo, ARESTA(3,1));
    GRAFOinsere_aresta(grafo, ARESTA(2,0));
    GRAFOinsere_aresta(grafo, ARESTA(2,1));
    GRAFOimprime(grafo);

    return 0;
}
    