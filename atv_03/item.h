/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef ITEM_H

#define ITEM_H

typedef int Chave;

struct item {
    int ind;
    Chave chave;
};
typedef struct item Item;

Item ITEM(int ind, int chave);

int ITEMcompara(Item item1, Item item2);

#endif /* ITEM_H */
