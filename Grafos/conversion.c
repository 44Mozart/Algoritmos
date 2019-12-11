

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


void printGraphM(GraphM g, int n) {
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf ("%d", g[i][j]);
        }
        printf ("\n");
    }
}



void printGraphL(GraphL g, int n) {
    int i;
    struct edge *aux;
    for (i = 0; i < n; i++) {
        for (aux = g[i]; aux ; aux = aux->next) {
            printf ("--> (%d,%d)", aux->dest, aux->weight);
        }
        printf ("\n");
    }
}



void graphLtoM(GraphM gm, GraphL gl, int n) {
    int i, j;
    struct edge *aux;
    for (i = 0; i < n; i++){
        for (j = 0, aux = gl[i]; j < n; j++) {
            if (aux && aux->dest == j){
                gm[i][j] = aux -> weight;
                aux = aux->next;
            }
            else {
                gm[i][j] = NE;
            }
        }
    }
}



void graphMtoL(GraphL gl, GraphM gm, int n) {
    int i, j;
    struct edge *aux, *head;
    for (i = 0; i < n; i++){
        head = NULL;
        for (j = n-1; j>=0; j--){
            if (gm[i][j] != NE){
                aux = malloc(sizeof(struct edge));
                aux -> dest = j;
                aux -> weight = gm[i][j];
                aux -> next = head;
                head = aux;
            }
        }
        gl[i] = head;
    }
}



int inDegree (GraphL g, int j, int n) {
    int i, k = 0;
    struct edge *aux;
    for (i = 0; i < n; i++){
        for (aux = g[i]; aux && aux -> dest < j; aux = aux->next);
        if (aux->dest == j) k++;
    }
    return k;
}



int outDegree (GraphL g, int j) {
    struct edge *aux;
    int k = 0;
    for(aux = g[j]; aux; aux = aux->next) k++;
    return k;
}


int capacidadeL (GraphL g, int v, int n) {
    int cap; struct edge *aux;
    int entra = 0,i,sai = 0;
    for (i = 0; i < n; i++){
        if (i == v){
            for (aux = g[i]; aux; aux = aux ->next){
                if (aux->dest != i) entra += aux->weight;
            }
        }
        else {
            for (aux = g[i]; aux; aux = aux->next){
                if (aux->dest == v) sai += aux->weight;
            }
        }
    }
    return (sai-entra);
}

int maxCap (GraphL g, int n) {
    int i, k = 0;
    struct edge *aux;
    int caps[n];
    for (i = 0; i < n; i++){
        caps[i] = 0;
    }
    for (i = 0; i < n; i++){
        for (aux = g[i]; aux; aux = aux->next){
            caps[i] -= aux->weight;
            caps[aux->dest] += aux->weight;
        }
    }
   for (i = 0; i < n; i++){
       if (caps[i] > caps[k]) k = i;
   }
   return k;
}


