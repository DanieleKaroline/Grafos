#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "graph.h"

int main() {
    Grafo *grafo;
    
    grafo = GRAFOconstroi(4);

    GRAFOinsere_aresta(grafo, ARESTA(0,1));
    GRAFOinsere_aresta(grafo, ARESTA(0,2));
    GRAFOimprime(grafo);

    return 0;
}
    