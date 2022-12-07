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
#include <stdbool.h>
#include "grafo.h"

struct elemListaAdj {
    int v;
    struct elemListaAdj *proximo;
};
typedef struct elemListaAdj ElemListaAdj;

struct grafo {
    int num_vertices;
    int num_arestas;
    ElemListaAdj **listas_adj;
};

static bool GRAFOvertice_valido(Grafo *g, int v) {
    if ((v >= 0) && (v <= (g->num_vertices - 1))) {
        return true;
    }

    return false;
}

static bool GRAFOaresta_valida(Grafo *g, Aresta e) {
    if (GRAFOvertice_valido(g, e.v1) && GRAFOvertice_valido(g, e.v2)) {
        return true;
    }

    return false;
}

Grafo *GRAFOconstroi(int num_vertices) {
    Grafo *g = malloc(sizeof(*g));

    g->num_vertices = num_vertices;
    g->num_arestas = 0;

    g->listas_adj = malloc(num_vertices * sizeof(*(g->listas_adj)));

    for (int i = 0; i < num_vertices; i++) {
        g->listas_adj[i] = NULL;
    }

    return g;
}

int GRAFOnum_vertices(Grafo *g) {
    return g->num_vertices;
}

int GRAFOnum_arestas(Grafo *g) {
    return g->num_arestas;
}

static bool GRAFOtem_aresta(Grafo *g, Aresta e) {
    ElemListaAdj *vizinho;

    if (!GRAFOaresta_valida(g, e)) {
        printf("Erro na operacao GRAFOtem_aresta: a aresta %d %d eh "
            "invalida!\n", e.v1, e.v2);
        exit(EXIT_FAILURE);
    }

    vizinho = g->listas_adj[e.v1];
    while (vizinho != NULL) {
        if (vizinho->v == e.v2) {
            return true;
        }

        vizinho = vizinho->proximo;
    }

    return false;
}

void GRAFOinsere_aresta(Grafo *g, Aresta e) {
    ElemListaAdj *vizinho;

    if (!GRAFOaresta_valida(g, e)) {
        printf("Erro na operacao GRAFOinsere_aresta: a aresta %d %d eh "
            "invalida!\n", e.v1, e.v2);
        exit(EXIT_FAILURE);
    }

    if (GRAFOtem_aresta(g, e) || (e.v1 == e.v2)) {
        return;
    }

    // Insere o segundo vertice da aresta no inicio da lista de adjacencias do
    // primeiro vertice da aresta
    vizinho = malloc(sizeof(*vizinho));
    vizinho->v = e.v2;

    vizinho->proximo = g->listas_adj[e.v1];
    g->listas_adj[e.v1] = vizinho;

    // Insere o primeiro vertice da aresta no inicio da lista de adjacencias
    // do segundo vertice da aresta
    vizinho = malloc(sizeof(*vizinho));
    vizinho->v = e.v1;

    vizinho->proximo = g->listas_adj[e.v2];
    g->listas_adj[e.v2] = vizinho;

    g->num_arestas++;
}

void GRAFOremove_aresta(Grafo *g, Aresta e) {
    bool grafo_tem_aresta;
    ElemListaAdj *vizinho;
    ElemListaAdj *vizinho_anterior;

    if (!GRAFOaresta_valida(g, e)) {
        printf("Erro na operacao GRAFOremove_aresta: a aresta %d %d eh "
            "invalida!\n", e.v1, e.v2);
        exit(EXIT_FAILURE);
    }

    grafo_tem_aresta = false;

    // Remove o segundo vertice da aresta da lista de adjacencias do primeiro
    // vertice da aresta
    vizinho_anterior = NULL;
    vizinho = g->listas_adj[e.v1];
    while (vizinho != NULL) {
        if (vizinho->v == e.v2) {
            if (vizinho_anterior == NULL) {
                g->listas_adj[e.v1] = vizinho->proximo;
            }
            else {
                vizinho_anterior->proximo = vizinho->proximo;
            }

            free(vizinho);

            grafo_tem_aresta = true;

            break;
        }

        vizinho_anterior = vizinho;
        vizinho = vizinho->proximo;
    }

    if (grafo_tem_aresta) {
        // Remove o primeiro vertice da aresta da lista de adjacencias do
        // segundo vertice da aresta
        vizinho_anterior = NULL;
        vizinho = g->listas_adj[e.v2];
        while (vizinho != NULL) {
            if (vizinho->v == e.v1) {
                if (vizinho_anterior == NULL) {
                    g->listas_adj[e.v2] = vizinho->proximo;
                }
                else {
                    vizinho_anterior->proximo = vizinho->proximo;
                }
    
                free(vizinho);
    
                break;
            }
    
            vizinho_anterior = vizinho;
            vizinho = vizinho->proximo;
        }

        g->num_arestas--;
    }
}

static int GRAFOgrau(Grafo *g, int v) {
    int grau;
    ElemListaAdj *vizinho;

    if (!GRAFOvertice_valido(g, v)) {
        printf("Erro na operacao GRAFOgrau: o vertice %d eh invalido!\n", v);
        exit(EXIT_FAILURE);
    }

    grau = 0;
    vizinho = g->listas_adj[v];
    while (vizinho != NULL) {
        grau++;

        vizinho = vizinho->proximo;
    }

    return grau;
}

int GRAFOgrau_maximo(Grafo *g) {
    int grau;

    int grau_maximo = 0;
    for (int i = 0; i < g->num_vertices; i++) {
        grau = GRAFOgrau(g, i);

        if (grau > grau_maximo) {
            grau_maximo = grau;
        }
    }

    return grau_maximo;
}

void GRAFOimprime(Grafo *g) {
    ElemListaAdj *vizinho;

    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d:", i);

        vizinho = g->listas_adj[i];
        while (vizinho != NULL) {
            printf(" %d", vizinho->v);
    
            vizinho = vizinho->proximo;
        }

        printf("\n");
    }
}

void GRAFOdestroi(Grafo *g) {
    ElemListaAdj *aux;

    for (int i = 0; i < g->num_vertices; i++) {
        while (g->listas_adj[i] != NULL) {
            aux = g->listas_adj[i];
            g->listas_adj[i] = g->listas_adj[i]->proximo;

            free(aux);
        }
    }

    free(g->listas_adj);

    free(g);
}
