#ifndef NO_H
#define NO_H

#include <stdlib.h>

typedef int Item;

typedef struct no
{
    Item item;
    struct no *prox;
}*No;

No gerarNo(Item item) {

    No novo_no = (No)malloc(sizeof(struct no));
    novo_no->item = item;
    novo_no->prox = NULL;
}

No gerarNoP(Item item, No prox) {

    No novo_no = (No)malloc(sizeof(struct no));
    novo_no->item = item;
    novo_no->prox = prox;
}

int size(No no){

    if(no == NULL) return 0;
    return 1 + size(no->prox);
}

void kill(No no){

    if(no == NULL) return;
    kill(no->prox);
    free(no);
}



#endif