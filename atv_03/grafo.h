/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "aresta.h"

typedef struct grafo Grafo;

/** Constroi um grafo simples que possui o numero de vertices recebido por
 *  parametro e que nao possui arestas
 */
Grafo *GRAFOconstroi(int num_vertices);

int GRAFOnum_vertices(Grafo *g);

int GRAFOnum_arestas(Grafo *g);

/** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e nao
 *  seja um laco
 */
void GRAFOinsere_aresta(Grafo *g, Aresta e);

/** Remove uma aresta do grafo caso a aresta exista no grafo
 */
void GRAFOremove_aresta(Grafo *g, Aresta e);

int GRAFOgrau_maximo(Grafo *g);

void GRAFOimprime(Grafo *g);

void GRAFOdestroi(Grafo *g);

#endif /* GRAFO_H */
