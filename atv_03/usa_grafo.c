/*
 * Tarefa 02 - Distancias e Caminhos
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "grafo.c"

int main() {
    int V;
    int E;
    Grafo *grafo;
    int v1;
    int v2;
    int C;
    int p;

    scanf("%d %d", &V, &E);

    grafo = GRAFOconstroi(V);

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &v1, &v2, &p);
        GRAFOinsere_aresta(grafo, ARESTA(v1, v2, p));
        GRAFOimprime(grafo);
    }
    GRAFOimprime(grafo);
    /*scanf("%d", &C);

    if (C > 0) {
        for (int i = 0; i < (C - 1); i++) {
            scanf("%d", &v1);
            GRAFOimprime_distancias_caminhos(grafo, v1);

            printf("\n");
        }

        scanf("%d", &v1);
        GRAFOimprime_distancias_caminhos(grafo, v1);
    }*/

    GRAFOdestroi(grafo);

    return 0;
}
