#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "grafo.c"

int main() {
    Grafo *g;
    int i, n_v, n_op, v1, v2;
    char op;
    scanf("%d", &n_v);
    g = GRAFOconstroi(n_v);

    scanf("%d", &n_op);
    i = n_op;
    while(i == n_op){
        scanf("%c", &op);
        switch (op)
        {
            case 'I':
                scanf("%d %d", &v1, &v2);
                GRAFOinsere_aresta(g, ARESTA(v1, v2));
                
            break;
            case 'R':
               scanf("%d %d", &v1, &v2);
               GRAFOremove_aresta(g, ARESTA(v1, v2));
               
            break;
            case 'P':
                GRAFOimprime(g);
                
            break;
            case 'E':
                printf("%d\n",GRAFOget_num_aresta(g));
            break;
            case 'G':
                printf("%d\n", GRAFOgrau_maximo(g));
            break;
            case 'D':
                GRAFOdestroi(g);
            break;
            i--;
        }
    
    }
    return 0;
}
    