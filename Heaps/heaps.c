
#include <stdlib.h>

#include "minheap.h"

//
//void swap (Elem h[], int a, int b){
  //  int t = h[a];
    //h[a] = h[b];
    //h[b] = t;
//}


void initHeap (Heap *h, int size) {
    h->values = calloc(size, sizeof(Elem));
    h->size = size;
    h->used = 0;
}



void bubbleUp (Elem h[], int i) {
    while (i != 0 && h[i] < h[PARENT(i)]){
        swap(h,i,PARENT(i));
        i = PARENT(i);
    }
}



int  insertHeap (Heap *h, Elem x) {
    if (h->used == h->size){
        h->values = realloc(h->values, 2*(h->size)*sizeof(Elem));
    }
    h->values[h->used] = x;
    (h->used)++;
    bubbleUp (h->values, h->used-1);
    
    return 1;
}



void bubbleDown (Elem h[], int N) {
    int i = 0, min;
    if (LEFT(i) < N){
        min  = LEFT(i);
        if (RIGHT(i) < N && h[RIGHT(i)] < h[LEFT(i)]){
            min = RIGHT(i);
        }
        else if (h[min] < h[i]){
            swap(h, i, min);
            i = min;
        }
    }
}



int  extractMin (Heap *h, Elem *x) {
    if (h->used < 0){
        *x = h->values[0];
        h->values[0] = h->values[h->used -1];
        bubbleDown (h->values, h->used);
        h->used --;
    }
    else if (h->used < (h->size)/2){
        h->values = realloc (h->values, h->used *sizeof(Elem));
        h->size /= 2; 
        return 1;
    }
    return 0;
}



int minHeapOK (Heap h) {
    
 // ...
 
}
