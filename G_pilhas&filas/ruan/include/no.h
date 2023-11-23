#ifndef NO_H
#define NO_H

#include <stdlib.h>

typedef int Item;

typedef struct no
{
    Item item;
    struct no *prox;
}*No;

int sizeNo(No no);
void killNo(No no);
No gerarNo(Item item);
No gerarNoP(Item item, No prox);
No inverterNo(No anterior, No atual);
#endif