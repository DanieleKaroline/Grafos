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
#include "fila.h"

struct elemFila {
    Item item;
    struct elemFila *proximo;
};
typedef struct elemFila ElemFila;

struct fila {
    ElemFila *primeiro;
    ElemFila *ultimo;
};

Fila *FILAconstroi() {
    Fila *f;

    f = malloc(sizeof(*f));

    f->primeiro = NULL;
    f->ultimo = NULL;

    return f;
}

bool FILAvazia(Fila *f) {
    return (f->primeiro == NULL);
}

void FILAinsere(Fila *f, Item i) {
    ElemFila *aux;

    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = malloc(sizeof(*aux));
    aux->item = i;
    aux->proximo = NULL;

    // Insere o novo elemento no fim da lista encadeada que representa a fila
    if (FILAvazia(f)) {
        f->primeiro = aux;
        f->ultimo = aux;
    }
    else {
        f->ultimo->proximo = aux;
        f->ultimo = aux;
    }
}

Item FILAremove(Fila *f) {
    Item i;
    ElemFila *aux;

    if (FILAvazia(f)) {
        printf("Erro na operacao FILAremove: fila vazia!\n");
        exit(EXIT_FAILURE);
    }

    // Armazena o item a ser removido da fila
    i = f->primeiro->item;

    // Armazena o primeiro elemento da lista encadeada que representa a fila e
    // remove este primeiro elemento da lista
    aux = f->primeiro;
    if (f->primeiro == f->ultimo) {
        f->primeiro = NULL;
        f->ultimo = NULL;
    }
    else {
        f->primeiro = f->primeiro->proximo;
    }

    // Libera a memoria alocada para o elemento removido
    free(aux);

    // Retorna o item removido da fila
    return i;
}

void FILAdestroi(Fila *f) {
    ElemFila *aux;

    while (!FILAvazia(f)) {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // fila e remove este primeiro elemento da lista
        aux = f->primeiro;
        f->primeiro = f->primeiro->proximo;

        // Libera a memoria alocada para o elemento removido
        free(aux);
    }

    free(f);
}
