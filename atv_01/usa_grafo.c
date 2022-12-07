/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "grafo.h"

int main() {
    int V;
    int O;
    Grafo *grafo;
    char op;
    int v1;
    int v2;

    scanf("%d %d", &V, &O);

    grafo = GRAFOconstroi(V);

    for (int i = 0; i < O; i++) {
        scanf("\n");
        scanf("%c", &op);

        switch (op) {
            case 'I':
                scanf("%d %d", &v1, &v2);
                GRAFOinsere_aresta(grafo, ARESTA(v1, v2));
                break;

            case 'R':
                scanf("%d %d", &v1, &v2);
                GRAFOremove_aresta(grafo, ARESTA(v1, v2));
                break;

            case 'E':
                printf("%d\n", GRAFOnum_arestas(grafo));
                break;

            case 'G':
                printf("%d\n", GRAFOgrau_maximo(grafo));
                break;

            case 'P':
                GRAFOimprime(grafo);
                break;

            default:
                printf("Erro na funcao main: a operacao %c eh invalida!\n",
                    op);
                exit(EXIT_FAILURE);
        }
    }

    GRAFOdestroi(grafo);

    return 0;
}
