#include "fila.h"
#include "pilha.h"

int main(){
    Fila F = fila(5);
    enfileira(1,F);
    enfileira(2,F);
    enfileira(3,F);
    enfileira(desinfileira(F),F);
    enfileira(desinfileira(F),F);
    printf("%d\n",desinfileira(F));
    killf(&F);
}

/*
O output será a fila com a ordem 3,2,1.
*/