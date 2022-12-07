/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef ARESTA_H

#define ARESTA_H

struct aresta {
    int v1;
    int v2;
};
typedef struct aresta Aresta;

Aresta ARESTA(int v1, int v2);

#endif /* ARESTA_H */
