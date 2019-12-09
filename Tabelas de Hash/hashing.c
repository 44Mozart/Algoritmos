
//
//  hashing.c
//  Hashing
//
//  Created by Jorge Sousa Pinto on 22/11/17.
//  Copyright © 2017 Jorge Sousa Pinto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "hashing.h"


int hash(char key[], int size) {
    int i;
    int sum;
    for (i=0; key[i]!=0; i++){
        sum += key[i];
    }
    return (sum % size);
}

// Como sei o que cada função faz?

void initHT(HT *h, int size) {
    int i;
    h->size = size;
    h->used = 0;
    h->tbl = calloc (size, sizeof (struct pair)); //O que é o calloc??
    
    for (i = 0; i<size; i++){
        strcpy (h->tbl[i].key, EMPTY);
    }
}


int freeHT(HT *h, int k) {
    // Ver se está livre, ou ocupado ou apagado
    if (h->tbl[k].key == EMPTY) return 1;
    if (h->tbl[k].key == DELETED) return 1;
    return 0;
}

void growHT (HT *h, int size) {
    int i, j;
    struct pair *aux = calloc(size, (sizeof(struct pair)));
    
    // Porquê o strcpy? Não podias por manualmente tipo:
    // for (i = 0; i < size; i++) aux->tbl[i].key == EMPTY
    for (i = 0; i < size; i++) strcpy (aux[i].key, EMPTY);

    for (i = 0; i < h->size; i++) {
        if (!freeHT(h,i)){
            j = hash(h->tbl[i].key, size);
            while (strcmp(aux[j].key,EMPTY) != 0) {
                // Enquanto não encontra um livre
                j = (j+1)%2;
            }
            strcpy(aux[j].key,h->tbl[i].key);
            aux[j].value = h->tbl[i].value;
        }
    }
    free(h->tbl);
    h->tbl = aux;
    h->size = size;
}


int writeHT (HT *h, char key[], int value) {
    //adicionar um elemento há tabela com valor value e chave key
    int i;
    if (h->used > 0.8*h->size) growHT(h,2 * h->size);
    i = hash(key,h->size);
    while (!freeHT(h,i)){
        i = (i+1)%(h->size);
    }
    h->used ++;
    h->tbl[i].value = value;
    strcpy(h->tbl[i].key,key);
    return i;
}

int readHT (HT *h, char key[], int* value) {
    int i;
    i = hash(key,h->size);
    while (!freeHT(h,i)){
        if (strcpy(h->tbl[i].key,key) == 0){
            *value = h->tbl[i].value;
            return i;
        }
        i = (i+1)%(h->size);
    }
    
    
    return -1;
}



int deleteHT (HT *h, char key[]) {
    int i = hash(key,h->size);
    
    while (!freeHT(h,i)) {
        if (strcmp(h->tbl[i].key, key) == 0){
            strcpy(h->tbl[i].key, DELETED);
            h->used --;
            return i;
        }
        i = (i+1)%(h->size);
    }
    return -1;
}




