/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef FILAPRI_MIN_H

#define FILAPRI_MIN_H

#include <stdbool.h>
#include "item.h"

typedef struct filaPriMin FilaPriMin;

FilaPriMin *FILAPRI_MINconstroi(int max_num_itens);

bool FILAPRI_MINvazia(FilaPriMin *f);

bool FILAPRI_MINcheia(FilaPriMin *f);

bool FILAPRI_MINtem_indice(FilaPriMin *f, int ind);

void FILAPRI_MINinsere(FilaPriMin *f, Item i);

Item FILAPRI_MINremove(FilaPriMin *f);

Chave FILAPRI_MINchave(FilaPriMin *f, int ind);

void FILAPRI_MINdiminui_chave(FilaPriMin *f, int ind, Chave c);

void FILAPRI_MINdestroi(FilaPriMin *f);

#endif /* FILAPRI_MIN_H */
