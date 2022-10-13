#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "graph.c"

int main() {
    Grafo *g;
    
    g = GRAFOconstroi(4);
    GRAFOinsere_aresta(g, ARESTA(0,1));
    GRAFOinsere_aresta(g, ARESTA(2,3));
    GRAFOinsere_aresta(g, ARESTA(3,1));
    GRAFOinsere_aresta(g, ARESTA(3,3));
    GRAFOimprime(g);
    //GRAFOremove_aresta(g, ARESTA(2,3))
    GRAFOimprime(g);
    
    

    return 0;
}
    
