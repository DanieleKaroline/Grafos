/*
 * Tarefa 02 - Distancias e Caminhos
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef FILA_H

#define FILA_H

#include <stdbool.h>
#include "item.h"

typedef struct fila Fila;

Fila *FILAconstroi();

bool FILAvazia(Fila *f);

void FILAinsere(Fila *f, Item i);

Item FILAremove(Fila *f);

void FILAdestroi(Fila *f);

#endif /* FILA_H */
