
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


void initHT(HT *h, int size) {
    int i;
    h->size = size;
    h->used = 0;
    h->tbl = calloc (size, sizeof (struct pair));
    
    for (i = 0; i<size; i++){
        strcpy (h->tbl[i].key, EMPTY);
    }
}


int freeHT(HT *h, int k) {
    
    return freeHT_sol(h, k);
}



int writeHT (HT *h, char key[], int value) {

    return writeHT_sol (h, key, value);
}



int readHT (HT *h, char key[], int* value) {
    
    return readHT_sol (h, key, value);
}



int deleteHT (HT *h, char key[]) {

    return deleteHT_sol (h, key);
}

