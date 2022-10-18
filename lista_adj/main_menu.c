#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "graph.c"

int main() {
    Grafo *g;
    int i, n_v, n_op, v1, v2;
    char op;
    scanf("%d", &n_v);
    g = GRAFOconstroi(n_v);

    printf("Digite o n de op: ");
    scanf("%d", &n_op);
    i = n_op;
    while(i == n_op){
        printf("OPERACAO: ");
        scanf("%c", &op);
        switch (op)
        {
            case 'I':
                scanf("%d", &v1);
                scanf("%d", &v2);
                GRAFOinsere_aresta(g, ARESTA(v1, v2));
                GRAFOimprime(g);
                i--;
            break;
            case 'R':
                scanf("%d", &v1);
                scanf("%d", &v2);
                GRAFOremove_aresta(g, ARESTA(v1, v2));
                i--;
            break;
            case 'P':
                GRAFOimprime(g);
                i--;
            default:
                break;
        }
    }
    return 0;
}
    