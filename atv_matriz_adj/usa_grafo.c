/*
 * Tarefa de laboratorio 00_a - graph
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "graph.h"

int main() {
    int N;
    Graph *graph;
    int i;

    graph = GRAPHconstroi(4);

    GRAPHinsere_aresta(graph, ARESTA(0,1));
    GRAPHinsere_aresta(graph, ARESTA(0,2));
    GRAPHremove_aresta(graph, ARESTA(0,2));
    GRAPHremove_aresta(graph, ARESTA(3,2));
    printf("Numero de arestas: %d\n", GRAPHget_num_aresta(graph));
    printf("Numero de vertices: %d\n", GRAPHget_num_vertice(graph));
    GRAPHimprime(graph);
    GRAPHdestroi(graph);
    


    return 0;
}
