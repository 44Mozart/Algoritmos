

#include "graphs.h"



int readGraphM(GraphM g) {
    int i, n, j;
    printf("Número de vértices do grafo? (<=%d)\n", MAX);
    scanf("%d", &n);
    if (n > MAX) return 0;
    for (i = 0; i < n; i++){
        for (i = 0; i < n; i++){
            scanf ("%d", &g[i][j]);
        }
    }
    return n;
}
