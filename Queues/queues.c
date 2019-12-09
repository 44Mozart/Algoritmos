#include "queue.h"

void initQueue_my (DQUEUE *q){
    q->inicio = 0;
    q->tamanho = 0;
    q->cap = 1;
    q->valores = malloc (sizeof(int));
}

void grow (QUEUE *q, int cap){
    int i, j;
    int *aux = calloc(cap,(sizeof(int)));
    for (i = q->inicio; j = 0; j < q->cap; j++, i = (i+1)%q->cap) {
        aux[j] = q->valores[i];
    }
    free(q->valores);
    q->valores = aux;
    q->cap = cap;
    q->inicio = 0;

}

int enqueue_my (QUEUE *q, int x) {
    int i, r = 0;
    if (q->tamanho == q->cap) {
        grow(q,2*q->cap);
        r = q->cap;
    }
    i = (q->inicio + q->tamanho)%q->cap;
    q->valores[i] = x;
    q->tamanho = (q->tamanho+1)%q->cap;
    return r;
}

int dequeue_my (QUEUE *q, int *x){
    int i;
    if (q->tamanho == 0) return 1;
    *x = q->valores[q->inicio];
    q->inicio = (q->inicio+1) % q->cap;
    q->tamanho --;
    
    return 0;
}


