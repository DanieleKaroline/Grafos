/*
 * Tarefa 02 - Distancias e Caminhos
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include "aresta.h"

Aresta ARESTA(int v1, int v2, int p) {
    return ((Aresta) {.v1 = v1, .v2 = v2, .p = p});
}
