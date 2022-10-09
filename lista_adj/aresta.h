#ifndef ARESTA_H
#define ARESTA_H

struct aresta {
    int v1;
    int v2;
};
typedef struct aresta Aresta;

Aresta ARESTA(int v1, int v2);

#endif /* ARESTA_H */