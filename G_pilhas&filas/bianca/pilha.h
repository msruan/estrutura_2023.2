#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#include <stdlib.h>

typedef int itemp;

typedef struct pilha {
    int max;
    int topo;
    itemp *item;
}*Pilha;

Pilha pilha (int max){
    Pilha p = (Pilha)malloc(sizeof(struct pilha));
    p->max = max;
    p->topo = -1;
    p->item = (itemp*)malloc(max*sizeof(itemp));
    return p;
}

int emptyp(Pilha p){
    return p->topo == -1;
}

int fullp(Pilha p){
    return p->topo == p->max-1;
}

void empilha(itemp item, Pilha p){
    if(fullp(p)){
        abort();
    }
    p->topo++;
    p->item[p->topo] = item;
}

itemp desempilha(Pilha p){
    if(emptyp(p)){
        abort();
    }
    itemp item = p->item[p->topo];
    p->topo--;
    return item;
}

itemp getTopo(Pilha p){
    if(emptyp(p)){
        abort();
    }
    return p->item[p->topo];
}

void killp(Pilha p){
    free((p)->item);
    free(p);
    p = NULL;
} 
#endif