/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "filapri_min.h"

struct filaPriMin {
    Item *itens;
    int *ind_posfila;
    int max_num_itens;
    int num_itens;
};

bool indice_valido(FilaPriMin *f, int ind) {
    if ((ind >= 0) && (ind <= (f->max_num_itens - 1))) {
        return true;
    }

    return false;
}

int pai(int i) {
    return ((i - 1) / 2);
}

int filho_esq(int i) {
    return ((2 * i) + 1);
}

int filho_dir(int i) {
    return ((2 * i) + 2);
}

void troca(FilaPriMin *f, int i, int j) {
    Item aux = f->itens[i];
    f->itens[i] = f->itens[j];
    f->itens[j] = aux;

    f->ind_posfila[f->itens[i].ind] = i;
    f->ind_posfila[f->itens[j].ind] = j;
}

void consertaParaCima(FilaPriMin *f, int i) {
    while (i > 0) {
        if (ITEMcompara(f->itens[i], f->itens[pai(i)]) >= 0) {
            break;
        }

        troca(f, i, pai(i));

        i = pai(i);
    }
}

void consertaParaBaixo(FilaPriMin *f, int i) {
    int menor_filho;

    while (filho_esq(i) < f->num_itens) {
        menor_filho = filho_esq(i);
        if (filho_dir(i) < f->num_itens) {
            if (ITEMcompara(f->itens[filho_dir(i)], f->itens[filho_esq(i)])
                    < 0) {
                menor_filho = filho_dir(i);
            }
        }

        if (ITEMcompara(f->itens[i], f->itens[menor_filho]) <= 0) {
            break;
        }

        troca(f, i, menor_filho);

        i = menor_filho;
    }
}

FilaPriMin *FILAPRI_MINconstroi(int max_num_itens) {
    FilaPriMin *f;

    f = malloc(sizeof(*f));

    f->itens = malloc(max_num_itens * sizeof(*(f->itens)));

    f->ind_posfila = malloc(max_num_itens * sizeof(*(f->ind_posfila)));
    for (int i = 0; i < max_num_itens; i++) {
        f->ind_posfila[i] = -1;
    }

    f->max_num_itens = max_num_itens;
    f->num_itens = 0;

    return f;
}

bool FILAPRI_MINvazia(FilaPriMin *f) {
    return (f->num_itens == 0);
}

bool FILAPRI_MINcheia(FilaPriMin *f) {
    return (f->num_itens == f->max_num_itens);
}

bool FILAPRI_MINtem_indice(FilaPriMin *f, int ind) {
    if (!indice_valido(f, ind)) {
        printf("Erro na operacao FILAPRI_MINtem_indice: o indice %d eh "
            "invalido!\n", ind);
        exit(EXIT_FAILURE);
    }

    return (f->ind_posfila[ind] != -1);
}

void FILAPRI_MINinsere(FilaPriMin *f, Item i) {
    if (FILAPRI_MINcheia(f)) {
        printf("Erro na operacao FILAPRI_MINinsere: fila de prioridade "
            "cheia!\n");
        exit(EXIT_FAILURE);
    }

    if (!indice_valido(f, i.ind)) {
        printf("Erro na operacao FILAPRI_MINinsere: o indice %d do item eh "
            "invalido!\n", i.ind);
        exit(EXIT_FAILURE);
    }

    if (FILAPRI_MINtem_indice(f, i.ind)) {
        printf("Erro na operacao FILAPRI_MINinsere: o indice %d do item ja "
            "existe na fila de prioridade!\n", i.ind);
        exit(EXIT_FAILURE);
    }

    f->itens[f->num_itens] = i;
    f->ind_posfila[i.ind] = f->num_itens;
    f->num_itens++;

    consertaParaCima(f, (f->num_itens - 1));
}

Item FILAPRI_MINremove(FilaPriMin *f) {
    Item i;

    if (FILAPRI_MINvazia(f)) {
        printf("Erro na operacao FILAPRI_MINremove: fila de prioridade "
            "vazia!\n");
        exit(EXIT_FAILURE);
    }

    i = f->itens[0];

    f->ind_posfila[f->itens[0].ind] = -1;

    f->itens[0] = f->itens[f->num_itens - 1];
    f->ind_posfila[f->itens[0].ind] = 0;

    f->num_itens--;

    consertaParaBaixo(f, 0);

    return i;
}

Chave FILAPRI_MINchave(FilaPriMin *f, int ind) {
    if (!indice_valido(f, ind)) {
        printf("Erro na operacao FILAPRI_MINchave: o indice %d eh invalido!"
            "\n", ind);
        exit(EXIT_FAILURE);
    }

    if (!FILAPRI_MINtem_indice(f, ind)) {
        printf("Erro na operacao FILAPRI_MINchave: o indice %d nao existe na "
            "fila de prioridade!\n", ind);
        exit(EXIT_FAILURE);
    }

    return f->itens[f->ind_posfila[ind]].chave;
}

void FILAPRI_MINdiminui_chave(FilaPriMin *f, int ind, Chave c) {
    if (!indice_valido(f, ind)) {
        printf("Erro na operacao FILAPRI_MINdiminui_chave: o indice %d eh "
            "invalido!\n", ind);
        exit(EXIT_FAILURE);
    }

    if (!FILAPRI_MINtem_indice(f, ind)) {
        printf("Erro na operacao FILAPRI_MINdiminui_chave: o indice %d nao "
            "existe na fila de prioridade!\n", ind);
        exit(EXIT_FAILURE);
    }

    // TODO: Checar se a chave recebida por parametro eh menor que a chave
    // atual do item

    f->itens[f->ind_posfila[ind]].chave = c;

    consertaParaCima(f, f->ind_posfila[ind]);
}

void FILAPRI_MINdestroi(FilaPriMin *f) {
    free(f->itens);
    free(f->ind_posfila);

    free(f);
}
