#include <stdio.h>
#include <stdlib.h>
#include "aresta.c"
#include "grafo.c"

int main() {
    Grafo *g;

    int n_v; 
    int n_op;
    int v1, v2;

    scanf("%d %d", &n_v, &n_op);
    g = GRAFOconstroi(n_v);
    for(int i = (n_op-1); i >= 0; i--){
        char op;
        scanf("%s", &op);
        
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
            case 'E':
                printf("%d\n",GRAFOget_num_aresta(g));
            break;
            case 'G':
                printf("%d\n", GRAFOgrau_maximo(g));
            break;
            case 'P':
                GRAFOimprime(g);
            break;
            default:
             exit(0);
            break;
        }
        if(i == 0){
            exit(0);
        }
    }
    
    return 0;
} 
    