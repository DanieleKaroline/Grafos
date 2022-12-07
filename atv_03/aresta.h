/*
 * Tarefa 02 - Distancias e Caminhos
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
    int p;
};
typedef struct aresta Aresta;

Aresta ARESTA(int v1, int v2, int p);

#endif /* ARESTA_H */
