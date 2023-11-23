#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>

typedef int itemf;

typedef struct fila {
    int max;
    int total;
    int inicio;
    int final;
    itemf *item;
}*Fila;

Fila fila(int max){
    Fila f = (Fila)malloc(sizeof(struct fila));
    f->max = max;
    f->total = 0;
    f->inicio = 0;
    f->final = 0;
    f->item = (itemf*)malloc(max*sizeof(itemf));
    return f;
}

int emptyf(Fila f){
    return f->total == 0;
}

int fullf(Fila f){
    return f->total == f->max;
}

void enfileira(itemf item, Fila f){
    if(fullf(f)){
        abort();
    }
    f->item[f->final] = item;
    f->final = (f->final + 1) % f->max;
    f->total++;
}

itemf desinfileira(Fila f){
    if(emptyf(f)){
        abort();
    }
    itemf item = f->item[f->inicio];
    f->inicio = (f->inicio + 1) % f->max;
    f->total--;
    return item;
}

void killf(Fila *f){
    free((*f)->item);
    free(*f);
    *f = NULL;
}
#endif